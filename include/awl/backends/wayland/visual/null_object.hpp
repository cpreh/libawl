#ifndef AWL_BACKENDS_WAYLAND_VISUAL_NULL_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_VISUAL_NULL_OBJECT_HPP_INCLUDED

#include <awl/backends/wayland/visual/object.hpp>
#include <awl/detail/class_symbol.hpp>
#include <awl/detail/symbol.hpp>
#include <fcppt/nonmovable.hpp>


namespace awl::backends::wayland::visual
{

class AWL_DETAIL_CLASS_SYMBOL null_object
:
	public
		awl::backends::wayland::visual::object
{
	FCPPT_NONMOVABLE(
		null_object
	);
public:
	AWL_DETAIL_SYMBOL
	null_object();

	AWL_DETAIL_SYMBOL
	~null_object()
	override;
};

}

#endif
