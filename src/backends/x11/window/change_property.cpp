#include <awl/backends/x11/display.hpp> // NOLINT(misc-include-cleaner)
#include <awl/backends/x11/window/base.hpp>
#include <awl/backends/x11/window/basic_property_data.hpp>
#include <awl/backends/x11/window/change_property.hpp>
#include <awl/backends/x11/window/property.hpp>
#include <awl/backends/x11/window/property_data.hpp>
#include <awl/backends/x11/window/property_mode.hpp>
#include <awl/backends/x11/window/property_type.hpp>
#include <fcppt/cast/size.hpp>
#include <fcppt/cast/to_char_ptr.hpp>
#include <fcppt/cast/to_signed.hpp>
#include <fcppt/enum/make_invalid.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/range/size.hpp>
#include <fcppt/variant/apply.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/X.h>
#include <X11/Xlib.h>
#include <fcppt/config/external_end.hpp>

namespace
{

int convert_mode(awl::backends::x11::window::property_mode const _type)
{
  FCPPT_PP_PUSH_WARNING
  FCPPT_PP_DISABLE_GCC_WARNING(-Wswitch-default)
  switch (_type)
  {
  case awl::backends::x11::window::property_mode::replace:
    return PropModeReplace;
  case awl::backends::x11::window::property_mode::prepend:
    return PropModePrepend;
  case awl::backends::x11::window::property_mode::append:
    return PropModeAppend;
  }
  FCPPT_PP_POP_WARNING

  throw fcppt::enum_::make_invalid(_type);
}

template <typename Type>
struct convert_format_impl;

template <>
struct convert_format_impl<char>
{
  static constexpr const int value{8};
};

template <>
struct convert_format_impl<short // NOLINT(google-runtime-int)
                           >
{
  static constexpr const int value{16};
};

template <>
struct convert_format_impl<long // NOLINT(google-runtime-int)
                           >
{
  static constexpr const int value{32};
};

template <typename Type>
constexpr int convert_format()
{
  return convert_format_impl<Type>::value;
}

template <typename Type>
void change_property_impl(
    awl::backends::x11::window::base const &_window,
    awl::backends::x11::window::property const
        _name, // NOLINT(readability-avoid-const-params-in-decls)
    awl::backends::x11::window::property_type const
        _type, // NOLINT(readability-avoid-const-params-in-decls)
    awl::backends::x11::window::property_mode const
        _mode, // NOLINT(readability-avoid-const-params-in-decls)
    awl::backends::x11::window::basic_property_data<Type> const
        _data // NOLINT(readability-avoid-const-params-in-decls)
)
{
  // Always returns 1
  XChangeProperty(
      _window.display().get().get(),
      _window.get(),
      _name.get().get(),
      _type.get().get(),
      convert_format<Type>(),
      convert_mode(_mode),
      fcppt::cast::to_char_ptr<unsigned char const *>(_data.begin()),
      fcppt::cast::size<int>(fcppt::cast::to_signed(fcppt::range::size(_data))));
}

}

void awl::backends::x11::window::change_property(
    awl::backends::x11::window::base const &_window,
    awl::backends::x11::window::property const _name,
    awl::backends::x11::window::property_type const _type,
    awl::backends::x11::window::property_mode const _mode,
    awl::backends::x11::window::property_data const &_data_variant)
{
  fcppt::variant::apply(
      [&_window, _name, _type, _mode](auto const &_data)
      { change_property_impl(_window, _name, _type, _mode, _data); },
      _data_variant);
}
