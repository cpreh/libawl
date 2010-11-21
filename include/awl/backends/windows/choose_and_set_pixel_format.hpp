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


#ifndef AWL_BACKENDS_WINDOWS_CHOOSE_AND_SET_PIXEL_FORMAT_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_CHOOSE_AND_SET_PIXEL_FORMAT_HPP_INCLUDED

#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/gdi_device_fwd.hpp>
#include <awl/symbol.hpp>

namespace awl
{
namespace backends
{
namespace windows
{

AWL_SYMBOL
void
choose_and_set_pixel_format(
	windows::gdi_device const &,
	DWORD flags,
	BYTE pixel_type,
	BYTE depth,
	BYTE depth_buffer,
	BYTE stencil_buffer
);

}
}
}

#endif
