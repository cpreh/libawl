#include <awl/backends/sdl/system/event/register.hpp>
#include <awl/backends/sdl/system/event/type.hpp>
#include <fcppt/literal.hpp>
#include <fcppt/cast/to_unsigned.hpp>
#include <fcppt/optional/make_if.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <SDL_events.h>
#include <cstdint>
#include <fcppt/config/external_end.hpp>


fcppt::optional::object<
	awl::backends::sdl::system::event::type
>
awl::backends::sdl::system::event::register_()
{
	std::uint32_t const result{
		SDL_RegisterEvents(
			1
		)
	};

	return
		fcppt::optional::make_if(
			result
			!=
			fcppt::cast::to_unsigned(
				fcppt::literal<
					std::int32_t
				>(
					-1
				)
			),
			[
				result
			]{
				return
					awl::backends::sdl::system::event::type{
						result
					};
			}
		);
}
