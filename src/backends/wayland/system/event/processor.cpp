#include <awl/backends/posix/processor_base.hpp>
#include <awl/backends/wayland/system/event/processor.hpp>
#include <awl/system/event/processor.hpp>


awl::backends::wayland::system::event::processor::processor()
:
	awl::system::event::processor(),
	awl::backends::posix::processor_base()
{
}

awl::backends::wayland::system::event::processor::~processor()
= default;
