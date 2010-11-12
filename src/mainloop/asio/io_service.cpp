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


#include <awl/mainloop/asio/io_service.hpp>
#include <fcppt/function/object.hpp>
#include <fcppt/config.hpp>
#ifdef FCPPT_POSIX_PLATFORM
#include <awl/mainloop/asio/dispatcher.hpp>
#include <fcppt/tr1/functional.hpp>
#include <fcppt/make_shared_ptr.hpp>
#endif

awl::mainloop::asio::io_service::io_service()
:
	io_service_()
{}

awl::mainloop::asio::io_service::~io_service()
{
}

boost::asio::io_service &
awl::mainloop::asio::io_service::get()
{
	return io_service_;
}

void
awl::mainloop::asio::io_service::run_one()
{
	io_service_.run_one();
}

void
awl::mainloop::asio::io_service::run()
{
	io_service_.run();
}

void
awl::mainloop::asio::io_service::poll()
{
	io_service_.poll();
}

void
awl::mainloop::asio::io_service::stop()
{
	io_service_.stop();
}

void
awl::mainloop::asio::io_service::reset()
{
	io_service_.reset();
}

void
awl::mainloop::asio::io_service::post(
	dispatcher_callback const &_callback
)
{
	io_service_.post(
		_callback
	);
}

awl::mainloop::dispatcher_ptr const
awl::mainloop::asio::io_service::create_dispatcher(
	native_handle const _handle,
	dispatcher_callback const &_callback
)
{
#ifdef FCPPT_POSIX_PLATFORM
	return
		fcppt::make_shared_ptr<
			asio::dispatcher
		>(
			std::tr1::ref(
				io_service_
			),
			_handle,
			_callback
		);
#else
	return dispatcher_ptr();
#endif
}
