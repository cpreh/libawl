#ifndef AWL_SYSTEM_OBJECT_UNIQUE_PTR_HPP_INCLUDED
#define AWL_SYSTEM_OBJECT_UNIQUE_PTR_HPP_INCLUDED

#include <awl/system/object_fwd.hpp>
#include <fcppt/unique_ptr_impl.hpp>

namespace awl::system
{

using object_unique_ptr = fcppt::unique_ptr<awl::system::object>;

}

#endif
