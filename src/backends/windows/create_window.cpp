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


#include <sge/windows/create_window.hpp>
#include <sge/windows/choose_and_set_pixel_format.hpp>
#include <sge/windows/gdi_device.hpp>
#include <sge/windows/window_ptr.hpp>
#include <sge/windows/window.hpp>
#include <sge/window/parameters.hpp>
#include <sge/renderer/parameters.hpp>
#include <fcppt/math/dim/basic_impl.hpp>
#include <fcppt/make_shared_ptr.hpp>

sge::window::instance_ptr const
awl::backends::windows::create_window(
	sge::window::parameters const &param,
	optional_renderer_parameters const &rparam
)
{
	windows::window_ptr const wnd(
		fcppt::make_shared_ptr<
			windows::window
		>(
			*param.dim(),
			param.title(),
			param.class_name()
		)
	);

	if(rparam)
		windows::choose_and_set_pixel_format(
			windows::gdi_device(
				wnd->hwnd(),
				windows::gdi_device::get_tag()),
			PFD_DRAW_TO_WINDOW |
			PFD_SUPPORT_OPENGL |
			PFD_DOUBLEBUFFER,
			PFD_TYPE_RGBA,
			static_cast<BYTE>(rparam->display_mode().bit_depth()),
			static_cast<BYTE>(rparam->depth_buffer()),
			static_cast<BYTE>(rparam->stencil_buffer()));

	return wnd;
}
