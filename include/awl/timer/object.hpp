#ifndef AWL_TIMER_OBJECT_HPP_INCLUDED
#define AWL_TIMER_OBJECT_HPP_INCLUDED

#include <awl/detail/class_symbol.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/timer/object_fwd.hpp>
#include <awl/timer/setting_fwd.hpp>
#include <fcppt/noncopyable.hpp>


namespace awl
{
namespace timer
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
	~object();

	virtual
	void
	set(
		awl::timer::setting const &
	) = 0;
};

}
}

#endif
