#include <awl/backends/sdl/exception.hpp>
#include <awl/backends/sdl/system/init.hpp>
#include <fcppt/output_to_fcppt_string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/config/external_begin.hpp>
#include <SDL.h>
#include <cstdint>
#include <fcppt/config/external_end.hpp>


awl::backends::sdl::system::init::init(
	std::uint32_t const _systems
)
:
	systems_{
		_systems
	}
{
	if(
		SDL_InitSubSystem(
			_systems
		)
		!=
		0
	)
		throw
			awl::backends::sdl::exception{
				FCPPT_TEXT("SDL_InitSubSystem ")
				+
				fcppt::output_to_fcppt_string(
					_systems
				)
				+
				FCPPT_TEXT(" failed.")
			};
}

awl::backends::sdl::system::init::~init()
{
	SDL_QuitSubSystem(
		this->systems_
	);
}
