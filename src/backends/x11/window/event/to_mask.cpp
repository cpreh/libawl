#include <awl/backends/x11/window/event/mask_bit.hpp>
#include <awl/backends/x11/window/event/optional_mask_bit.hpp>
#include <awl/backends/x11/window/event/to_mask.hpp>
#include <awl/backends/x11/window/event/type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/X.h>
#include <fcppt/config/external_end.hpp>


awl::backends::x11::window::event::optional_mask_bit
awl::backends::x11::window::event::to_mask(
	awl::backends::x11::window::event::type const _event_type
)
{
#define AWL_BACKENDS_X11_WINDOW_EVENT_TO_MASK_CASE(\
	type_value,\
	mask_value\
)\
case type_value: \
	return \
		awl::backends::x11::window::event::optional_mask_bit(\
			awl::backends::x11::window::event::mask_bit(\
				mask_value\
			) \
		);
	switch(
		_event_type.get()
	)
	{
		AWL_BACKENDS_X11_WINDOW_EVENT_TO_MASK_CASE(
			KeyPress,
			KeyPressMask
		);
		AWL_BACKENDS_X11_WINDOW_EVENT_TO_MASK_CASE(
			KeyRelease,
			KeyReleaseMask
		);
		AWL_BACKENDS_X11_WINDOW_EVENT_TO_MASK_CASE(
			ButtonPress,
			ButtonPressMask
		);
		AWL_BACKENDS_X11_WINDOW_EVENT_TO_MASK_CASE(
			ButtonRelease,
			ButtonReleaseMask
		);
		AWL_BACKENDS_X11_WINDOW_EVENT_TO_MASK_CASE(
			MotionNotify,
			PointerMotionMask
		);
		AWL_BACKENDS_X11_WINDOW_EVENT_TO_MASK_CASE(
			EnterNotify,
			EnterWindowMask
		);
		AWL_BACKENDS_X11_WINDOW_EVENT_TO_MASK_CASE(
			LeaveNotify,
			LeaveWindowMask
		);
		AWL_BACKENDS_X11_WINDOW_EVENT_TO_MASK_CASE(
			FocusIn,
			FocusChangeMask
		);
		AWL_BACKENDS_X11_WINDOW_EVENT_TO_MASK_CASE(
			FocusOut,
			FocusChangeMask
		);
		AWL_BACKENDS_X11_WINDOW_EVENT_TO_MASK_CASE(
			KeymapNotify,
			KeymapStateMask
		);
		AWL_BACKENDS_X11_WINDOW_EVENT_TO_MASK_CASE(
			Expose,
			ExposureMask
		);
		AWL_BACKENDS_X11_WINDOW_EVENT_TO_MASK_CASE(
			VisibilityNotify,
			VisibilityChangeMask
		);
		AWL_BACKENDS_X11_WINDOW_EVENT_TO_MASK_CASE(
			CreateNotify,
			SubstructureNotifyMask
		);
		AWL_BACKENDS_X11_WINDOW_EVENT_TO_MASK_CASE(
			DestroyNotify,
			StructureNotifyMask
		);
		AWL_BACKENDS_X11_WINDOW_EVENT_TO_MASK_CASE(
			UnmapNotify,
			StructureNotifyMask
		);
		AWL_BACKENDS_X11_WINDOW_EVENT_TO_MASK_CASE(
			MapNotify,
			StructureNotifyMask
		);
		AWL_BACKENDS_X11_WINDOW_EVENT_TO_MASK_CASE(
			MapRequest,
			SubstructureRedirectMask
		);
		AWL_BACKENDS_X11_WINDOW_EVENT_TO_MASK_CASE(
			ReparentNotify,
			StructureNotifyMask
		);
		AWL_BACKENDS_X11_WINDOW_EVENT_TO_MASK_CASE(
			ConfigureNotify,
			StructureNotifyMask
		);
		AWL_BACKENDS_X11_WINDOW_EVENT_TO_MASK_CASE(
			ConfigureRequest,
			SubstructureRedirectMask
		);
		AWL_BACKENDS_X11_WINDOW_EVENT_TO_MASK_CASE(
			GravityNotify,
			StructureNotifyMask
		);
		AWL_BACKENDS_X11_WINDOW_EVENT_TO_MASK_CASE(
			ResizeRequest,
			ResizeRedirectMask
		);
		AWL_BACKENDS_X11_WINDOW_EVENT_TO_MASK_CASE(
			CirculateNotify,
			StructureNotifyMask
		);
		AWL_BACKENDS_X11_WINDOW_EVENT_TO_MASK_CASE(
			CirculateRequest,
			SubstructureRedirectMask
		);
		AWL_BACKENDS_X11_WINDOW_EVENT_TO_MASK_CASE(
			PropertyNotify,
			PropertyChangeMask
		);
		AWL_BACKENDS_X11_WINDOW_EVENT_TO_MASK_CASE(
			ColormapNotify,
			ColormapChangeMask
		);
	case GraphicsExpose:
	case NoExpose:
	case SelectionClear:
	case SelectionRequest:
	case SelectionNotify:
	case ClientMessage:
	case MappingNotify:
	case GenericEvent:
		break;
	}

	return
		awl::backends::x11::window::event::optional_mask_bit();
}
