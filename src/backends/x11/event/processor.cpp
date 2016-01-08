#include <awl/backends/linux/fd/optional_duration.hpp>
#include <awl/backends/linux/fd/processor.hpp>
#include <awl/backends/x11/event/next.hpp>
#include <awl/backends/x11/event/object.hpp>
#include <awl/backends/x11/event/pending.hpp>
#include <awl/backends/x11/event/processor.hpp>
#include <awl/backends/x11/system/object.hpp>
#include <awl/backends/x11/system/event/optional_processor_ref.hpp>
#include <awl/backends/x11/system/event/processor.hpp>
#include <awl/backends/x11/window/object.hpp>
#include <awl/backends/x11/window/event/processor.hpp>
#include <awl/window/event/processor_fwd.hpp>
#include <fcppt/const.hpp>
#include <fcppt/make_ref.hpp>
#include <fcppt/reference_wrapper_impl.hpp>
#include <fcppt/assert/error.hpp>
#include <fcppt/cast/static_downcast.hpp>
#include <fcppt/cast/static_downcast_ptr.hpp>
#include <fcppt/cast/try_dynamic.hpp>
#include <fcppt/container/find_opt_mapped.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/optional/maybe_void.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/X.h>
#include <utility>
#include <fcppt/config/external_end.hpp>


awl::backends::x11::event::processor::processor(
	awl::backends::x11::system::object &_system,
	awl::backends::x11::system::event::optional_processor_ref const &_system_processor
)
:
	system_(
		_system
	),
	system_processor_(
		_system_processor
	),
	window_processors_()
{
}

awl::backends::x11::event::processor::~processor()
{
}

bool
awl::backends::x11::event::processor::poll()
{
	// events might come in any order
	// so make sure to process as much as possible in one go
	bool events_processed = false;

	bool more_messages = true;

	while(
		more_messages
	)
	{
		fcppt::optional::maybe_void(
			system_processor_,
			[
				&more_messages
			](
				fcppt::reference_wrapper<
					awl::backends::x11::system::event::processor
				> const _system_processor
			)
			{
				more_messages =
					_system_processor.get().poll();
			}
		);

		for(
			auto &entry
			:
			window_processors_
		)
			more_messages =
				entry.second.get().poll()
				||
				more_messages;

		if(
			more_messages
		)
			events_processed = true;
		else
			break;
	}

	return
		events_processed;
}

void
awl::backends::x11::event::processor::next()
{
	// TODO: This is a complicated check for pending events, move this into a function!
	if(
		fcppt::optional::maybe(
			system_processor_,
			fcppt::const_(
				false
			),
			[
				this
			](
				fcppt::reference_wrapper<
					awl::backends::x11::system::event::processor
				> const _system_processor
			)
			{
				return
					!_system_processor.get().running()
					||
					fcppt::optional::maybe(
						fcppt::cast::try_dynamic<
							awl::backends::linux::fd::processor
						>(
							_system_processor.get()
						),
						fcppt::const_(
							false
						),
						[
							this
						](
							fcppt::reference_wrapper<
								awl::backends::linux::fd::processor
							> const _linux_processor
						)
						{
							_linux_processor.get().epoll(
								awl::backends::linux::fd::optional_duration()
							);

							return
								!awl::backends::x11::event::pending(
									system_.display()
								);
						}
					);
			}
		)
	)
		return;

	awl::backends::x11::event::object const event(
		awl::backends::x11::event::next(
			system_.display()
		)
	);

	if(
		event.get().type
		==
		GenericEvent
	)
	{
		fcppt::optional::maybe_void(
			system_processor_,
			[
				&event
			](
				fcppt::reference_wrapper<
					awl::backends::x11::system::event::processor
				> const _system_processor
			)
			{
				_system_processor.get().process(
					event
				);
			}
		);

		return;
	}

	fcppt::optional::maybe_void(
		fcppt::container::find_opt_mapped(
			window_processors_,
			event.get().xany.window
		),
		[
			&event
		](
			fcppt::reference_wrapper<
				window_event_processor_ref
			> const _processor
		)
		{
			_processor.get().get().process(
				event
			);
		}
	);
}

void
awl::backends::x11::event::processor::attach(
	awl::window::event::processor &_processor
)
{
	awl::backends::x11::window::event::processor &x11_processor(
		fcppt::cast::static_downcast<
			awl::backends::x11::window::event::processor &
		>(
			_processor
		)
	);

	FCPPT_ASSERT_ERROR((
		window_processors_.insert(
			std::make_pair(
				x11_processor.x11_window().get(),
				fcppt::make_ref(
					x11_processor
				)
			)
		).second
	));
}

void
awl::backends::x11::event::processor::detach(
	awl::window::event::processor &_processor
)
{
	FCPPT_ASSERT_ERROR(
		window_processors_.erase(
			fcppt::cast::static_downcast<
				awl::backends::x11::window::event::processor &
			>(
				_processor
			).x11_window().get()
		)
		==
		1u
	);
}
