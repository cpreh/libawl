#ifndef AWL_BACKENDS_SDL_WINDOW_SET_DATA_HPP_INCLUDED
#define AWL_BACKENDS_SDL_WINDOW_SET_DATA_HPP_INCLUDED

#include <awl/backends/sdl/window/native_reference.hpp>
#include <awl/detail/symbol.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace backends
{
namespace sdl
{
namespace window
{

AWL_DETAIL_SYMBOL
void
set_data(
	awl::backends::sdl::window::native_reference,
	std::string const &,
	void *
);

}
}
}
}

#endif
