#ifndef AWL_BACKENDS_WINDOWS_MESSAGE_TYPE_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_MESSAGE_TYPE_HPP_INCLUDED

#include <awl/backends/windows/windows.hpp>
#include <fcppt/declare_strong_typedef.hpp>
#include <fcppt/strong_typedef.hpp>


namespace awl
{
namespace backends
{
namespace windows
{

FCPPT_DECLARE_STRONG_TYPEDEF(
	UINT,
	message_type
);

}
}
}

#endif
