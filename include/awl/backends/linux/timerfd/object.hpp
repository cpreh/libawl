#ifndef AWL_BACKENDS_LINUX_TIMERFD_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_LINUX_TIMERFD_OBJECT_HPP_INCLUDED

#include <awl/backends/linux/timerfd/object_fwd.hpp>
#include <awl/backends/posix/fd.hpp>
#include <awl/timer/setting_fwd.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstdint>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace backends
{
namespace linux
{
namespace timerfd
{

class object
{
	FCPPT_NONCOPYABLE(
		object
	);
public:
	object();

	~object();

	awl::backends::posix::fd
	get() const;

	void
	set_time(
		awl::timer::setting const &
	);

	typedef
	std::uint64_t
	value_type;

	value_type
	read();
private:
	awl::backends::posix::fd const fd_;
};

}
}
}
}

#endif
