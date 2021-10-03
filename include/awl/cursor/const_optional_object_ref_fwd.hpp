#ifndef AWL_CURSOR_CONST_OPTIONAL_OBJECT_REF_FWD_HPP_INCLUDED
#define AWL_CURSOR_CONST_OPTIONAL_OBJECT_REF_FWD_HPP_INCLUDED

#include <awl/cursor/object_fwd.hpp>
#include <fcppt/optional/reference_fwd.hpp>


namespace awl::cursor
{

using
const_optional_object_ref
=
fcppt::optional::reference<
	awl::cursor::object const
>;

}

#endif
