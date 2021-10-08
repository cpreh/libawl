#include <awl/backends/posix/processor_base.hpp>
#include <awl/backends/x11/system/event/processor.hpp>
#include <awl/system/event/processor.hpp>

awl::backends::x11::system::event::processor::processor()
    : awl::system::event::processor(), awl::backends::posix::processor_base()
{
}

awl::backends::x11::system::event::processor::~processor() = default;
