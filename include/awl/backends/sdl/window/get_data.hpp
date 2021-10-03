#ifndef AWL_BACKENDS_SDL_WINDOW_GET_DATA_HPP_INCLUDED
#define AWL_BACKENDS_SDL_WINDOW_GET_DATA_HPP_INCLUDED

#include <awl/backends/sdl/window/native_reference.hpp>
#include <awl/detail/symbol.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


namespace awl::backends::sdl::window
{

AWL_DETAIL_SYMBOL
fcppt::optional::object<
	void *
>
get_data(
	awl::backends::sdl::window::native_reference,
	std::string const &
);

}

#endif
