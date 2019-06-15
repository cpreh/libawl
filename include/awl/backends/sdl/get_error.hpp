#ifndef AWL_BACKENDS_SDL_GET_ERROR_HPP_INCLUDED
#define AWL_BACKENDS_SDL_GET_ERROR_HPP_INCLUDED

#include <awl/detail/symbol.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace backends
{
namespace sdl
{

AWL_DETAIL_SYMBOL
fcppt::optional::object<
	std::string
>
get_error();

}
}
}

#endif
