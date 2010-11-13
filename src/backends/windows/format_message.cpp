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


#include <sge/windows/format_message.hpp>
#include <sge/windows/windows.hpp>
#include <sge/exception.hpp>
#include <fcppt/tr1/array.hpp>
#include <fcppt/text.hpp>
#include <fcppt/char_type.hpp>

fcppt::string const
awl::backends::windows::format_message(
	DWORD const error)
{
	std::tr1::array<
		fcppt::char_type,
		1024
	> errmsg;

	if(FormatMessage(
		FORMAT_MESSAGE_FROM_SYSTEM,
		0, // ignored
		error, // message id
		0, // language id
		errmsg.data(),
		errmsg.size()-1,
		0
	) == 0)
		throw exception(
			FCPPT_TEXT("FormatMessage() failed!"));
	return fcppt::string(
		errmsg.data()
	);
}
