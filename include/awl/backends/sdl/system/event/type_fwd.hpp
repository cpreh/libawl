#ifndef AWL_BACKENDS_SDL_SYSTEM_EVENT_TYPE_FWD_HPP_INCLUDED
#define AWL_BACKENDS_SDL_SYSTEM_EVENT_TYPE_FWD_HPP_INCLUDED

#include <fcppt/make_strong_typedef.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstdint>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace backends
{
namespace sdl
{
namespace system
{
namespace event
{

FCPPT_MAKE_STRONG_TYPEDEF(
	std::uint32_t,
	type
);

}
}
}
}
}

#endif
