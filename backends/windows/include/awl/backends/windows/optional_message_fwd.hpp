#ifndef AWL_BACKENDS_WINDOWS_OPTIONAL_MESSAGE_FWD_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_OPTIONAL_MESSAGE_FWD_HPP_INCLUDED

#include <awl/backends/windows/message_fwd.hpp>
#include <fcppt/optional/object_fwd.hpp>

namespace awl
{
namespace backends
{
namespace windows
{

typedef fcppt::optional::object<awl::backends::windows::message> optional_message;

}
}
}

#endif
