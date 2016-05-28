#ifndef AWL_BACKENDS_POSIX_TIMER_HPP_INCLUDED
#define AWL_BACKENDS_POSIX_TIMER_HPP_INCLUDED

#include <awl/class_symbol.hpp>
#include <awl/backends/posix/timer_fwd.hpp>
#include <awl/detail/symbol.hpp>
#include <fcppt/noncopyable.hpp>


namespace awl
{
namespace backends
{
namespace posix
{

class AWL_CLASS_SYMBOL timer
{
	FCPPT_NONCOPYABLE(
		timer
	);
protected:
	AWL_DETAIL_SYMBOL
	timer();
public:
	AWL_DETAIL_SYMBOL
	virtual
	~timer() = 0;
};

}
}
}

#endif
