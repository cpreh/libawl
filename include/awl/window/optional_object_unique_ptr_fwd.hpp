#ifndef AWL_WINDOW_OPTIONAL_OBJECT_UNIQUE_PTR_FWD_HPP_INCLUDED
#define AWL_WINDOW_OPTIONAL_OBJECT_UNIQUE_PTR_FWD_HPP_INCLUDED

#include <awl/window/object_unique_ptr.hpp>
#include <fcppt/optional_fwd.hpp>


namespace awl
{
namespace window
{

typedef
fcppt::optional<
	awl::window::object_unique_ptr
>
optional_object_unique_ptr;

}
}

#endif
