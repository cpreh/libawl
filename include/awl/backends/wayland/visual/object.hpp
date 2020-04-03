#ifndef AWL_BACKENDS_WAYLAND_VISUAL_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_VISUAL_OBJECT_HPP_INCLUDED

#include <awl/detail/class_symbol.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/visual/object.hpp>
#include <fcppt/nonmovable.hpp>


namespace awl
{
namespace backends
{
namespace wayland
{
namespace visual
{

class AWL_DETAIL_CLASS_SYMBOL object
:
	public
		awl::visual::object
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
