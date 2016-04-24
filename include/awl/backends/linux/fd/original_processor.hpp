#ifndef AWL_BACKENDS_LINUX_FD_ORIGINAL_PROCESSOR_HPP_INCLUDED
#define AWL_BACKENDS_LINUX_FD_ORIGINAL_PROCESSOR_HPP_INCLUDED

#include <awl/class_symbol.hpp>
#include <awl/backends/linux/fd/callback.hpp>
#include <awl/backends/linux/fd/function.hpp>
#include <awl/backends/linux/fd/object.hpp>
#include <awl/backends/linux/fd/optional_duration_fwd.hpp>
#include <awl/backends/linux/fd/processor.hpp>
#include <awl/backends/linux/fd/epoll/set.hpp>
#include <awl/detail/symbol.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/signal/auto_connection_fwd.hpp>
#include <fcppt/signal/object_decl.hpp>
#include <fcppt/signal/unregister/base_decl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <map>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace backends
{
namespace linux
{
namespace fd
{

class AWL_CLASS_SYMBOL original_processor
:
	public awl::backends::linux::fd::processor
{
	FCPPT_NONCOPYABLE(
		original_processor
	);
public:
	AWL_DETAIL_SYMBOL
	original_processor();

	AWL_DETAIL_SYMBOL
	~original_processor()
	override;

	AWL_DETAIL_SYMBOL
	fcppt::signal::auto_connection
	register_fd_callback(
		awl::backends::linux::fd::object const &,
		awl::backends::linux::fd::callback const &
	)
	override;

	AWL_DETAIL_SYMBOL
	bool
	epoll(
		awl::backends::linux::fd::optional_duration const &
	)
	override;
private:
	void
	unregister_fd_signal(
		awl::backends::linux::fd::object const &
	);

	awl::backends::linux::fd::epoll::set fd_set_;

	typedef
	fcppt::signal::object<
		awl::backends::linux::fd::function,
		fcppt::signal::unregister::base
	>
	fd_signal;

	typedef
	std::map<
		awl::backends::linux::fd::object,
		fd_signal
	>
	fd_signal_map;

	fd_signal_map fd_signals_;
};

}
}
}
}

#endif
