#include <awl/backends/windows/event/get.hpp>
#include <awl/backends/windows/event/lparam.hpp>
#include <awl/backends/windows/event/message.hpp>
#include <awl/backends/windows/event/object.hpp>
#include <awl/backends/windows/event/peek.hpp>
#include <awl/backends/windows/event/processor.hpp>
#include <awl/backends/windows/event/type.hpp>
#include <awl/backends/windows/event/wparam.hpp>
#include <awl/backends/windows/system/object_fwd.hpp>
#include <awl/backends/windows/system/event/optional_processor_ref.hpp>
#include <awl/backends/windows/system/event/processor.hpp>
#include <awl/backends/windows/window/object.hpp>
#include <awl/backends/windows/window/event/processor.hpp>
#include <fcppt/const.hpp>
#include <fcppt/make_ref.hpp>
#include <fcppt/reference_wrapper_impl.hpp>
#include <fcppt/assert/error.hpp>
#include <fcppt/cast/static_downcast.hpp>
#include <fcppt/container/find_opt_mapped.hpp>
#include <fcppt/optional/copy_value.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/optional/maybe_void.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstdlib>
#include <utility>
#include <fcppt/config/external_end.hpp>


awl::backends::windows::event::processor::processor(
	awl::backends::windows::system::object &,
	awl::backends::windows::system::event::optional_processor_ref const &_system_processor
)
:
	system_processor_(
		_system_processor
	),
	window_processors_()
{
}

awl::backends::windows::event::processor::~processor()
{
}

bool
awl::backends::windows::event::processor::poll()
{
	bool events_processed(
		this->poll_messages()
	);

	fcppt::optional::maybe_void(
		system_processor_,
		[
			&events_processed
		](
			fcppt::reference_wrapper<
				awl::backends::windows::system::event::processor
			> const _processor
		)
		{
			events_processed =
				_processor.get().poll_handles()
				||
				events_processed;
		}
	);

	return
		events_processed;
}

void
awl::backends::windows::event::processor::next()
{
	fcppt::optional::maybe(
		system_processor_,
		[
			this
		]{
			this->do_process(
				awl::backends::windows::event::get()
			);
		},
		[
			this
		](
			fcppt::reference_wrapper<
				awl::backends::windows::system::event::processor
			> const _processor
		)
		{
			_processor.get().next();

			this->poll_messages();
		}
	);
}

void
awl::backends::windows::event::processor::attach(
	awl::window::event::processor &_processor
)
{
	awl::backends::windows::window::event::processor &windows_processor(
		fcppt::cast::static_downcast<
			awl::backends::windows::window::event::processor &
		>(
			_processor
		)
	);

	FCPPT_ASSERT_ERROR(
		window_processors_.insert(
			std::make_pair(
				windows_processor.windows_window().hwnd(),
				fcppt::make_ref(
					windows_processor
				)
			)
		).second
	);
}

void
awl::backends::windows::event::processor::detach(
	awl::window::event::processor &_processor
)
{
	FCPPT_ASSERT_ERROR(
		window_processors_.erase(
			fcppt::cast::static_downcast<
				awl::backends::windows::window::event::processor &
			>(
				_processor
			).windows_window().hwnd()
		)
		== 1u
	);
}

void
awl::backends::windows::event::processor::do_process(
	awl::backends::windows::event::message const &_msg
)
{
	if(
		_msg.get().hwnd
		==
		NULL
	)
	{
		fcppt::optional::maybe_void(
			system_processor_,
			[
				&_msg
			](
				fcppt::reference_wrapper<
					awl::backends::windows::system::event::processor
				> const _processor
			)
			{
				_processor.get().process(
					awl::backends::windows::event::object(
						awl::backends::windows::event::type(
							_msg.get().message
						),
						awl::backends::windows::event::wparam(
							_msg.get().wParam
						),
						awl::backends::windows::event::lparam(
							_msg.get().lParam
						)
					)
				);
			}
		);

		return;
	}

	fcppt::optional::maybe_void(
		fcppt::optional::copy_value(
			fcppt::container::find_opt_mapped(
				window_processors_,
				_msg.get().hwnd
			)
		),
		[
			&_msg
		](
			window_processor_ref const _processor
		)
		{
			_processor.get().process(
				_msg
			);
		}
	);
}

bool
awl::backends::windows::event::processor::poll_messages()
{
	bool events_processed{
		false
	};

	while(
		fcppt::optional::maybe(
			awl::backends::windows::event::peek(
				NULL
			),
			fcppt::const_(
				false
			),
			[
				this
			](
				awl::backends::windows::event::message const _message
			)
			{
				this->do_process(
					_message
				);

				return
					true;
			}
		)
	)
		events_processed
			= true;

	return
		events_processed;
}
