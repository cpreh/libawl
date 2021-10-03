#ifndef AWL_BACKENDS_SDL_SYSTEM_INIT_HPP_INCLUDED
#define AWL_BACKENDS_SDL_SYSTEM_INIT_HPP_INCLUDED

#include <awl/detail/symbol.hpp>
#include <fcppt/nonmovable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstdint>
#include <fcppt/config/external_end.hpp>


namespace awl::backends::sdl::system
{

class init
{
	FCPPT_NONMOVABLE(
		init
	);
public:
	AWL_DETAIL_SYMBOL
	explicit
	init(
		std::uint32_t
	);

	AWL_DETAIL_SYMBOL
	~init();
private:
	std::uint32_t const systems_;
};

}

#endif
