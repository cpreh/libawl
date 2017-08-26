#ifndef AWL_BACKENDS_POSIX_PROCESSOR_HPP_INCLUDED
#define AWL_BACKENDS_POSIX_PROCESSOR_HPP_INCLUDED

#include <awl/detail/class_symbol.hpp>
#include <awl/event/connection_unique_ptr.hpp>
#include <awl/backends/posix/event_container.hpp>
#include <awl/backends/posix/fd.hpp>
#include <awl/backends/posix/optional_duration_fwd.hpp>
#include <awl/backends/posix/processor_fwd.hpp>
#include <awl/detail/symbol.hpp>
#include <fcppt/noncopyable.hpp>


namespace awl
{
namespace backends
{
namespace posix
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
	awl::event::connection_unique_ptr
	register_fd(
		awl::backends::posix::fd const &
	) = 0;

	virtual
	awl::backends::posix::event_container
	poll(
		awl::backends::posix::optional_duration const &
	) = 0;

	virtual
	fcppt::signal::auto_connection
	event_function(
		awl::backends::posix::event_function,
		awl::backends::posix::fd
	) = 0;

	AWL_DETAIL_SYMBOL
	virtual
	~processor() = 0;
};

}
}
}

#endif
