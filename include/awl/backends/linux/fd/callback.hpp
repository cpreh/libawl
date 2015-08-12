#ifndef AWL_BACKENDS_LINUX_FD_CALLBACK_HPP_INCLUDED
#define AWL_BACKENDS_LINUX_FD_CALLBACK_HPP_INCLUDED

#include <awl/backends/linux/fd/function.hpp>
#include <fcppt/function_impl.hpp>


namespace awl
{
namespace backends
{
namespace linux
{
namespace fd
{

typedef
fcppt::function<
	awl::backends::linux::fd::function
>
callback;

}
}
}
}

#endif
