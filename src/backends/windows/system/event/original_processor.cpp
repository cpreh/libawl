#include <awl/exception.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/event/lparam.hpp>
#include <awl/backends/windows/event/message.hpp>
#include <awl/backends/windows/event/object.hpp>
#include <awl/backends/windows/event/peek.hpp>
#include <awl/backends/windows/event/type.hpp>
#include <awl/backends/windows/event/wparam.hpp>
#include <awl/backends/windows/system/event/handle.hpp>
#include <awl/backends/windows/system/event/handle_destroy_callback.hpp>
#include <awl/backends/windows/system/event/handle_unique_ptr.hpp>
#include <awl/backends/windows/system/event/object.hpp>
#include <awl/backends/windows/system/event/original_handle.hpp>
#include <awl/backends/windows/system/event/original_processor.hpp>
#include <awl/main/exit_code.hpp>
#include <awl/system/optional_exit_code.hpp>
#include <awl/system/event/quit.hpp>
#include <awl/system/event/quit_callback.hpp>
#include <fcppt/const.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/maybe.hpp>
#include <fcppt/strong_typedef_construct_cast.hpp>
#include <fcppt/text.hpp>
#include <fcppt/unique_ptr_to_base.hpp>
#include <fcppt/algorithm/remove.hpp>
#include <fcppt/assert/optional_error.hpp>
#include <fcppt/cast/size.hpp>
#include <fcppt/cast/to_signed.hpp>
#include <fcppt/cast/to_unsigned_fun.hpp>
#include <fcppt/container/raw_vector_impl.hpp>
#include <fcppt/preprocessor/disable_vc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/signal/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <functional>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_VC_WARNING(4355)
awl::backends::windows::system::event::original_processor::original_processor(
	awl::backends::windows::system::object &
)
:
	signals_(),
	handle_signal_(),
	handles_(),
	exit_code_(),
	quit_signal_(),
	quit_connection_(
		this->register_callback(
			fcppt::strong_typedef_construct_cast<
				awl::backends::windows::event::type,
				fcppt::cast::to_unsigned_fun
			>(
				WM_QUIT
			),
			awl::backends::windows::system::event::callback{
				std::bind(
					&awl::backends::windows::system::event::original_processor::on_quit,
					this,
					std::placeholders::_1
				)
			}
		)
	)
{
}
FCPPT_PP_POP_WARNING

awl::backends::windows::system::event::original_processor::~original_processor()
{
}

bool
awl::backends::windows::system::event::original_processor::poll()
{
	bool events_processed{
		false
	};

	while(
		fcppt::maybe(
			awl::backends::windows::event::peek(
				reinterpret_cast<
					HWND
				>(
					-1
				)
			),
			fcppt::const_(
				false
			),
			[
				this
			](
				awl::backends::windows::event::message const &_message
			)
			{
				this->do_process(
					awl::backends::windows::event::type(
						_message.get().message
					),
					awl::backends::windows::system::event::object(
						awl::backends::windows::event::wparam(
							_message.get().wParam
						),
						awl::backends::windows::event::lparam(
							_message.get().lParam
						)
					)
				);

				return
					true;
			}
		)
	)
		events_processed =
			true;

	events_processed =
		this->poll_handles()
		|| events_processed;

	return
		events_processed;
}

void
awl::backends::windows::system::event::original_processor::quit(
	awl::main::exit_code const _exit_code
)
{
	::PostQuitMessage(
		_exit_code.get()
	);
}

bool
awl::backends::windows::system::event::original_processor::running() const
{
	return
		!exit_code_.has_value();
}

awl::main::exit_code const
awl::backends::windows::system::event::original_processor::exit_code() const
{
	return
		FCPPT_ASSERT_OPTIONAL_ERROR(
			exit_code_
		);
}

fcppt::signal::auto_connection
awl::backends::windows::system::event::original_processor::quit_callback(
	awl::system::event::quit_callback const &_callback
)
{
	return
		quit_signal_.connect(
			_callback
		);
}

