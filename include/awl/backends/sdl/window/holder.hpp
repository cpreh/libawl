#ifndef AWL_BACKENDS_SDL_WINDOW_HOLDER_HPP_INCLUDED
#define AWL_BACKENDS_SDL_WINDOW_HOLDER_HPP_INCLUDED

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

class holder
{
	FCPPT_NONCOPYABLE(
		holder
	);
public:
	explicit
	holder(
		SDL_Window *
	);

	~holder();

	SDL_Window *
	get() const;
private:
	SDL_Window *const window_;
};

}
}
}
}

#endif
