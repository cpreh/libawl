#ifndef AWL_BACKENDS_LINUX_FD_PROCESSOR_HPP_INCLUDED
#define AWL_BACKENDS_LINUX_FD_PROCESSOR_HPP_INCLUDED

#include <awl/class_symbol.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/backends/linux/fd/callback.hpp>
#include <awl/backends/linux/fd/object.hpp>
#include <awl/backends/linux/fd/optional_duration_fwd.hpp>
#include <awl/backends/linux/fd/processor_fwd.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/signal/auto_connection_fwd.hpp>


namespace awl
{
namespace backends
{
namespace linux
{
namespace fd
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
		awl::backends::linux::fd::object const &,
		awl::backends::linux::fd::callback const &
	) = 0;

	virtual
	bool
	epoll(
		awl::backends::linux::fd::optional_duration const &
	) = 0;

	AWL_DETAIL_SYMBOL
	virtual
	~processor() = 0;
};

}
}
}
}

#endif
