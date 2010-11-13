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


#include <sge/windows/wndclass_pool.hpp>
#include <sge/windows/wndclass.hpp>
#include <fcppt/make_shared_ptr.hpp>
#include <fcppt/weak_ptr.hpp>
#include <map>

// TODO: we have to somehow free the weak_ptrs

namespace
{

typedef fcppt::weak_ptr<
	awl::backends::windows::wndclass
> wndclass_weak_ptr;

typedef std::map<
	fcppt::string,
	wndclass_weak_ptr
> wndclass_map;

wndclass_map wndclasses;

}

awl::backends::windows::wndclass_ptr const
awl::backends::windows::wndclass_pool(
	fcppt::string const &name,
	WNDPROC const proc
)
{
	wndclass_weak_ptr &ptr(
		wndclasses[name]
	);

	{
		wndclass_ptr const ref(
			ptr.lock()
		);

		if(ref)
			return ref;
	}

	wndclass_ptr const nref(
		fcppt::make_shared_ptr<
			wndclass
		>(
			name,
			proc
		)
	);

	ptr = nref;

	return nref;
}
