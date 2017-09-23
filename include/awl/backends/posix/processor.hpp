#ifndef AWL_BACKENDS_POSIX_PROCESSOR_HPP_INCLUDED
#define AWL_BACKENDS_POSIX_PROCESSOR_HPP_INCLUDED

#include <awl/detail/class_symbol.hpp>
#include <awl/event/connection_unique_ptr.hpp>
#include <awl/backends/posix/fd.hpp>
#include <awl/backends/posix/optional_duration_fwd.hpp>
#include <awl/backends/posix/processor_fwd.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/event/container.hpp>
#include <awl/timer/setting_fwd.hpp>
#include <awl/timer/unique_ptr.hpp>
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
	awl::event::container
	poll(
		awl::backends::posix::optional_duration const &
	) = 0;

	virtual
	awl::timer::unique_ptr
	create_timer(
		awl::timer::setting const &
	) = 0;

	AWL_DETAIL_SYMBOL
	virtual
	~processor() = 0;
};

}
}
}

#endif
