#ifndef AWL_BACKENDS_WINDOWS_TIMER_WAITABLE_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_TIMER_WAITABLE_HPP_INCLUDED

#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/timer/waitable_fwd.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/timer/setting_fwd.hpp>
#include <fcppt/noncopyable.hpp>


namespace awl
{
namespace backends
{
namespace windows
{
namespace timer
{

class waitable
{
	FCPPT_NONCOPYABLE(
		waitable
	);
public:
	AWL_DETAIL_SYMBOL
	waitable();

	AWL_DETAIL_SYMBOL
	~waitable();

	AWL_DETAIL_SYMBOL
	void
	set(
		awl::timer::setting const &
	);

	AWL_DETAIL_SYMBOL
	HANDLE
	handle() const;
private:
	HANDLE const handle_;
};

}
}
}
}

#endif
