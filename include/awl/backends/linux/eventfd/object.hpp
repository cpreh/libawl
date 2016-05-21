#ifndef AWL_BACKENDS_LINUX_EVENTFD_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_LINUX_EVENTFD_OBJECT_HPP_INCLUDED

#include <awl/backends/linux/eventfd/object_fwd.hpp>
#include <awl/backends/posix/fd.hpp>
#include <fcppt/noncopyable.hpp>


namespace awl
{
namespace backends
{
namespace linux
{
namespace eventfd
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
	read();

	void
	write();
private:
	awl::backends::posix::fd const fd_;
};

}
}
}
}

#endif
