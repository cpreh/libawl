#ifndef AWL_BACKENDS_WAYLAND_SYSTEM_ORIGINAL_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_SYSTEM_ORIGINAL_OBJECT_HPP_INCLUDED

#include <awl/backends/wayland/display_fwd.hpp>
#include <awl/backends/wayland/original_display.hpp>
#include <awl/backends/wayland/system/object.hpp>
#include <awl/detail/symbol.hpp>
#include <fcppt/noncopyable.hpp>


namespace awl
{
namespace backends
{
namespace wayland
{
namespace system
{

class original_object
:
	public awl::backends::wayland::system::object
{
	FCPPT_NONCOPYABLE(
		original_object
	);
public:
	AWL_DETAIL_SYMBOL
	original_object();

	AWL_DETAIL_SYMBOL
	~original_object()
	override;

	awl::backends::wayland::display &
	display()
	override;
private:
	awl::backends::wayland::original_display display_;
};

}
}
}
}

#endif
