#ifndef AWL_EVENT_PROCESSOR_HPP_INCLUDED
#define AWL_EVENT_PROCESSOR_HPP_INCLUDED

#include <awl/class_symbol.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/event/processor_fwd.hpp>
#include <awl/window/event/processor_fwd.hpp>
#include <fcppt/noncopyable.hpp>


namespace awl
{
namespace event
{

class AWL_CLASS_SYMBOL processor
{
	FCPPT_NONCOPYABLE(
		processor
	);
protected:
	AWL_DETAIL_SYMBOL
	processor();
public:
	virtual
	bool
	poll() = 0;

	virtual
	void
	next() = 0;

	virtual
	void
	attach(
		awl::window::event::processor &
	) = 0;

	virtual
	void
	detach(
		awl::window::event::processor &
	) = 0;

	AWL_DETAIL_SYMBOL
	virtual
	~processor() = 0;
};

}
}

#endif
