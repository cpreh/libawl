#ifndef AWL_BACKENDS_WAYLAND_SYSTEM_EVENT_BASE_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_SYSTEM_EVENT_BASE_HPP_INCLUDED

#include <awl/backends/wayland/display_fwd.hpp>
#include <awl/backends/wayland/display_reference.hpp>
#include <awl/backends/wayland/system/event/base_fwd.hpp>
#include <awl/detail/class_symbol.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/event/base.hpp>
#include <fcppt/noncopyable.hpp>


namespace awl
{
namespace backends
{
namespace wayland
{
namespace system
{
namespace event
{

class base
:
	public awl::event::base
{
	FCPPT_NONCOPYABLE(
		base
	);
public:
	AWL_DETAIL_SYMBOL
	explicit
	base(
		awl::backends::wayland::display_reference
	);

	AWL_DETAIL_SYMBOL
	~base()
	override;

	AWL_DETAIL_SYMBOL
	awl::backends::wayland::display &
	display() const;
private:
	awl::backends::wayland::display_reference const display_;
};

}
}
}
}
}

#endif
