#ifndef AWL_CURSOR_OPTIONAL_TYPE_FWD_HPP_INCLUDED
#define AWL_CURSOR_OPTIONAL_TYPE_FWD_HPP_INCLUDED

#include <awl/cursor/type_fwd.hpp>
#include <fcppt/optional/object_fwd.hpp>


namespace awl::cursor
{

using
optional_type
=
fcppt::optional::object<
	awl::cursor::type
>;

}

#endif
