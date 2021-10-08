#ifndef AWL_BACKENDS_SDL_SYSTEM_EVENT_REGISTER_HPP_INCLUDED
#define AWL_BACKENDS_SDL_SYSTEM_EVENT_REGISTER_HPP_INCLUDED

#include <awl/backends/sdl/system/event/type.hpp>
#include <awl/detail/symbol.hpp>
#include <fcppt/optional/object_impl.hpp>

namespace awl::backends::sdl::system::event
{

AWL_DETAIL_SYMBOL
fcppt::optional::object<awl::backends::sdl::system::event::type> register_();

}

#endif
