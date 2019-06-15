#ifndef AWL_BACKENDS_SDL_CURSOR_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_SDL_CURSOR_OBJECT_HPP_INCLUDED

#include <awl/backends/sdl/cursor/object_fwd.hpp>
#include <awl/cursor/object.hpp>
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

class AWL_DETAIL_CLASS_SYMBOL object
:
	public awl::cursor::object
{
	FCPPT_NONCOPYABLE(
		object
	);
public:
	AWL_DETAIL_SYMBOL
	object();

	AWL_DETAIL_SYMBOL
	~object()
	override;
};

}
}
}
}

#endif
