#ifndef AWL_BACKENDS_POSIX_PROCESSOR_HPP_INCLUDED
#define AWL_BACKENDS_POSIX_PROCESSOR_HPP_INCLUDED

#include <awl/class_symbol.hpp>
#include <awl/backends/posix/callback.hpp>
#include <awl/backends/posix/fd.hpp>
#include <awl/backends/posix/optional_duration_fwd.hpp>
#include <awl/backends/posix/processor_fwd.hpp>
#include <awl/detail/symbol.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/signal/auto_connection_fwd.hpp>


namespace awl
{
namespace backends
{
namespace posix
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
	fcppt::signal::auto_connection
	register_fd_callback(
		awl::backends::posix::fd const &,
		awl::backends::posix::callback const &
	) = 0;

	virtual
	bool
	poll(
		awl::backends::posix::optional_duration const &
	) = 0;

	AWL_DETAIL_SYMBOL
	virtual
	~processor() = 0;
};

}
}
}

#endif
