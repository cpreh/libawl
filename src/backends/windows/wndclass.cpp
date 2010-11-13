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


#include <sge/windows/wndclass.hpp>
#include <sge/windows/windows.hpp>
#include <sge/windows/module_handle.hpp>
#include <sge/exception.hpp>
#include <fcppt/text.hpp>

awl::backends::windows::wndclass::wndclass(
	fcppt::string const &class_name,
	WNDPROC const proc)
:
	class_name(
		class_name)
{
	WNDCLASSEX wndclass;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hbrBackground = reinterpret_cast<HBRUSH>(COLOR_WINDOW+1);
	wndclass.hCursor = 0;
	wndclass.hIcon = 0;
	wndclass.hIconSm = 0;
	wndclass.hInstance = module_handle();
	wndclass.lpfnWndProc = proc;
	wndclass.lpszClassName = class_name.c_str();
	wndclass.lpszMenuName = 0;
	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = 0;

	if(!RegisterClassEx(&wndclass))
		throw exception(
			FCPPT_TEXT("RegisterClassEx() failed!"));
}

awl::backends::windows::wndclass::~wndclass()
{
	UnregisterClass(
		class_name.c_str(),
		module_handle());
}

fcppt::string const &
awl::backends::windows::wndclass::name() const
{
	return class_name;
}
