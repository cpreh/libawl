#ifndef AWL_BACKENDS_SDL_WINDOW_ORIGINAL_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_SDL_WINDOW_ORIGINAL_OBJECT_HPP_INCLUDED

#include <awl/backends/sdl/window/holder.hpp>
#include <awl/backends/sdl/window/object.hpp>
#include <awl/cursor/const_optional_object_ref.hpp>
#include <awl/detail/class_symbol.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/visual/object_fwd.hpp>
#include <awl/window/parameters_fwd.hpp>
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

class AWL_DETAIL_CLASS_SYMBOL original_object
:
	public awl::backends::sdl::window::object
{
	FCPPT_NONCOPYABLE(
		original_object
	);
public:
	AWL_DETAIL_SYMBOL
	explicit
	original_object(
		awl::window::parameters const &
	);

	AWL_DETAIL_SYMBOL
	~original_object()
	override;

	AWL_DETAIL_SYMBOL
	SDL_Window *
	get() const
	override;

	AWL_DETAIL_SYMBOL
	awl::visual::object const &
	visual() const
	override;
private:
	awl::visual::object const &visual_;

	awl::cursor::const_optional_object_ref const cursor_;

	awl::backends::sdl::window::holder const impl_;
};

}
}
}
}

#endif
