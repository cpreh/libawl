#ifndef AWL_BACKENDS_SDL_CURSOR_PREDEFINED_HPP_INCLUDED
#define AWL_BACKENDS_SDL_CURSOR_PREDEFINED_HPP_INCLUDED

#include <awl/backends/sdl/cursor/object.hpp>
#include <awl/cursor/type_fwd.hpp>
#include <awl/detail/class_symbol.hpp>
#include <awl/detail/symbol.hpp>
#include <fcppt/nonmovable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <SDL_mouse.h>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace backends
{
namespace sdl
{
namespace cursor
{

class AWL_DETAIL_CLASS_SYMBOL predefined
:
	public awl::backends::sdl::cursor::object
{
	FCPPT_NONMOVABLE(
		predefined
	);
public:
	AWL_DETAIL_SYMBOL
	explicit
	predefined(
		awl::cursor::type
	);

	AWL_DETAIL_SYMBOL
	~predefined()
	override;

	[[nodiscard]]
	AWL_DETAIL_SYMBOL
	awl::backends::sdl::cursor::object::cursor_ref
	get() const
	override;
private:
	SDL_Cursor *const impl_;
};

}
}
}
}

#endif
