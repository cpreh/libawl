#include <awl/window/reference.hpp>
#include <awl/window/event/base.hpp>
#include <awl/window/event/close.hpp>

awl::window::event::close::close(awl::window::reference const _window)
    : awl::window::event::base{_window}
{
}

awl::window::event::close::~close() = default;
