#ifndef AWL_BACKENDS_WAYLAND_WINDOW_EVENT_ORIGINAL_PROCESSOR_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_WINDOW_EVENT_ORIGINAL_PROCESSOR_HPP_INCLUDED

#include <awl/class_symbol.hpp>
#include <awl/backends/wayland/window/object_fwd.hpp>
#include <awl/backends/wayland/window/event/data.hpp>
#include <awl/backends/wayland/window/event/processor.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/window/event/close_callback.hpp>
#include <awl/window/event/close_signal.hpp>
#include <awl/window/event/destroy_callback.hpp>
#include <awl/window/event/destroy_signal.hpp>
#include <awl/window/event/hide_callback.hpp>
#include <awl/window/event/hide_signal.hpp>
#include <awl/window/event/resize_callback.hpp>
#include <awl/window/event/show_callback.hpp>
#include <awl/window/event/show_signal.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/signal/auto_connection_fwd.hpp>
#include <fcppt/signal/object_decl.hpp>


namespace awl
{
namespace backends
{
namespace wayland
{
namespace window
{
namespace event
{

class AWL_CLASS_SYMBOL original_processor
:
	public awl::backends::wayland::window::event::processor
{
	FCPPT_NONCOPYABLE(
		original_processor
	);
public:
	AWL_DETAIL_SYMBOL
	explicit
	original_processor(
		awl::backends::wayland::window::object &
	);

	AWL_DETAIL_SYMBOL
	~original_processor()
	override;

	AWL_DETAIL_SYMBOL
	fcppt::signal::auto_connection
	close_callback(
		awl::window::event::close_callback const &
	)
	override;

	AWL_DETAIL_SYMBOL
	fcppt::signal::auto_connection
	destroy_callback(
		awl::window::event::destroy_callback const &
	)
	override;

	AWL_DETAIL_SYMBOL
	fcppt::signal::auto_connection
	hide_callback(
		awl::window::event::hide_callback const &
	)
	override;

	AWL_DETAIL_SYMBOL
	fcppt::signal::auto_connection
	resize_callback(
		awl::window::event::resize_callback const &
	)
	override;

	AWL_DETAIL_SYMBOL
	fcppt::signal::auto_connection
	show_callback(
		awl::window::event::show_callback const &
	)
	override;
private:
	awl::window::event::close_signal close_signal_;

	awl::window::event::destroy_signal destroy_signal_;

	awl::window::event::hide_signal hide_signal_;

	awl::window::event::show_signal show_signal_;

	awl::backends::wayland::window::event::data data_;
};

}
}
}
}
}

#endif
