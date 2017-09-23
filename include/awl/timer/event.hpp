#ifndef AWL_TIMER_EVENT_HPP_INCLUDED
#define AWL_TIMER_EVENT_HPP_INCLUDED

#include <awl/detail/class_symbol.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/event/base.hpp>
#include <awl/timer/event_fwd.hpp>
#include <awl/timer/object_fwd.hpp>
#include <awl/timer/reference.hpp>
#include <fcppt/noncopyable.hpp>


namespace awl
{
namespace timer
{

class AWL_DETAIL_CLASS_SYMBOL event
:
	public awl::event::base
{
	FCPPT_NONCOPYABLE(
		event
	);
public:
	AWL_DETAIL_SYMBOL
	explicit
	event(
		awl::timer::reference
	);

	AWL_DETAIL_SYMBOL
	~event()
	override;

	AWL_DETAIL_SYMBOL
	awl::timer::object &
	get() const;
private:
	awl::timer::reference const timer_;
};

}
}

#endif
