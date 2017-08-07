#ifndef AWL_BACKENDS_X11_SYSTEM_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_X11_SYSTEM_OBJECT_HPP_INCLUDED

#include <awl/backends/x11/display_fwd.hpp>
#include <awl/backends/x11/screen.hpp>
#include <awl/backends/x11/system/object_fwd.hpp>
#include <awl/detail/class_symbol.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/system/object.hpp>
#include <fcppt/noncopyable.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace system
{

class AWL_DETAIL_CLASS_SYMBOL object
:
	public awl::system::object
{
	FCPPT_NONCOPYABLE(
		object
	);
protected:
	AWL_DETAIL_SYMBOL
	object();
public:
	AWL_DETAIL_SYMBOL
	~object()
	override;

	virtual
	awl::backends::x11::display &
	display() = 0;

	virtual
	awl::backends::x11::screen
	screen() const = 0;
};

}
}
}
}

#endif
