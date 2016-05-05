#ifndef AWL_BACKENDS_WAYLAND_VISUAL_NULL_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_VISUAL_NULL_OBJECT_HPP_INCLUDED

#include <awl/class_symbol.hpp>
#include <awl/backends/wayland/visual/object.hpp>
#include <awl/detail/symbol.hpp>
#include <fcppt/noncopyable.hpp>


namespace awl
{
namespace backends
{
namespace wayland
{
namespace visual
{

class AWL_CLASS_SYMBOL null_object
:
	public
		awl::backends::wayland::visual::object
{
	FCPPT_NONCOPYABLE(
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
}
}
}

#endif
