#ifndef AWL_CURSOR_CREATE_INVISIBLE_HPP_INCLUDED
#define AWL_CURSOR_CREATE_INVISIBLE_HPP_INCLUDED

#include <awl/cursor/object_unique_ptr.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/system/object_fwd.hpp>


namespace awl
{
namespace cursor
{

AWL_DETAIL_SYMBOL
awl::cursor::object_unique_ptr
create_invisible(
	awl::system::object &
);

}
}

#endif
