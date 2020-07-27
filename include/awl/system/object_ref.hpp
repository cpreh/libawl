#ifndef AWL_SYSTEM_OBJECT_REF_HPP_INCLUDED
#define AWL_SYSTEM_OBJECT_REF_HPP_INCLUDED

#include <awl/system/object_fwd.hpp>
#include <fcppt/reference_impl.hpp>


namespace awl
{
namespace system
{

using
object_ref
=
fcppt::reference<
	awl::system::object
>;

}
}

#endif
