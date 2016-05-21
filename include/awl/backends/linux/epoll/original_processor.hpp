#ifndef AWL_BACKENDS_LINUX_EPOLL_ORIGINAL_PROCESSOR_HPP_INCLUDED
#define AWL_BACKENDS_LINUX_EPOLL_ORIGINAL_PROCESSOR_HPP_INCLUDED

#include <awl/class_symbol.hpp>
#include <awl/backends/posix/callback.hpp>
#include <awl/backends/posix/function.hpp>
#include <awl/backends/posix/fd.hpp>
#include <awl/backends/posix/optional_duration_fwd.hpp>
#include <awl/backends/posix/processor.hpp>
#include <awl/backends/linux/epoll/set.hpp>
#include <awl/detail/symbol.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/signal/auto_connection_fwd.hpp>
#include <fcppt/signal/object_decl.hpp>
#include <fcppt/signal/unregister/base_decl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <unordered_map>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace backends
{
namespace linux
{
namespace epoll
{

class AWL_CLASS_SYMBOL original_processor
:
	public awl::backends::posix::processor
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
		awl::backends::posix::fd const &,
		awl::backends::posix::callback const &
	)
	override;

	AWL_DETAIL_SYMBOL
	bool
	poll(
		awl::backends::posix::optional_duration const &
	)
	override;
private:
	void
	unregister_fd_signal(
		awl::backends::posix::fd const &
	);

	awl::backends::linux::epoll::set fd_set_;

	typedef
	fcppt::signal::object<
		awl::backends::posix::function,
		fcppt::signal::unregister::base
	>
	fd_signal;

	typedef
	std::unordered_map<
		awl::backends::posix::fd,
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
