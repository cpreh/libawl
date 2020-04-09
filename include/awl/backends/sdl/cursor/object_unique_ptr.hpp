#ifndef AWL_BACKENDS_SDL_CURSOR_OBJECT_UNIQUE_PTR_HPP_INCLUDED
#define AWL_BACKENDS_SDL_CURSOR_OBJECT_UNIQUE_PTR_HPP_INCLUDED

#include <awl/backends/sdl/cursor/object_fwd.hpp>
#include <fcppt/unique_ptr_impl.hpp>


namespace awl
{
namespace backends
{
namespace sdl
{
namespace cursor
{

using
object_unique_ptr
=
fcppt::unique_ptr<
	awl::backends::sdl::cursor::object
>;

}
}
}
}

#endif
