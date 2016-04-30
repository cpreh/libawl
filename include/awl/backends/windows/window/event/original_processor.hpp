#ifndef AWL_BACKENDS_WINDOWS_WINDOW_EVENT_ORIGINAL_PROCESSOR_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_WINDOW_EVENT_ORIGINAL_PROCESSOR_HPP_INCLUDED

#include <awl/class_symbol.hpp>
#include <awl/backends/windows/lparam.hpp>
#include <awl/backends/windows/message_fwd.hpp>
#include <awl/backends/windows/message_type.hpp>
#include <awl/backends/windows/wparam.hpp>
#include <awl/backends/windows/window/object_fwd.hpp>
#include <awl/backends/windows/window/event/callback.hpp>
#include <awl/backends/windows/window/event/object_fwd.hpp>
#include <awl/backends/windows/window/event/processor.hpp>
#include <awl/backends/windows/window/event/unregister_callback.hpp>
#include <awl/backends/windows/window/event/return_type.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/window/event/close_callback.hpp>
#include <awl/window/event/close_signal.hpp>
#include <awl/window/event/destroy_callback.hpp>
#include <awl/window/event/destroy_signal.hpp>
#include <awl/window/event/hide_callback.hpp>
#include <awl/window/event/hide_signal.hpp>
#include <awl/window/event/resize_callback.hpp>
#include <awl/window/event/resize_signal.hpp>
#include <awl/window/event/show_callback.hpp>
#include <awl/window/event/show_signal.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/strong_typedef_std_hash.hpp>
#include <fcppt/signal/auto_connection_container.hpp>
#include <fcppt/signal/auto_connection_fwd.hpp>
#include <fcppt/signal/object_decl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <unordered_map>
#include <vector>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace backends
{
namespace windows
{
namespace window
{
namespace event
{

class AWL_CLASS_SYMBOL original_processor
:
	public awl::backends::windows::window::event::processor
{
	FCPPT_NONCOPYABLE(
		original_processor
	);
public:
	AWL_DETAIL_SYMBOL
	original_processor(
		awl::backends::windows::window::object &,
		awl::backends::windows::window::event::unregister_callback const &
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

	AWL_DETAIL_SYMBOL
	awl::window::object &
	window() const
	override;

	AWL_DETAIL_SYMBOL
	awl::backends::windows::window::object &
	windows_window() const
	override;

	AWL_DETAIL_SYMBOL
	fcppt::signal::auto_connection
	register_callback(
		awl::backends::windows::message_type,
		windows::window::event::callback const &
	)
	override;

	void
	process(
		awl::backends::windows::message const &
	)
	override;

	// TODO: Why is this here?
	awl::backends::windows::message_type
	allocate_user_message()
	override;

	void
	free_user_message(
		awl::backends::windows::message_type
	)
	override;

	AWL_DETAIL_SYMBOL
	awl::backends::windows::window::event::return_type
	execute_callback(
		awl::backends::windows::message_type,
		awl::backends::windows::wparam,
		awl::backends::windows::lparam
	);
private:
	awl::backends::windows::window::event::return_type
	on_close(
		awl::backends::windows::window::event::object const &
	);

	awl::backends::windows::window::event::return_type
	on_destroy(
		awl::backends::windows::window::event::object const &
	);

	awl::backends::windows::window::event::return_type
	on_resize(
		awl::backends::windows::window::event::object const &
	);

	awl::backends::windows::window::event::return_type
	on_show(
		awl::backends::windows::window::event::object const &
	);

	awl::backends::windows::window::event::return_type
	on_setcursor(
		awl::backends::windows::window::event::object const &
	);

	awl::backends::windows::window::object &window_;

	awl::backends::windows::window::event::unregister_callback const unregister_;

	typedef
	fcppt::signal::object<
		awl::backends::windows::window::event::function
	>
	signal_type;

	typedef
	std::unordered_map<
		awl::backends::windows::message_type,
		signal_type
	>
	signal_map;

	typedef
	std::vector<
		awl::backends::windows::message_type
	>
	user_message_vector;

	signal_map signals_;

	user_message_vector user_messages_;

	awl::window::event::close_signal close_signal_;

	awl::window::event::destroy_signal destroy_signal_;

	awl::window::event::hide_signal hide_signal_;

	awl::window::event::resize_signal resize_signal_;

	awl::window::event::show_signal show_signal_;

	fcppt::signal::auto_connection_container const connections_;
};

}
}
}
}
}

#endif
