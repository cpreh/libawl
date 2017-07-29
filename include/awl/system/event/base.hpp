#ifndef AWL_SYSTEM_EVENT_BASE_HPP_INCLUDED
#define AWL_SYSTEM_EVENT_BASE_HPP_INCLUDED

#include <awl/class_symbol.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/system/event/base_fwd.hpp>
#include <fcppt/noncopyable.hpp>


namespace awl
{
namespace system
{
namespace event
{

class AWL_CLASS_SYMBOL base
{
	FCPPT_NONCOPYABLE(
		base
	);
protected:
	AWL_DETAIL_SYMBOL
	base();
public:
	AWL_DETAIL_SYMBOL
	virtual
	~base() = 0;
};

}
}
}

#endif
