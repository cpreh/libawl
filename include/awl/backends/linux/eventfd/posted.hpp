#ifndef AWL_BACKENDS_LINUX_EVENTFD_POSTED_HPP_INCLUDED
#define AWL_BACKENDS_LINUX_EVENTFD_POSTED_HPP_INCLUDED

#include <awl/class_symbol.hpp>
#include <awl/backends/posix/callback.hpp>
#include <awl/backends/posix/posted.hpp>
#include <awl/backends/posix/processor_fwd.hpp>
#include <awl/backends/linux/eventfd/object.hpp>
#include <awl/detail/symbol.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/signal/auto_connection.hpp>


namespace awl
{
namespace backends
{
namespace linux
{
namespace eventfd
{

class posted
:
	public awl::backends::posix::posted
{
	FCPPT_NONCOPYABLE(
		posted
	);
public:
	AWL_DETAIL_SYMBOL
	posted(
		awl::backends::posix::processor &,
		awl::backends::posix::callback const &
	);

	AWL_DETAIL_SYMBOL
	~posted()
	override;
private:
	awl::backends::linux::eventfd::object fd_;

	fcppt::signal::auto_connection const fd_connection_;
};

}
}
}
}

#endif
