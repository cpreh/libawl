#ifndef AWL_WINDOW_OBJECT_HPP_INCLUDED
#define AWL_WINDOW_OBJECT_HPP_INCLUDED

#include <awl/class_symbol.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/visual/object_fwd.hpp>
#include <awl/window/dim_fwd.hpp>
#include <awl/window/rect_fwd.hpp>
#include <fcppt/noncopyable.hpp>


namespace awl
{
namespace window
{

class AWL_CLASS_SYMBOL object
{
	FCPPT_NONCOPYABLE(
		object
	);
protected:
	AWL_DETAIL_SYMBOL
	object();
public:
	virtual
	void
	show() = 0;

	AWL_DETAIL_SYMBOL
	awl::window::dim
	size() const;

	virtual
	awl::window::rect
	rect() const = 0;

	virtual
	awl::visual::object const &
	visual() const = 0;

	AWL_DETAIL_SYMBOL
	virtual
	~object() = 0;
};

}
}

#endif
