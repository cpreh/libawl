#ifndef AWL_BACKENDS_X11_PIXMAP_HOLDER_HPP_INCLUDED
#define AWL_BACKENDS_X11_PIXMAP_HOLDER_HPP_INCLUDED

#include <awl/backends/x11/X.hpp>
#include <awl/backends/x11/display_fwd.hpp>
#include <awl/backends/x11/pixmap/holder_fwd.hpp>
#include <awl/detail/symbol.hpp>
#include <fcppt/noncopyable.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace pixmap
{

class holder
{
	FCPPT_NONCOPYABLE(
		holder
	);
public:
	AWL_DETAIL_SYMBOL
	holder(
		awl::backends::x11::display const &,
		Pixmap
	);

	AWL_DETAIL_SYMBOL
	~holder();

	AWL_DETAIL_SYMBOL
	Pixmap
	get() const;
private:
	awl::backends::x11::display const &display_;

	Pixmap const pixmap_;
};

}
}
}
}

#endif
