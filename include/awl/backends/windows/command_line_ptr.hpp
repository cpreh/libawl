#ifndef AWL_BACKENDS_WINDOWS_COMMAND_LINE_PTR_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_COMMAND_LINE_PTR_HPP_INCLUDED

#include <awl/backends/windows/local_free_deleter.hpp>
#include <fcppt/unique_ptr_impl.hpp>

namespace awl
{
namespace backends
{
namespace windows
{

typedef fcppt::unique_ptr<wchar_t *, awl::backends::windows::local_free_deleter> command_line_ptr;

}
}
}

#endif
