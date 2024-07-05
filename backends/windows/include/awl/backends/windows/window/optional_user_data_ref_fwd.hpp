#ifndef AWL_BACKENDS_WINDOWS_WINDOW_OPTIONAL_USER_DATA_REF_FWD_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_WINDOW_OPTIONAL_USER_DATA_REF_FWD_HPP_INCLUDED

#include <awl/backends/windows/window/user_data_fwd.hpp>
#include <fcppt/optional/reference_fwd.hpp>

namespace awl
{
namespace backends
{
namespace windows
{
namespace window
{

typedef fcppt::optional::reference<awl::backends::windows::window::user_data const>
    optional_user_data_ref;

}
}
}
}

#endif
