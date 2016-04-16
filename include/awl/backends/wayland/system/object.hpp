#ifndef AWL_BACKENDS_WAYLAND_SYSTEM_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_SYSTEM_OBJECT_HPP_INCLUDED

#include <awl/class_symbol.hpp>
#include <awl/backends/wayland/system/object_fwd.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/system/object.hpp>
#include <fcppt/noncopyable.hpp>


namespace awl
{
namespace backends
{
namespace wayland
{
namespace system
{

class AWL_CLASS_SYMBOL object
:
	public awl::system::object
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
};

}
}
}

#endif
