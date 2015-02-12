#ifndef AWL_CURSOR_CREATE_PREDEFINED_HPP_INCLUDED
#define AWL_CURSOR_CREATE_PREDEFINED_HPP_INCLUDED

#include <awl/cursor/object_unique_ptr.hpp>
#include <awl/cursor/predefined_fwd.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/system/object_fwd.hpp>


namespace awl
{
namespace cursor
{

AWL_DETAIL_SYMBOL
awl::cursor::object_unique_ptr
create_predefined(
	awl::system::object &,
	awl::cursor::predefined
);

}
}

#endif
