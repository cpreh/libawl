#ifndef AWL_BACKENDS_X11_DISPLAY_HPP_INCLUDED
#define AWL_BACKENDS_X11_DISPLAY_HPP_INCLUDED

#include <awl/class_symbol.hpp>
#include <awl/backends/x11/discard.hpp>
#include <awl/detail/symbol.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xlib.h>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace backends
{
namespace x11
{

class AWL_CLASS_SYMBOL display
{
	FCPPT_NONCOPYABLE(
		display
	);
protected:
	AWL_DETAIL_SYMBOL
	display();
public:
	virtual
	Display *
	get() const = 0;

	AWL_DETAIL_SYMBOL
	virtual
	~display() = 0;

	AWL_DETAIL_SYMBOL
	void
	sync(
		awl::backends::x11::discard
	);
};

}
}
}

#endif
