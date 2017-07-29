#ifndef AWL_BACKENDS_X11_COLORMAP_HPP_INCLUDED
#define AWL_BACKENDS_X11_COLORMAP_HPP_INCLUDED

#include <awl/backends/x11/X.hpp>
#include <awl/backends/x11/display_fwd.hpp>
#include <awl/backends/x11/screen.hpp>
#include <awl/backends/x11/visual/object_fwd.hpp>
#include <awl/detail/symbol.hpp>
#include <fcppt/noncopyable.hpp>


namespace awl
{
namespace backends
{
namespace x11
{

class colormap
{
	FCPPT_NONCOPYABLE(
		colormap
	);
public:
	AWL_DETAIL_SYMBOL
	colormap(
		awl::backends::x11::display &,
		awl::backends::x11::screen,
		awl::backends::x11::visual::object const &
	);

	AWL_DETAIL_SYMBOL
	~colormap();

	AWL_DETAIL_SYMBOL
	Colormap &
	get();

	AWL_DETAIL_SYMBOL
	Colormap const &
	get() const;
private:
	awl::backends::x11::display &display_;

	Colormap colormap_;
};

}
}
}

#endif
