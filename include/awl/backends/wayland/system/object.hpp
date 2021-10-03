#ifndef AWL_BACKENDS_WAYLAND_SYSTEM_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_SYSTEM_OBJECT_HPP_INCLUDED

#include <awl/backends/wayland/display_fwd.hpp>
#include <awl/backends/wayland/system/object_fwd.hpp>
#include <awl/detail/class_symbol.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/system/object.hpp>
#include <fcppt/nonmovable.hpp>


namespace awl::backends::wayland::system
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

	virtual
	awl::backends::wayland::display &
	display() = 0;
};

}

#endif
