#ifndef AWL_BACKENDS_WINDOWS_LOCAL_FREE_DELETER_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_LOCAL_FREE_DELETER_HPP_INCLUDED

#include <awl/backends/windows/local_free.hpp>
#include <awl/backends/windows/local_free_deleter_fwd.hpp>


namespace awl
{
namespace backends
{
namespace windows
{

struct local_free_deleter
{
	template<
		typename T
	>
	void
	operator()(
		T *const _ptr
	) const
	{
		awl::backends::windows::local_free(
			_ptr
		);
	}
};

}
}
}

#endif
