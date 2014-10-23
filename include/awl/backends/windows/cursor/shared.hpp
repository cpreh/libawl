#ifndef AWL_BACKENDS_WINDOWS_CURSOR_SHARED_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_CURSOR_SHARED_HPP_INCLUDED

#include <awl/class_symbol.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/cursor/object.hpp>
#include <awl/backends/windows/cursor/shared_fwd.hpp>
#include <fcppt/noncopyable.hpp>


namespace awl
{
namespace backends
{
namespace windows
{
namespace cursor
{

class AWL_CLASS_SYMBOL shared
:
	public awl::backends::windows::cursor::object
{
	FCPPT_NONCOPYABLE(
		shared
	);
public:
	AWL_DETAIL_SYMBOL
	explicit
	shared(
		HCURSOR
	);

	AWL_DETAIL_SYMBOL
	~shared();

	AWL_DETAIL_SYMBOL
	HCURSOR
	get() const;
private:
	HCURSOR const cursor_;
};

}
}
}
}

#endif
