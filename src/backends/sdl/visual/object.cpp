#include <awl/backends/sdl/visual/flags.hpp>
#include <awl/backends/sdl/visual/object.hpp>
#include <awl/visual/object.hpp>


awl::backends::sdl::visual::object::object(
	awl::backends::sdl::visual::flags const _flags
)
:
	awl::visual::object{},
	flags_{
		_flags
	}
{
}

awl::backends::sdl::visual::object::~object()
{
}

awl::backends::sdl::visual::flags
awl::backends::sdl::visual::object::flags() const
{
	return
		this->flags_;
}
