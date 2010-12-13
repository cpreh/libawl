#ifndef AWL_SYSTEM_EVENT_PROCESSOR_HPP_INCLUDED
#define AWL_SYSTEM_EVENT_PROCESSOR_HPP_INCLUDED

#include <awl/system/event/processor_fwd.hpp>
#include <awl/class_symbol.hpp>
#include <awl/symbol.hpp>
#include <fcppt/noncopyable.hpp>

namespace awl
{
namespace system
{
namespace event
{

class AWL_CLASS_SYMBOL processor
{
	FCPPT_NONCOPYABLE(
		processor
	)
protected:
	AWL_SYMBOL
	processor();
public:
	virtual bool
	dispatch() = 0;

	AWL_SYMBOL
	virtual ~processor();
};

}
}
}

#endif