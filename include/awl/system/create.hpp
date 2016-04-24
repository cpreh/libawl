#ifndef AWL_SYSTEM_CREATE_HPP_INCLUDED
#define AWL_SYSTEM_CREATE_HPP_INCLUDED

#include <awl/detail/symbol.hpp>
#include <awl/system/object_unique_ptr.hpp>


namespace awl
{
namespace system
{

AWL_DETAIL_SYMBOL
awl::system::object_unique_ptr
create();

}
}

#endif
