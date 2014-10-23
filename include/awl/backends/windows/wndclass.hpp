#ifndef AWL_BACKENDS_WINDOWS_WNDCLASS_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_WNDCLASS_HPP_INCLUDED

#include <awl/detail/symbol.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/wndclass_fwd.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/string.hpp>


namespace awl
{
namespace backends
{
namespace windows
{

class wndclass
{
	FCPPT_NONCOPYABLE(
		wndclass
	);
public:
	wndclass();

	AWL_DETAIL_SYMBOL
	wndclass(
		fcppt::string const &class_name,
		WNDPROC
	);

	AWL_DETAIL_SYMBOL
	wndclass(
		wndclass &&
	);

	AWL_DETAIL_SYMBOL
	wndclass &
	operator=(
		wndclass &&
	);

	AWL_DETAIL_SYMBOL
	~wndclass();

	AWL_DETAIL_SYMBOL
	fcppt::string const &
	name() const;

	AWL_DETAIL_SYMBOL
	void
	swap(
		wndclass &
	);
private:
	fcppt::string class_name_;
};

AWL_DETAIL_SYMBOL
void
swap(
	awl::backends::windows::wndclass &,
	awl::backends::windows::wndclass &
);

}
}
}

#endif
