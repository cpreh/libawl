#ifndef AWL_BACKENDS_WINDOWS_TIMER_WAITABLE_UNIQUE_PTR_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_TIMER_WAITABLE_UNIQUE_PTR_HPP_INCLUDED

#include <awl/backends/windows/timer/waitable_fwd.hpp>
#include <fcppt/unique_ptr_impl.hpp>

namespace awl
{
namespace backends
{
namespace windows
{
namespace timer
{

typedef fcppt::unique_ptr<awl::backends::windows::timer::waitable> waitable_unique_ptr;

}
}
}
}

#endif
