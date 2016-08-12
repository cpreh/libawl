#ifndef AWL_BACKENDS_X11_WINDOW_HOLDER_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_HOLDER_HPP_INCLUDED

#include <awl/backends/x11/display_fwd.hpp>
#include <awl/backends/x11/window/holder_fwd.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/X.h>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace window
{

class holder
{
	FCPPT_NONCOPYABLE(
		holder
	);
public:
	holder(
		awl::backends::x11::display &,
		Window
	);

	~holder();

	void
	destroy();

	bool
	destroyed() const;

	Window
	get() const;
private:
	void
	do_destroy();

	awl::backends::x11::display &display_;

	Window const window_;

	bool destroyed_;
};

}
}
}
}

#endif
