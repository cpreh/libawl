#include <awl/log_location.hpp>
#include <awl/backends/wayland/display.hpp>
#include <awl/backends/wayland/display_roundtrip.hpp>
#include <awl/backends/wayland/cursor/convert_name.hpp>
#include <awl/backends/wayland/cursor/create_invisible.hpp>
#include <awl/backends/wayland/cursor/create_name.hpp>
#include <awl/backends/wayland/cursor/object.hpp> // NOLINT(misc-include-cleaner)
#include <awl/backends/wayland/system/object.hpp>
#include <awl/backends/wayland/system/original_object.hpp>
#include <awl/backends/wayland/system/event/original_processor.hpp>
#include <awl/backends/wayland/system/event/processor.hpp>
#include <awl/backends/wayland/visual/null_object.hpp>
#include <awl/backends/wayland/window/original_object.hpp>
#include <awl/cursor/object.hpp>
#include <awl/cursor/object_unique_ptr.hpp>
#include <awl/cursor/optional_type.hpp>
#include <awl/cursor/type.hpp>
#include <awl/impl/backends/wayland/log_name.hpp>
#include <awl/system/event/processor.hpp>
#include <awl/visual/object.hpp>
#include <awl/visual/object_unique_ptr.hpp>
#include <awl/window/object.hpp>
#include <awl/window/object_unique_ptr.hpp>
#include <awl/window/parameters_fwd.hpp>
#include <fcppt/make_ref.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/reference_to_base.hpp>
#include <fcppt/unique_ptr_to_base.hpp>
#include <fcppt/log/context_reference.hpp>
#include <fcppt/optional/maybe.hpp>

awl::backends::wayland::system::original_object::original_object(
    fcppt::log::context_reference const _log_context)
    : awl::backends::wayland::system::object(),
      log_{_log_context, awl::log_location(), awl::impl::backends::wayland::log_name()},
      display_{},
      processor_{fcppt::unique_ptr_to_base<awl::backends::wayland::system::event::processor>(
          fcppt::make_unique_ptr<awl::backends::wayland::system::event::original_processor>(
              fcppt::make_ref(log_),
              fcppt::reference_to_base<awl::backends::wayland::display>(
                  fcppt::make_ref(display_))))},
      cursor_theme_{processor_->shm()}
{
}

awl::backends::wayland::system::original_object::~original_object() = default;

awl::window::object_unique_ptr awl::backends::wayland::system::original_object::create_window(
    awl::window::parameters const &_parameters)
{
  awl::window::object_unique_ptr result{fcppt::unique_ptr_to_base<awl::window::object>(
      fcppt::make_unique_ptr<awl::backends::wayland::window::original_object>(
          fcppt::make_ref(log_),
          processor_->events(),
          display_,
          processor_->compositor(),
          processor_->shell(),
          _parameters))};

  // TODO(philipp): Do we need this?
  awl::backends::wayland::display_roundtrip(display_);

  return result;
}

awl::system::event::processor &awl::backends::wayland::system::original_object::processor()
{
  return *processor_;
}

awl::visual::object_unique_ptr awl::backends::wayland::system::original_object::default_visual()
{
  return fcppt::unique_ptr_to_base<awl::visual::object>(
      fcppt::make_unique_ptr<awl::backends::wayland::visual::null_object>());
}

awl::cursor::object_unique_ptr awl::backends::wayland::system::original_object::create_cursor(
    awl::cursor::optional_type const &_optional_type)
{
  return fcppt::unique_ptr_to_base<awl::cursor::object>(fcppt::optional::maybe(
      _optional_type,
      [] { return awl::backends::wayland::cursor::create_invisible(); },
      [this](awl::cursor::type const _type)
      {
        return awl::backends::wayland::cursor::create_name(
            this->cursor_theme_, awl::backends::wayland::cursor::convert_name(_type));
      }));
}

awl::backends::wayland::display &awl::backends::wayland::system::original_object::display()
{
  return display_;
}
