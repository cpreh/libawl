#ifndef AWL_SYSTEM_EVENT_PROCESSOR_HPP_INCLUDED
#define AWL_SYSTEM_EVENT_PROCESSOR_HPP_INCLUDED

#include <awl/detail/class_symbol.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/main/exit_code_fwd.hpp>
#include <awl/system/event/processor_fwd.hpp>
#include <awl/system/event/result_fwd.hpp>
#include <awl/timer/setting_fwd.hpp>
#include <awl/timer/unique_ptr.hpp>
#include <fcppt/noncopyable.hpp>


namespace awl
{
namespace system
{
namespace event
{

class AWL_DETAIL_CLASS_SYMBOL processor
{
	FCPPT_NONCOPYABLE(
		processor
	);
protected:
	AWL_DETAIL_SYMBOL
	processor();
public:
	virtual
	awl::system::event::result
	poll() = 0;

	virtual
	awl::system::event::result
	next() = 0;

	virtual
	void
	quit(
		awl::main::exit_code
	) = 0;

	virtual
	awl::timer::unique_ptr
	create_timer(
		awl::timer::setting const &
	) = 0;

	AWL_DETAIL_SYMBOL
	virtual
	~processor() = 0;
};

}
}
}

#endif
