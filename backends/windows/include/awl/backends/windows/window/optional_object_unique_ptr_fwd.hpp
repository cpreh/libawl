#ifndef AWL_BACKENDS_WINDOWS_WINDOW_OPTIONAL_OBJECT_UNIQUE_PTR_FWD_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_WINDOW_OPTIONAL_OBJECT_UNIQUE_PTR_FWD_HPP_INCLUDED

#include <awl/backends/windows/window/object_unique_ptr.hpp>
#include <fcppt/optional/object_fwd.hpp>

namespace awl
{
namespace backends
{
namespace windows
{
namespace window
{

typedef fcppt::optional::object<awl::backends::windows::window::object_unique_ptr>
    optional_object_unique_ptr;

}
}
}
}

#endif
