#ifndef AWL_BACKENDS_X11_EVENT_PROCESSOR_HPP_INCLUDED
#define AWL_BACKENDS_X11_EVENT_PROCESSOR_HPP_INCLUDED

#include <awl/class_symbol.hpp>
#include <awl/backends/x11/event/processor_fwd.hpp>
#include <awl/backends/x11/system/object_fwd.hpp>
#include <awl/backends/x11/system/event/optional_processor_ref.hpp>
#include <awl/backends/x11/window/event/processor_fwd.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/event/processor.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/reference_std_hash.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xlib.h>
#include <unordered_map>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace event
{

class AWL_CLASS_SYMBOL processor
:
	public awl::event::processor
{
	FCPPT_NONCOPYABLE(
		processor
	);
public:
	AWL_DETAIL_SYMBOL
	processor(
		awl::backends::x11::system::object &,
		awl::backends::x11::system::event::optional_processor_ref const &
	);

	AWL_DETAIL_SYMBOL
	~processor()
	override;

	AWL_DETAIL_SYMBOL
	bool
	poll()
	override;

	AWL_DETAIL_SYMBOL
	void
	next()
	override;

	AWL_DETAIL_SYMBOL
	void
	attach(
		awl::window::event::processor &
	)
	override;

	AWL_DETAIL_SYMBOL
	void
	detach(
		awl::window::event::processor &
	)
	override;
private:
	typedef
	fcppt::reference<
		awl::backends::x11::window::event::processor
	>
	window_event_processor_ref;

	typedef
	std::unordered_map<
		Window,
		window_event_processor_ref
	>
	window_processor_map;

	awl::backends::x11::system::object &system_;

	awl::backends::x11::system::event::optional_processor_ref const system_processor_;

	window_processor_map window_processors_;
};

}
}
}
}

#endif
