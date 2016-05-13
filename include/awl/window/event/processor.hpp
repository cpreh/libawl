#ifndef AWL_WINDOW_EVENT_PROCESSOR_HPP_INCLUDED
#define AWL_WINDOW_EVENT_PROCESSOR_HPP_INCLUDED

#include <awl/class_symbol.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/window/event/close_callback.hpp>
#include <awl/window/event/destroy_callback.hpp>
#include <awl/window/event/hide_callback.hpp>
#include <awl/window/event/processor_fwd.hpp>
#include <awl/window/event/resize_callback.hpp>
#include <awl/window/event/show_callback.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/signal/auto_connection_fwd.hpp>


namespace awl
{
namespace window
{
namespace event
{

class AWL_CLASS_SYMBOL processor
{
	FCPPT_NONCOPYABLE(
		processor
	);
protected:
	AWL_DETAIL_SYMBOL
	processor();
public:
	virtual
	fcppt::signal::auto_connection
	close_callback(
		awl::window::event::close_callback const &
	) = 0;

	virtual
	fcppt::signal::auto_connection
	destroy_callback(
		awl::window::event::destroy_callback const &
	) = 0;

	virtual
	fcppt::signal::auto_connection
	hide_callback(
		awl::window::event::hide_callback const &
	) = 0;

	virtual
	fcppt::signal::auto_connection
	resize_callback(
		awl::window::event::resize_callback const &
	) = 0;

	virtual
	fcppt::signal::auto_connection
	show_callback(
		awl::window::event::show_callback const &
	) = 0;

	AWL_DETAIL_SYMBOL
	virtual
	~processor() = 0;
};

}
}
}

#endif
