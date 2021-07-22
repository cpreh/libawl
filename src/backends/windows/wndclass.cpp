#include <awl/exception.hpp>
#include <awl/backends/windows/module_handle.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/wndclass.hpp>
#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/assert/pre.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstring>
#include <fcppt/config/external_end.hpp>


awl::backends::windows::wndclass::wndclass(
	fcppt::string const &_class_name,
	WNDPROC const _proc
)
:
	class_name_(
		_class_name
	)
{
	if(
		class_name_.empty()
	)
	{
		throw
			awl::exception{
				FCPPT_TEXT("wndclass name cannot be empty!")
			};
	}

	WNDCLASS object;

	std::memset(
		&object,
		0,
		sizeof(WNDCLASS)
	);

	object.style = 0;

	object.lpfnWndProc = _proc;

	object.cbClsExtra = 0;

	object.cbWndExtra = 0;

	object.hInstance = awl::backends::windows::module_handle();

	object.hIcon = nullptr;

	object.hCursor = nullptr;

	object.hbrBackground =
		reinterpret_cast<
			HBRUSH
		>(
			COLOR_WINDOW
			+
			1
		);

	object.lpszClassName = class_name_.c_str();

	object.lpszMenuName = nullptr;

	if(
		::RegisterClass(
			&object
		)
		==
		0
	)
	{
		throw
			awl::exception{
				FCPPT_TEXT("RegisterClassEx() failed!")
			};
	}
}

awl::backends::windows::wndclass::~wndclass()
{
	::UnregisterClass(
		class_name_.c_str(),
		awl::backends::windows::module_handle()
	);
}

fcppt::string const &
awl::backends::windows::wndclass::name() const
{
	return
		class_name_;
}
