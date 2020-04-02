#ifndef AWL_BACKENDS_SDL_SYSTEM_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_SDL_SYSTEM_OBJECT_HPP_INCLUDED

#include <awl/backends/sdl/system/object_fwd.hpp>
#include <awl/detail/class_symbol.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/system/object.hpp>
#include <fcppt/nonmovable.hpp>


namespace awl
{
namespace backends
{
namespace sdl
{
namespace system
{

class AWL_DETAIL_CLASS_SYMBOL object
:
	public awl::system::object
{
	FCPPT_NONMOVABLE(
		object
	);
protected:
	AWL_DETAIL_SYMBOL
	object();
public:
	AWL_DETAIL_SYMBOL
	~object()
	override;
};

}
}
}
}

#endif
