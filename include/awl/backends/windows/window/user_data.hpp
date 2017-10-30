#ifndef AWL_BACKENDS_WINDOWS_WINDOW_USER_DATA_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_WINDOW_USER_DATA_HPP_INCLUDED

#include <awl/backends/windows/window/reference.hpp>
#include <awl/backends/windows/window/user_data_fwd.hpp>
#include <awl/event/container_reference.hpp>
#include <awl/detail/symbol.hpp>
#include <fcppt/noncopyable.hpp>


namespace awl
{
namespace backends
{
namespace windows
{
namespace window
{

class user_data
{
	FCPPT_NONCOPYABLE(
		user_data
	);
public:
	AWL_DETAIL_SYMBOL
	user_data(
		awl::backends::windows::window::reference,
		awl::event::container_reference
	);

	AWL_DETAIL_SYMBOL
	~user_data();

	AWL_DETAIL_SYMBOL
	awl::backends::windows::window::reference
	window() const;

	AWL_DETAIL_SYMBOL
	awl::event::container_reference
	events() const;
private:
	awl::backends::windows::window::reference const window_;

	awl::event::container_reference const events_;
};

}
}
}
}

#endif
