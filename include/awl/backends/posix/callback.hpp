#ifndef AWL_BACKENDS_POSIX_CALLBACK_HPP_INCLUDED
#define AWL_BACKENDS_POSIX_CALLBACK_HPP_INCLUDED

#include <awl/backends/posix/function.hpp>
#include <fcppt/function_impl.hpp>


namespace awl
{
namespace backends
{
namespace posix
{

typedef
fcppt::function<
	awl::backends::posix::function
>
callback;

}
}
}

#endif
