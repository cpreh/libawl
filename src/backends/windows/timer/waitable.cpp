#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/timer/due_time.hpp>
#include <awl/backends/windows/timer/waitable.hpp>
#include <awl/exception.hpp>
#include <awl/timer/object.hpp>
#include <awl/timer/setting.hpp>
#include <fcppt/text.hpp>
#include <fcppt/assert/error.hpp>
#include <fcppt/cast/size.hpp>
#include <fcppt/config/external_begin.hpp>
#include <chrono>
#include <cstdlib>
#include <fcppt/config/external_end.hpp>


awl::backends::windows::timer::waitable::waitable()
:
	handle_{
		::CreateWaitableTimer(
			NULL,
			FALSE, // TODO:
			NULL
		)
	}
{
	if(
		handle_
		==
		NULL
	)
		throw
			awl::exception{
				FCPPT_TEXT("CreateWaitableTimer failed")
			};
}

awl::backends::windows::timer::waitable::~waitable()
{
	FCPPT_ASSERT_ERROR(
		::CloseHandle(
			handle_
		)
		!=
		0
	);
}

void
awl::backends::windows::timer::waitable::set(
	awl::timer::setting const &_setting
)
{
	LARGE_INTEGER const due_time{
		awl::backends::windows::timer::due_time(
			_setting.delay()
		)
	};

	if(
		::SetWaitableTimer(
			handle_,
			&due_time,
			fcppt::cast::size<
				LONG
			>(
				std::chrono::duration_cast<
					std::chrono::milliseconds
				>(
					_setting.period().get()
				).count()
			),
			NULL,
			NULL,
			FALSE
		)
		==
		0
	)
		throw
			awl::exception{
				FCPPT_TEXT("SetWaitableTimer failed")
			};
}

HANDLE
awl::backends::windows::timer::waitable::handle() const
{
	return
		handle_;
}
