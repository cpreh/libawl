#ifndef AWL_WINDOW_EVENT_RESIZE_HPP_INCLUDED
#define AWL_WINDOW_EVENT_RESIZE_HPP_INCLUDED

#include <awl/detail/class_symbol.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/window/dim.hpp>
#include <awl/window/reference.hpp>
#include <awl/window/event/base.hpp>
#include <awl/window/event/resize_fwd.hpp>
#include <fcppt/noncopyable.hpp>


namespace awl
{
namespace window
{
namespace event
{

class AWL_DETAIL_CLASS_SYMBOL resize
:
	public awl::window::event::base
{
	FCPPT_NONCOPYABLE(
		resize
	);
public:
	AWL_DETAIL_SYMBOL
	resize(
		awl::window::reference,
		awl::window::dim const &
	);

	AWL_DETAIL_SYMBOL
	~resize()
	override;

	AWL_DETAIL_SYMBOL
	awl::window::dim const &
	dim() const;
private:
	awl::window::dim dim_;
};

}
}
}

#endif
