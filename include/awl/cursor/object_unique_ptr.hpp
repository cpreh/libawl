#ifndef AWL_CURSOR_OBJECT_UNIQUE_PTR_HPP_INCLUDED
#define AWL_CURSOR_OBJECT_UNIQUE_PTR_HPP_INCLUDED

#include <awl/cursor/object_fwd.hpp>
#include <fcppt/unique_ptr_impl.hpp>


namespace awl
{
namespace cursor
{

using
object_unique_ptr
=
fcppt::unique_ptr<
	awl::cursor::object
>;

}
}

#endif
