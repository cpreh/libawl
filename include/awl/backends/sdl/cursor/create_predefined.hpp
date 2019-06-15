#ifndef AWL_BACKENDS_SDL_CURSOR_CREATE_PREDEFINED_HPP_INCLUDED
#define AWL_BACKENDS_SDL_CURSOR_CREATE_PREDEFINED_HPP_INCLUDED

#include <awl/backends/sdl/cursor/object_unique_ptr.hpp>
#include <awl/cursor/type_fwd.hpp>
#include <awl/detail/symbol.hpp>


namespace awl
{
namespace backends
{
namespace sdl
{
namespace cursor
{

AWL_DETAIL_SYMBOL
awl::backends::sdl::cursor::object_unique_ptr
create_predefined(
	awl::cursor::type
);

}
}
}
}

#endif