fcppt::signal::auto_connection
awl::backends::windows::system::event::original_processor::register_callback(
	awl::backends::windows::event::type const _msg,
	awl::backends::windows::system::event::callback const &_func
)
{
	return
		signals_[
			_msg
		].connect(
			_func
		);
}

fcppt::signal::auto_connection
awl::backends::windows::system::event::original_processor::register_handle_callback(
	awl::backends::windows::system::event::handle_callback const &_func
)
{
	return
		handle_signal_.connect(
			_func
		);
}

awl::backends::windows::system::event::handle_unique_ptr
awl::backends::windows::system::event::original_processor::create_event_handle()
{
	awl::backends::windows::system::event::handle_unique_ptr ret(
		fcppt::unique_ptr_to_base<
			awl::backends::windows::system::event::handle
		>(
			fcppt::make_unique_ptr<
				awl::backends::windows::system::event::original_handle
			>(
				awl::backends::windows::system::event::handle_destroy_callback{
					std::bind(
						&awl::backends::windows::system::event::original_processor::unregister_event_handle,
						this,
						std::placeholders::_1
					)
				}
			)
		)
	);

	handles_.push_back(
		ret->get()
	);

	return
		ret;
}

void
awl::backends::windows::system::event::original_processor::process(
	awl::backends::windows::event::object const &_event
)
{
	this->do_process(
		_event.type(),
		awl::backends::windows::system::event::object(
			_event.wparam(),
			_event.lparam()
		)
	);
}

bool
awl::backends::windows::system::event::original_processor::poll_handles()
{
	return
		handles_.empty()
		?
			false
		:
			this->generic_multiple_wait(
				::WaitForMultipleObjects,
				0u
			)
		;
}

void
awl::backends::windows::system::event::original_processor::next()
{
	this->generic_multiple_wait(
		[](
			DWORD const _count,
			HANDLE const *const _handle,
			BOOL const _wait_all,
			DWORD const _milli_seconds
		)
		{
			return
				::MsgWaitForMultipleObjects(
					_count,
					_handle,
					_wait_all,
					_milli_seconds,
					QS_ALLPOSTMESSAGE
				);
		},
		INFINITE
	);
}

void
awl::backends::windows::system::event::original_processor::do_process(
	awl::backends::windows::event::type const _type,
	awl::backends::windows::system::event::object const &_event
)
{
	signals_[
		_type
	](
		_event
	);
}

void
awl::backends::windows::system::event::original_processor::on_quit(
	awl::backends::windows::system::event::object const &_event
)
{
	awl::main::exit_code const res_exit_code(
		fcppt::cast::size<
			int
		>(
			fcppt::cast::to_signed(
				_event.wparam().get()
			)
		)
	);

	exit_code_ =
		awl::system::optional_exit_code(
			res_exit_code
		);

	quit_signal_(
		awl::system::event::quit(
			res_exit_code
		)
	);
}

template<
	typename Function
>
bool
awl::backends::windows::system::event::original_processor::generic_multiple_wait(
	Function _function, // nonconst for VC++2012
	DWORD const _timeout
)
{
	DWORD const result(
		_function(
			fcppt::cast::size<
				DWORD
			>(
				handles_.size()
			),
			handles_.data(),
			FALSE,
			_timeout
		)
	);

	static_assert(
		WAIT_OBJECT_0 == 0,
		"This code assumes that WAIT_OBJECT_0 is 0"
	);

	if(
		result < WAIT_OBJECT_0 + handles_.size()
	)
	{
		handle_signal_();

		return true;
	}
	else if(
		result == WAIT_FAILED
	)
		throw awl::exception(
			FCPPT_TEXT("WaitForMultipleObjects() failed!")
		);

	return false;
}

void
awl::backends::windows::system::event::original_processor::unregister_event_handle(
	HANDLE const _handle
)
{
	fcppt::algorithm::remove(
		handles_,
		_handle
	);
}
