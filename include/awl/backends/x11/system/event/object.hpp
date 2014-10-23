#ifndef AWL_BACKENDS_X11_SYSTEM_EVENT_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_X11_SYSTEM_EVENT_OBJECT_HPP_INCLUDED

#include <awl/detail/symbol.hpp>
#include <awl/backends/x11/system/event/object_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xlib.h>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace system
{
namespace event
{

class object
{
public:
	AWL_DETAIL_SYMBOL
	explicit object(
		XGenericEventCookie const &
	);

	AWL_DETAIL_SYMBOL
	XGenericEventCookie const &
	get() const;

	AWL_DETAIL_SYMBOL
	XGenericEventCookie &
	get();
private:
	XGenericEventCookie event_;
};

}
}
}
}
}

#endif
