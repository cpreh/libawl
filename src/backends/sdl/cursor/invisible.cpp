#include <awl/backends/sdl/cursor/invisible.hpp>
#include <awl/backends/sdl/cursor/object.hpp>
#include <fcppt/optional/reference.hpp>


awl::backends::sdl::cursor::invisible::invisible()
:
	awl::backends::sdl::cursor::object{}
{
}

awl::backends::sdl::cursor::invisible::~invisible()
{
}

awl::backends::sdl::cursor::object::cursor_ref
awl::backends::sdl::cursor::invisible::get() const
{
	return
		awl::backends::sdl::cursor::object::cursor_ref{};
}