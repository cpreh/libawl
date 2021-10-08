#include <awl/backends/x11/window/event/mask_bit.hpp>
#include <awl/backends/x11/window/event/optional_mask_bit.hpp>
#include <awl/backends/x11/window/event/to_mask.hpp>
#include <awl/backends/x11/window/event/type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/X.h>
#include <fcppt/config/external_end.hpp>

awl::backends::x11::window::event::optional_mask_bit awl::backends::x11::window::event::to_mask(
    awl::backends::x11::window::event::type const _event_type)
{
#define AWL_BACKENDS_X11_WINDOW_EVENT_TO_MASK_CASE(type_value, mask_value) \
  case type_value: \
    return awl::backends::x11::window::event::optional_mask_bit( \
        awl::backends::x11::window::event::mask_bit(mask_value /* NOLINT(hicpp-signed-bitwise) */ \
                                                    ))
  switch (_event_type.get())
  {
    AWL_BACKENDS_X11_WINDOW_EVENT_TO_MASK_CASE(
        KeyPress,
        KeyPressMask // NOLINT(hicpp-signed-bitwise)
    );
    AWL_BACKENDS_X11_WINDOW_EVENT_TO_MASK_CASE(
        KeyRelease,
        KeyReleaseMask // NOLINT(hicpp-signed-bitwise)
    );
    AWL_BACKENDS_X11_WINDOW_EVENT_TO_MASK_CASE(
        ButtonPress,
        ButtonPressMask // NOLINT(hicpp-signed-bitwise)
    );
    AWL_BACKENDS_X11_WINDOW_EVENT_TO_MASK_CASE(
        ButtonRelease,
        ButtonReleaseMask // NOLINT(hicpp-signed-bitwise)
    );
    AWL_BACKENDS_X11_WINDOW_EVENT_TO_MASK_CASE(
        MotionNotify,
        PointerMotionMask // NOLINT(hicpp-signed-bitwise)
    );
    AWL_BACKENDS_X11_WINDOW_EVENT_TO_MASK_CASE(
        EnterNotify,
        EnterWindowMask // NOLINT(hicpp-signed-bitwise)
    );
    AWL_BACKENDS_X11_WINDOW_EVENT_TO_MASK_CASE(
        LeaveNotify,
        LeaveWindowMask // NOLINT(hicpp-signed-bitwise)
    );
    AWL_BACKENDS_X11_WINDOW_EVENT_TO_MASK_CASE( // NOLINT(bugprone-branch-clone)
        FocusIn,
        FocusChangeMask // NOLINT(hicpp-signed-bitwise)
    );
    AWL_BACKENDS_X11_WINDOW_EVENT_TO_MASK_CASE(
        FocusOut,
        FocusChangeMask // NOLINT(hicpp-signed-bitwise)
    );
    AWL_BACKENDS_X11_WINDOW_EVENT_TO_MASK_CASE(
        KeymapNotify,
        KeymapStateMask // NOLINT(hicpp-signed-bitwise)
    );
    AWL_BACKENDS_X11_WINDOW_EVENT_TO_MASK_CASE(
        Expose,
        ExposureMask // NOLINT(hicpp-signed-bitwise)
    );
    AWL_BACKENDS_X11_WINDOW_EVENT_TO_MASK_CASE(
        VisibilityNotify,
        VisibilityChangeMask // NOLINT(hicpp-signed-bitwise)
    );
    AWL_BACKENDS_X11_WINDOW_EVENT_TO_MASK_CASE(
        CreateNotify,
        SubstructureNotifyMask // NOLINT(hicpp-signed-bitwise)
    );
    AWL_BACKENDS_X11_WINDOW_EVENT_TO_MASK_CASE( // NOLINT(bugprone-branch-clone)
        DestroyNotify,
        StructureNotifyMask // NOLINT(hicpp-signed-bitwise)
    );
    AWL_BACKENDS_X11_WINDOW_EVENT_TO_MASK_CASE(
        UnmapNotify,
        StructureNotifyMask // NOLINT(hicpp-signed-bitwise)
    );
    AWL_BACKENDS_X11_WINDOW_EVENT_TO_MASK_CASE(
        MapNotify,
        StructureNotifyMask // NOLINT(hicpp-signed-bitwise)
    );
    AWL_BACKENDS_X11_WINDOW_EVENT_TO_MASK_CASE(
        MapRequest,
        SubstructureRedirectMask // NOLINT(hicpp-signed-bitwise)
    );
    AWL_BACKENDS_X11_WINDOW_EVENT_TO_MASK_CASE( // NOLINT(bugprone-branch-clone)
        ReparentNotify,
        StructureNotifyMask // NOLINT(hicpp-signed-bitwise)
    );
    AWL_BACKENDS_X11_WINDOW_EVENT_TO_MASK_CASE(
        ConfigureNotify,
        StructureNotifyMask // NOLINT(hicpp-signed-bitwise)
    );
    AWL_BACKENDS_X11_WINDOW_EVENT_TO_MASK_CASE(
        ConfigureRequest,
        SubstructureRedirectMask // NOLINT(hicpp-signed-bitwise)
    );
    AWL_BACKENDS_X11_WINDOW_EVENT_TO_MASK_CASE(
        GravityNotify,
        StructureNotifyMask // NOLINT(hicpp-signed-bitwise)
    );
    AWL_BACKENDS_X11_WINDOW_EVENT_TO_MASK_CASE(
        ResizeRequest,
        ResizeRedirectMask // NOLINT(hicpp-signed-bitwise)
    );
    AWL_BACKENDS_X11_WINDOW_EVENT_TO_MASK_CASE(
        CirculateNotify,
        StructureNotifyMask // NOLINT(hicpp-signed-bitwise)
    );
    AWL_BACKENDS_X11_WINDOW_EVENT_TO_MASK_CASE(
        CirculateRequest,
        SubstructureRedirectMask // NOLINT(hicpp-signed-bitwise)
    );
    AWL_BACKENDS_X11_WINDOW_EVENT_TO_MASK_CASE(
        PropertyNotify,
        PropertyChangeMask // NOLINT(hicpp-signed-bitwise)
    );
    AWL_BACKENDS_X11_WINDOW_EVENT_TO_MASK_CASE(
        ColormapNotify,
        ColormapChangeMask // NOLINT(hicpp-signed-bitwise)
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

  return {};
}
