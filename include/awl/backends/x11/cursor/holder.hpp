#ifndef AWL_BACKENDS_X11_CURSOR_HOLDER_HPP_INCLUDED
#define AWL_BACKENDS_X11_CURSOR_HOLDER_HPP_INCLUDED

#include <awl/backends/x11/X.hpp>
#include <awl/backends/x11/display_ref.hpp>
#include <awl/backends/x11/cursor/holder_fwd.hpp>
#include <awl/detail/symbol.hpp>
#include <fcppt/nonmovable.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace cursor
{

class holder
{
	FCPPT_NONMOVABLE(
		holder
	);
public:
	AWL_DETAIL_SYMBOL
	holder(
		awl::backends::x11::display_ref,
		Cursor
	);

	AWL_DETAIL_SYMBOL
	~holder();

	[[nodiscard]]
	AWL_DETAIL_SYMBOL
	Cursor
	get() const;
private:
	awl::backends::x11::display_ref const display_;

	Cursor const cursor_;
};

}
}
}
}

#endif
