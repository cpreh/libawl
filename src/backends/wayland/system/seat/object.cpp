#include <awl/exception.hpp>
#include <awl/backends/wayland/display_reference.hpp>
#include <awl/backends/wayland/registry_id.hpp>
#include <awl/backends/wayland/seat.hpp>
#include <awl/backends/wayland/system/event/seat_caps.hpp>
#include <awl/backends/wayland/system/seat/caps_field.hpp>
#include <awl/backends/wayland/system/seat/data.hpp>
#include <awl/backends/wayland/system/seat/object.hpp>
#include <awl/event/base.hpp>
#include <awl/event/container_reference.hpp>
#include <fcppt/enable_shared_from_this_impl.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/text.hpp>
#include <fcppt/unique_ptr_to_base.hpp>
#include <fcppt/bit/mask_c.hpp>
#include <fcppt/bit/test.hpp>
#include <fcppt/cast/from_void_ptr.hpp>
#include <fcppt/container/bitfield/operators.hpp>
#include <fcppt/optional/make.hpp>
#include <fcppt/optional/to_exception.hpp>
#include <fcppt/config/external_begin.hpp>
#include <wayland-client-protocol.h>
#include <cstdint>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace
{

awl::backends::wayland::system::seat::caps_field convert_caps(std::uint32_t const _caps)
{
  awl::backends::wayland::system::seat::caps_field result{
      awl::backends::wayland::system::seat::caps_field::null()};

  if (fcppt::bit::test(_caps, fcppt::bit::mask_c<std::uint32_t, WL_SEAT_CAPABILITY_POINTER>()))
  {
    result |= awl::backends::wayland::system::seat::caps::pointer;
  }

  if (fcppt::bit::test(_caps, fcppt::bit::mask_c<std::uint32_t, WL_SEAT_CAPABILITY_KEYBOARD>()))
  {
    result |= awl::backends::wayland::system::seat::caps::keyboard;
  }

  return result;
}

void wl_seat_capabilities(void *const _data, wl_seat *, std::uint32_t const _capabilities)
{
  awl::backends::wayland::system::seat::data &data(
      *fcppt::cast::from_void_ptr<awl::backends::wayland::system::seat::data *>(_data));

  data.caps_ = convert_caps(_capabilities);

  data.events_.get().push_back(fcppt::unique_ptr_to_base<awl::event::base>(
      fcppt::make_unique_ptr<awl::backends::wayland::system::event::seat_caps>(
          data.display_,
          fcppt::optional::to_exception(
              data.pointer_, [] { return awl::exception{FCPPT_TEXT("WL seat pointer not set.")}; }),
          data.caps_)));
}

void wl_seat_name(void *, wl_seat *, char const *) {}

wl_seat_listener const seat_listener{&wl_seat_capabilities, &wl_seat_name};

}

awl::backends::wayland::system::seat::object::object(
    awl::backends::wayland::seat &&_impl,
    awl::backends::wayland::display_reference const _display,
    awl::event::container_reference const _events)
    : fcppt::enable_shared_from_this<awl::backends::wayland::system::seat::object>{},
      impl_{std::move(_impl)},
      data_{_display, _events}
{
  ::wl_seat_add_listener(impl_.get(), &seat_listener, &data_);
}

awl::backends::wayland::system::seat::object::~object() = default;

void awl::backends::wayland::system::seat::object::init_ptr()
{
  // TODO(philipp): Make this less ugly
  data_.pointer_ = fcppt::optional::make(this->fcppt_shared_from_this());
}

awl::backends::wayland::registry_id awl::backends::wayland::system::seat::object::name() const
{
  return impl_.name();
}

awl::backends::wayland::seat &awl::backends::wayland::system::seat::object::get() { return impl_; }

awl::backends::wayland::seat const &awl::backends::wayland::system::seat::object::get() const
{
  return impl_;
}

awl::backends::wayland::system::seat::caps_field
awl::backends::wayland::system::seat::object::caps() const
{
  return data_.caps_;
}
