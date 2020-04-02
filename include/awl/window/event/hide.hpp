#ifndef AWL_WINDOW_EVENT_HIDE_HPP_INCLUDED
#define AWL_WINDOW_EVENT_HIDE_HPP_INCLUDED

#include <awl/detail/class_symbol.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/window/reference.hpp>
#include <awl/window/event/base.hpp>
#include <awl/window/event/hide_fwd.hpp>
#include <fcppt/nonmovable.hpp>


namespace awl
{
namespace window
{
namespace event
{

class AWL_DETAIL_CLASS_SYMBOL hide
:
	public awl::window::event::base
{
	FCPPT_NONMOVABLE(
		hide
	);
public:
	AWL_DETAIL_SYMBOL
	explicit
	hide(
		awl::window::reference
	);

	AWL_DETAIL_SYMBOL
	~hide()
	override;
};

}
}
}

#endif
