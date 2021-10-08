#include <awl/window/reference.hpp>
#include <awl/window/event/base.hpp>
#include <awl/window/event/hide.hpp>

awl::window::event::hide::hide(awl::window::reference const _window)
    : awl::window::event::base{_window}
{
}

awl::window::event::hide::~hide() = default;
