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


#ifndef AWL_MAINLOOP_ASIO_IO_SERVICE_HPP_INCLUDED
#define AWL_MAINLOOP_ASIO_IO_SERVICE_HPP_INCLUDED

#include <awl/mainloop/io_service.hpp>
#include <awl/mainloop/dispatcher_callback.hpp>
#include <awl/event/processor_ptr.hpp>
#include <awl/class_symbol.hpp>
#include <awl/symbol.hpp>
#include <boost/asio/io_service.hpp>
#include <fcppt/noncopyable.hpp>

namespace awl
{
namespace mainloop
{
namespace asio
{

class AWL_CLASS_SYMBOL io_service
:
	public mainloop::io_service
{
	FCPPT_NONCOPYABLE(io_service)
public:
	AWL_SYMBOL
	io_service();

	AWL_SYMBOL
	~io_service();

	AWL_SYMBOL
	boost::asio::io_service &
	get();
private:
	void
	run_one();

	void
	run();

	void
	poll();

	void
	stop();

	void
	reset();

	void
	post(
		dispatcher_callback const &
	);

	dispatcher_ptr const
	create_dispatcher(
		event::processor_ptr,
		dispatcher_callback const &
	);

	boost::asio::io_service io_service_;
};

}
}
}

#endif
