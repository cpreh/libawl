#ifndef AWL_BACKENDS_SDL_SYSTEM_OBJECT_REF_HPP_INCLUDED
#define AWL_BACKENDS_SDL_SYSTEM_OBJECT_REF_HPP_INCLUDED

#include <awl/backends/sdl/system/object_fwd.hpp>
#include <fcppt/reference_impl.hpp>


namespace awl
{
namespace backends
{
namespace sdl
{
namespace system
{

using
object_ref
=
fcppt::reference<
	awl::backends::sdl::system::object
>;

}
}
}
}

#endif
