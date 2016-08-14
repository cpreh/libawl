#ifndef AWL_BACKENDS_X11_WINDOW_EVENT_SCOPED_MASK_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_EVENT_SCOPED_MASK_HPP_INCLUDED

#include <awl/backends/x11/window/event/mask.hpp>
#include <awl/backends/x11/window/event/processor_fwd.hpp>
#include <awl/backends/x11/window/event/scoped_mask_fwd.hpp>
#include <awl/detail/symbol.hpp>
#include <fcppt/noncopyable.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace window
{
namespace event
{

class scoped_mask
{
	FCPPT_NONCOPYABLE(
		scoped_mask
	);
public:
	AWL_DETAIL_SYMBOL
	scoped_mask(
		awl::backends::x11::window::event::processor &,
		awl::backends::x11::window::event::mask
	);

	AWL_DETAIL_SYMBOL
	~scoped_mask();
private:
	awl::backends::x11::window::event::processor &processor_;

	awl::backends::x11::window::event::mask const mask_;
};

}
}
}
}
}

#endif
