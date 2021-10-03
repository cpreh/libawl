#ifndef AWL_BACKENDS_SDL_CURSOR_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_SDL_CURSOR_OBJECT_HPP_INCLUDED

#include <awl/backends/sdl/cursor/object_fwd.hpp>
#include <awl/cursor/object.hpp>
#include <awl/detail/class_symbol.hpp>
#include <awl/detail/symbol.hpp>
#include <fcppt/nonmovable.hpp>
#include <fcppt/optional/reference_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <SDL_mouse.h>
#include <fcppt/config/external_end.hpp>


namespace awl::backends::sdl::cursor
{

class AWL_DETAIL_CLASS_SYMBOL object
:
	public awl::cursor::object
{
	FCPPT_NONMOVABLE(
		object
	);
public:
	AWL_DETAIL_SYMBOL
	object();

	AWL_DETAIL_SYMBOL
	~object()
	override;

	using
	cursor_ref
	=
	fcppt::optional::reference<
		SDL_Cursor
	>;

	[[nodiscard]]
	virtual
	cursor_ref
	get() const = 0;
};

}

#endif
