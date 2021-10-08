#include <awl/backends/wayland/display_reference.hpp>
#include <awl/backends/wayland/system/seat/caps_field.hpp>
#include <awl/backends/wayland/system/seat/data.hpp>
#include <awl/event/container_reference.hpp>

awl::backends::wayland::system::seat::data::data(
    awl::backends::wayland::display_reference const _display,
    awl::event::container_reference const _events)
    : display_{_display},
      caps_{awl::backends::wayland::system::seat::caps_field::null()},
      events_{_events},
      pointer_{}
{
}

awl::backends::wayland::system::seat::data::~data() = default;
