#ifndef AWL_BACKENDS_X11_SYSTEM_EVENT_ORIGINAL_PROCESSOR_HPP_INCLUDED
#define AWL_BACKENDS_X11_SYSTEM_EVENT_ORIGINAL_PROCESSOR_HPP_INCLUDED

#include <awl/backends/posix/fd.hpp>
#include <awl/backends/posix/optional_duration_fwd.hpp>
#include <awl/backends/posix/processor_fwd.hpp>
#include <awl/backends/posix/processor_unique_ptr.hpp>
#include <awl/backends/x11/X.hpp>
#include <awl/backends/x11/atom.hpp>
#include <awl/backends/x11/display_fwd.hpp>
#include <awl/backends/x11/system/event/object_fwd.hpp>
#include <awl/backends/x11/system/event/original_processor_fwd.hpp>
#include <awl/backends/x11/system/event/processor.hpp>
#include <awl/backends/x11/window/object_fwd.hpp>
#include <awl/backends/x11/window/object_ref.hpp>
#include <awl/backends/x11/window/event/object_fwd.hpp>
#include <awl/detail/class_symbol.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/event/connection_unique_ptr.hpp>
#include <awl/event/container.hpp>
#include <awl/event/optional_base_unique_ptr.hpp>
#include <awl/main/exit_code.hpp>
#include <awl/main/optional_exit_code.hpp>
#include <awl/system/event/processor.hpp>
#include <awl/system/event/result_fwd.hpp>
#include <awl/timer/setting_fwd.hpp>
#include <awl/timer/unique_ptr.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <map>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace system
{
namespace event
{

class AWL_DETAIL_CLASS_SYMBOL original_processor
:
	public awl::backends::x11::system::event::processor
{
	FCPPT_NONCOPYABLE(
		original_processor
	);
public:
	AWL_DETAIL_SYMBOL
	explicit
	original_processor(
		awl::backends::x11::display &
	);

	AWL_DETAIL_SYMBOL
	~original_processor()
	override;

	AWL_DETAIL_SYMBOL
	awl::system::event::result
	poll()
	override;

	AWL_DETAIL_SYMBOL
	awl::system::event::result
	next()
	override;

	AWL_DETAIL_SYMBOL
	void
	quit(
		awl::main::exit_code
	)
	override;

	AWL_DETAIL_SYMBOL
	awl::timer::unique_ptr
	create_timer(
		awl::timer::setting const &
	)
	override;

	AWL_DETAIL_SYMBOL
	awl::backends::posix::processor &
	fd_processor()
	override;

	awl::event::connection_unique_ptr
	add_window(
		awl::backends::x11::window::object &
	);

	AWL_DETAIL_SYMBOL
	awl::backends::x11::atom
	delete_window_atom() const;
private:
	awl::system::event::result
	process(
		awl::backends::posix::optional_duration const &
	) const;

	awl::event::container
	process_fds(
		awl::backends::posix::optional_duration const &
	) const;

	awl::event::container
	process_pending() const;

	awl::event::optional_base_unique_ptr
	process_x11_event(
		awl::backends::x11::system::event::object const &
	) const;

	awl::event::optional_base_unique_ptr
	make_x11_event(
		awl::backends::x11::system::event::object const &
	) const;

	awl::event::base_unique_ptr
	process_window_event(
		awl::backends::x11::window::object_ref,
		awl::backends::x11::window::event::object const &
	) const;

	awl::backends::x11::display &display_;

	awl::backends::posix::fd const fd_;

	awl::backends::posix::processor_unique_ptr const fd_processor_;

	awl::event::connection_unique_ptr const fd_connection_;

	awl::backends::x11::atom const wm_protocols_atom_;

	awl::backends::x11::atom const wm_delete_window_atom_;

	awl::main::optional_exit_code exit_code_;

	typedef
	std::map<
		Window,
		fcppt::reference<
			awl::backends::x11::window::object
		>
	>
	window_map;

	window_map windows_;
};

}
}
}
}
}

#endif
