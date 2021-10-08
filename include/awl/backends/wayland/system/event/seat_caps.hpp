#ifndef AWL_BACKENDS_WAYLAND_SYSTEM_EVENT_SEAT_CAPS_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_SYSTEM_EVENT_SEAT_CAPS_HPP_INCLUDED

#include <awl/backends/wayland/display_reference.hpp>
#include <awl/backends/wayland/system/event/seat_base.hpp>
#include <awl/backends/wayland/system/event/seat_caps_fwd.hpp>
#include <awl/backends/wayland/system/seat/caps_field.hpp>
#include <awl/backends/wayland/system/seat/shared_ptr.hpp>
#include <awl/detail/class_symbol.hpp>
#include <awl/detail/symbol.hpp>
#include <fcppt/nonmovable.hpp>

namespace awl::backends::wayland::system::event
{

class AWL_DETAIL_CLASS_SYMBOL seat_caps : public awl::backends::wayland::system::event::seat_base
{
  FCPPT_NONMOVABLE(seat_caps);

public:
  AWL_DETAIL_SYMBOL
  seat_caps(
      awl::backends::wayland::display_reference,
      awl::backends::wayland::system::seat::shared_ptr,
      awl::backends::wayland::system::seat::caps_field);

  AWL_DETAIL_SYMBOL
  ~seat_caps() override;

  [[nodiscard]] AWL_DETAIL_SYMBOL awl::backends::wayland::system::seat::caps_field caps() const;

private:
  awl::backends::wayland::system::seat::caps_field const caps_;
};

}

#endif
