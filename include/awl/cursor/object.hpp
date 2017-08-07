#ifndef AWL_CURSOR_OBJECT_HPP_INCLUDED
#define AWL_CURSOR_OBJECT_HPP_INCLUDED

#include <awl/detail/class_symbol.hpp>
#include <awl/detail/symbol.hpp>
#include <fcppt/noncopyable.hpp>


namespace awl
{
namespace cursor
{

class AWL_DETAIL_CLASS_SYMBOL object
{
	FCPPT_NONCOPYABLE(
		object
	);
protected:
	AWL_DETAIL_SYMBOL
	object();
public:
	AWL_DETAIL_SYMBOL
	virtual
	~object() = 0;
};

}
}

#endif
