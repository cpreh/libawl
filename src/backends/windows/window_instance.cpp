/*
spacegameengine is a portable easy to use game engine written in C++.
Copyright (C) 2006-2010 Carl Philipp Reh (sefi@s-e-f-i.de)

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/


#include <sge/windows/window.hpp>
#include <sge/windows/detail/combine_result.hpp>
#include <sge/windows/wndclass.hpp>
#include <sge/windows/wndclass_pool.hpp>
#include <sge/windows/module_handle.hpp>
#include <sge/exception.hpp>
#include <fcppt/container/ptr/insert_unique_ptr_map.hpp>
#include <fcppt/math/box/basic_impl.hpp>
#include <fcppt/math/dim/basic_impl.hpp>
#include <fcppt/math/vector/basic_impl.hpp>
#include <fcppt/tr1/array.hpp>
#include <fcppt/tr1/functional.hpp>
#include <fcppt/text.hpp>
#include <fcppt/optional_impl.hpp>
#include <fcppt/make_unique_ptr.hpp>

namespace
{

LRESULT CALLBACK wnd_proc(
	HWND,
	UINT,
	WPARAM,
	LPARAM);

}

awl::backends::windows::window::window(
	dim_type const &sz,
	fcppt::string const &title,
	fcppt::string const &class_name)
:
	wndclass_(
		wndclass_pool(
			class_name,
			wnd_proc
		)
	),
	decoration_size(
		decoration_rect::null()
	)
{

	DWORD const flags = WS_OVERLAPPEDWINDOW;

	RECT r = { 0, 0, 0, 0 };

	if (!AdjustWindowRect(&r, flags, false))
		throw exception(
			FCPPT_TEXT("AdjustWindowRect() failed!"));

	decoration_size = decoration_rect(
		decoration_rect::vector(
			r.left,
			r.top
		),
		decoration_rect::dim(
			r.right,
			r.bottom
		)
	);

	handle = CreateWindow(
		wndclass_->name().c_str(),
		title.c_str(),
		flags,
		0,
		0,
		decoration_size.w() + sz.w(),
		decoration_size.h() + sz.h(),
		0,
		0,
		module_handle(),
		this
	);

	if(!handle)
		throw exception(
			FCPPT_TEXT("CreateWindow() failed!")
		);
}

awl::backends::windows::window::~window()
{
	DestroyWindow(handle);
}

awl::backends::windows::window::dim_type const
awl::backends::windows::window::size() const
{
	RECT rect;
	if(GetWindowRect(handle, &rect) == FALSE)
		throw exception(
			FCPPT_TEXT("GetWindowRect() failed!"));
	return dim_type(
		rect.right - rect.left - decoration_size.w(),
		rect.bottom - rect.top - decoration_size.h()
	);
}

HWND
awl::backends::windows::window::hwnd() const
{
	return handle;
}

fcppt::signal::auto_connection
awl::backends::windows::window::register_callback(
	event_type const msg,
	callback_type const func
)
{
	signal_map::iterator const it(
		signals.find(
			msg
		)
	);

	if(
		it == signals.end()
	)
		fcppt::container::ptr::insert_unique_ptr_map(
			signals,
			msg,
			fcppt::make_unique_ptr<
				signal_type
			>(
				detail::combine_result
			)
		);

	// TODO: can be optimized
	return signals[msg].connect(func);
}

awl::backends::windows::callback_return_type
awl::backends::windows::window::execute_callback(
	event_type const msg,
	WPARAM const wparam,
	LPARAM const lparam
)
{
	signal_map::iterator const it(
		signals.find(msg)
	);

	return it != signals.end()
		? (*(it->second))(
			std::tr1::ref(
				*this
			),
			msg,
			wparam,
			lparam
		)
		: callback_return_type();
}

void
awl::backends::windows::window::show()
{
	::ShowWindow(
		hwnd(),
		SW_NORMAL
	);
}

void
awl::backends::windows::window::dispatch()
{
	MSG msg;
	while(PeekMessage(&msg, handle, 0, 0, PM_REMOVE))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

sge::mainloop::io_service_ptr const
awl::backends::windows::window::io_service() const
{
	return mainloop::io_service_ptr();
}

namespace
{

LRESULT CALLBACK
wnd_proc(
	HWND const hwnd,
	unsigned const msg,
	WPARAM const wparam,
	LPARAM const lparam
)
{
	if (msg == WM_CREATE)
	{
		CREATESTRUCT* const s = reinterpret_cast<CREATESTRUCT*>(lparam);
		SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(s->lpCreateParams));
	}

	awl::backends::windows::window *const wnd = reinterpret_cast<awl::backends::windows::window*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));
	if (wnd)
	{
		awl::backends::windows::callback_return_type const ret =
			wnd->execute_callback(msg, wparam, lparam);
		if (ret)
			return *ret;
	}

	switch(msg) {
	case WM_CLOSE:
		return 0;
	case WM_CREATE:
		break;
	case WM_ACTIVATE:
	{
		awl::backends::windows::window* const wnd
			= reinterpret_cast<awl::backends::windows::window*>(
				GetWindowLongPtr(hwnd, GWLP_USERDATA));

		bool const active = wparam != 0 ? true : false;
		if(!active)
			ShowWindow(wnd->hwnd(),SW_MINIMIZE);
		return 0;
	}
	default:
		return DefWindowProc(hwnd,msg,wparam,lparam);
	}
	return TRUE;
}

}
