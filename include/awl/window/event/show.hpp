#ifndef AWL_WINDOW_EVENT_SHOW_HPP_INCLUDED
#define AWL_WINDOW_EVENT_SHOW_HPP_INCLUDED

#include <awl/detail/class_symbol.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/window/reference.hpp>
#include <awl/window/event/base.hpp>
#include <awl/window/event/show_fwd.hpp>
#include <fcppt/nonmovable.hpp>


namespace awl
{
namespace window
{
namespace event
{

class AWL_DETAIL_CLASS_SYMBOL show
:
	public awl::window::event::base
{
	FCPPT_NONMOVABLE(
		show
	);
public:
	AWL_DETAIL_SYMBOL
	explicit
	show(
		awl::window::reference
	);

	AWL_DETAIL_SYMBOL
	~show()
	override;
};

}
}
}

#endif
