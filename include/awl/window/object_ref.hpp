#ifndef AWL_WINDOW_OBJECT_REF_HPP_INCLUDED
#define AWL_WINDOW_OBJECT_REF_HPP_INCLUDED

#include <awl/window/object_fwd.hpp>
#include <fcppt/reference_impl.hpp>


namespace awl
{
namespace window
{

using
object_ref
=
fcppt::reference<
	awl::window::object
>;

}
}

#endif
