#ifndef AWL_BACKENDS_X11_CURSOR_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_X11_CURSOR_OBJECT_HPP_INCLUDED

#include <awl/backends/x11/X.hpp>
#include <awl/backends/x11/cursor/holder_unique_ptr.hpp>
#include <awl/backends/x11/cursor/object_fwd.hpp>
#include <awl/cursor/object.hpp>
#include <awl/detail/class_symbol.hpp>
#include <awl/detail/symbol.hpp>
#include <fcppt/noncopyable.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace cursor
{

class AWL_DETAIL_CLASS_SYMBOL object
:
	public awl::cursor::object
{
	FCPPT_NONCOPYABLE(
		object
	);
public:
	AWL_DETAIL_SYMBOL
	explicit
	object(
		awl::backends::x11::cursor::holder_unique_ptr &&
	);

	AWL_DETAIL_SYMBOL
	~object()
	override;

	AWL_DETAIL_SYMBOL
	Cursor
	get() const;
private:
	awl::backends::x11::cursor::holder_unique_ptr const holder_;
};

}
}
}
}

#endif
