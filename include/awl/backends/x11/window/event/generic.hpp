#ifndef AWL_BACKENDS_X11_WINDOW_EVENT_GENERIC_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_EVENT_GENERIC_HPP_INCLUDED

#include <awl/backends/x11/Xlib.hpp>
#include <awl/backends/x11/window/object_fwd.hpp>
#include <awl/backends/x11/window/object_ref.hpp>
#include <awl/backends/x11/window/event/generic_fwd.hpp>
#include <awl/backends/x11/window/event/object.hpp>
#include <awl/detail/class_symbol.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/window/event/base.hpp>
#include <fcppt/nonmovable.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace window
{
namespace event
{

class AWL_DETAIL_CLASS_SYMBOL generic
:
	public awl::window::event::base
{
	FCPPT_NONMOVABLE(
		generic
	);
public:
	AWL_DETAIL_SYMBOL
	generic(
		awl::backends::x11::window::object_ref,
		awl::backends::x11::window::event::object const &
	);

	AWL_DETAIL_SYMBOL
	~generic()
	override;

	[[nodiscard]]
	AWL_DETAIL_SYMBOL
	awl::backends::x11::window::object &
	window() const;

	[[nodiscard]]
	AWL_DETAIL_SYMBOL
	awl::backends::x11::window::event::object const &
	event() const;
private:
	awl::backends::x11::window::object_ref const window_;

	awl::backends::x11::window::event::object const event_;
};

}
}
}
}
}

#endif
