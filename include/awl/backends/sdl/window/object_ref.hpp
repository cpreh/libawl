#ifndef AWL_BACKENDS_SDL_WINDOW_OBJECT_REF_HPP_INCLUDED
#define AWL_BACKENDS_SDL_WINDOW_OBJECT_REF_HPP_INCLUDED

#include <awl/backends/sdl/window/object_fwd.hpp>
#include <fcppt/reference_impl.hpp>


namespace awl
{
namespace backends
{
namespace sdl
{
namespace window
{

using
object_ref
=
fcppt::reference<
	awl::backends::sdl::window::object
>;

}
}
}
}

#endif
