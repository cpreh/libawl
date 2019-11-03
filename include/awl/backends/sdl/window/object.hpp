#ifndef AWL_BACKENDS_SDL_WINDOW_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_SDL_WINDOW_OBJECT_HPP_INCLUDED

#include <awl/backends/sdl/window/object_fwd.hpp>
#include <awl/detail/class_symbol.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/window/dim_fwd.hpp>
#include <awl/window/object.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <SDL_video.h>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace backends
{
namespace sdl
{
namespace window
{

class AWL_DETAIL_CLASS_SYMBOL object
:
	public awl::window::object
{
	FCPPT_NONCOPYABLE(
		object
	);
protected:
	AWL_DETAIL_SYMBOL
	object();
public:
	AWL_DETAIL_SYMBOL
	~object()
	override;

	AWL_DETAIL_SYMBOL
	void
	show()
	override;

	AWL_DETAIL_SYMBOL
	awl::window::dim
	size() const
	override;

	virtual
	SDL_Window &
	get() const = 0;

	virtual
	void
	set_cursor() = 0;
};

}
}
}
}

#endif