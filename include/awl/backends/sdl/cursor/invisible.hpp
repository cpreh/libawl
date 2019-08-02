#ifndef AWL_BACKENDS_SDL_CURSOR_INVISIBLE_HPP_INCLUDED
#define AWL_BACKENDS_SDL_CURSOR_INVISIBLE_HPP_INCLUDED

#include <awl/backends/sdl/cursor/object.hpp>
#include <awl/detail/class_symbol.hpp>
#include <awl/detail/symbol.hpp>
#include <fcppt/noncopyable.hpp>


namespace awl
{
namespace backends
{
namespace sdl
{
namespace cursor
{

class AWL_DETAIL_CLASS_SYMBOL invisible
:
	public awl::backends::sdl::cursor::object
{
	FCPPT_NONCOPYABLE(
		invisible
	);
public:
	AWL_DETAIL_SYMBOL
	invisible();

	AWL_DETAIL_SYMBOL
	~invisible()
	override;

	AWL_DETAIL_SYMBOL
	awl::backends::sdl::cursor::object::cursor_ref
	get() const
	override;
};

}
}
}
}

#endif
