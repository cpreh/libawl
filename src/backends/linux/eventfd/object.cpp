/*
spacegameengine is a portable easy to use game engine written in C++.
Copyright (C) 2006-2016 Carl Philipp Reh (carlphilippreh <at> gmail.com)

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


#include <awl/exception.hpp>
#include <awl/backends/linux/eventfd/object.hpp>
#include <awl/backends/posix/fd.hpp>
#include <fcppt/text.hpp>
#include <fcppt/assert/error.hpp>
#include <fcppt/config/external_begin.hpp>
#include <sys/eventfd.h>
#include <cstdint>
#include <unistd.h>
#include <fcppt/config/external_end.hpp>


namespace
{

typedef std::uint64_t value_type;

value_type const value(
	1u
);

}

awl::backends::linux::eventfd::object::object()
:
	fd_(
		::eventfd(
			0u,
			0
		)
	)
{
	if(
		fd_.get()
		==
		-1
	)
		throw
			awl::exception{
				FCPPT_TEXT("eventfd failed")
			};
}

awl::backends::linux::eventfd::object::~object()
{
	::close(
		fd_.get()
	);
}

awl::backends::posix::fd
awl::backends::linux::eventfd::object::get() const
{
	return
		fd_;
}

void
awl::backends::linux::eventfd::object::write()
{
	FCPPT_ASSERT_ERROR(
		::write(
			fd_.get(),
			&value,
			sizeof(
				value_type
			)
		)
		==
		static_cast<
			ssize_t
		>(
			sizeof(
				value_type
			)
		)
	);
}

void
awl::backends::linux::eventfd::object::read()
{
	value_type ret;

	FCPPT_ASSERT_ERROR(
		::read(
			fd_.get(),
			&ret,
			sizeof(
				value_type
			)
		)
		==
		static_cast<
			ssize_t
		>(
			sizeof(
				value_type
			)
		)
	);

	FCPPT_ASSERT_ERROR(
		ret
		==
		value
	);
}
