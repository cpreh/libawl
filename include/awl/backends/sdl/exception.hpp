#ifndef AWL_BACKENDS_SDL_EXCEPTION_HPP_INCLUDED
#define AWL_BACKENDS_SDL_EXCEPTION_HPP_INCLUDED

#include <awl/exception.hpp>
#include <awl/detail/class_symbol.hpp>
#include <awl/detail/symbol.hpp>
#include <fcppt/string.hpp>


namespace awl::backends::sdl
{

class AWL_DETAIL_CLASS_SYMBOL exception
:
	public awl::exception
{
public:
	explicit
	exception(
		fcppt::string &&
	);

	AWL_DETAIL_SYMBOL
	exception(
		exception const &
	);

	AWL_DETAIL_SYMBOL
	exception(
		exception &&
	)
	noexcept;

	AWL_DETAIL_SYMBOL
	exception &
	operator=(
		exception const &
	);

	AWL_DETAIL_SYMBOL
	exception &
	operator=(
		exception &&
	)
	noexcept;

	AWL_DETAIL_SYMBOL
	~exception() noexcept
	override;
};

}

#endif
