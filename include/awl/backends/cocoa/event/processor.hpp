#ifndef AWL_BACKENDS_COCOA_EVENT_PROCESSOR_HPP_INCLUDED
#define AWL_BACKENDS_COCOA_EVENT_PROCESSOR_HPP_INCLUDED

#include <awl/backends/cocoa/system/object_fwd.hpp>
#include <awl/backends/cocoa/system/event/optional_processor_ref.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/event/processor.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/ptr_container/ptr_vector.hpp>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace backends
{
namespace cocoa
{
namespace event
{
class processor
:
	public awl::event::processor
{
FCPPT_NONCOPYABLE(
	processor);
public:
	AWL_DETAIL_SYMBOL
	processor(
		cocoa::system::object &,
		cocoa::system::event::optional_processor_ref const &);

	AWL_DETAIL_SYMBOL
	~processor();

	AWL_DETAIL_SYMBOL
	bool
	poll();

	AWL_DETAIL_SYMBOL
	void
	next();

	AWL_DETAIL_SYMBOL
	void
	attach(
		awl::window::event::processor &
	);

	AWL_DETAIL_SYMBOL
	void
	detach(
		awl::window::event::processor &
	);
private:
	typedef
	boost::ptr_vector<awl::window::event::processor,boost::view_clone_allocator>
	window_event_processors;

	cocoa::system::object &system_;
	cocoa::system::event::optional_processor_ref const &optional_processor_;
	window_event_processors window_event_processors_;
};
}
}
}
}

#endif
