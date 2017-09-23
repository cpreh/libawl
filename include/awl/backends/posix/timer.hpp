#ifndef AWL_BACKENDS_POSIX_TIMER_HPP_INCLUDED
#define AWL_BACKENDS_POSIX_TIMER_HPP_INCLUDED

#include <awl/backends/posix/fd.hpp>
#include <awl/backends/posix/timer_fwd.hpp>
#include <awl/detail/class_symbol.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/timer/object.hpp>
#include <fcppt/noncopyable.hpp>


namespace awl
{
namespace backends
{
namespace posix
{

class AWL_DETAIL_CLASS_SYMBOL timer
:
	public awl::timer::object
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

	virtual
	awl::backends::posix::fd
	fd() const = 0;
};

}
}
}

#endif
