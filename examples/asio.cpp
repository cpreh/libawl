#include <awl/mainloop/dispatcher_ptr.hpp>
#include <awl/mainloop/asio/io_service.hpp>
#include <awl/mainloop/asio/io_service_ptr.hpp>
#include <awl/mainloop/asio/create_io_service.hpp>
#include <awl/mainloop/dispatcher.hpp>
#include <awl/system/create.hpp>
#include <awl/system/object.hpp>
#include <awl/system/object_ptr.hpp>
#include <awl/window/dim.hpp>
#include <awl/window/instance.hpp>
#include <awl/window/instance_ptr.hpp>
#include <awl/window/parameters.hpp>
#include <awl/window/event/create_processor.hpp>
#include <awl/window/event/processor_ptr.hpp>
#include <awl/window/event/processor.hpp>
#include <fcppt/tr1/functional.hpp>
#include <boost/asio/deadline_timer.hpp>
#include <boost/asio/impl/src.hpp>
#include <boost/date_time/posix_time/posix_time_duration.hpp>

int main()
{
	awl::system::object_ptr const window_system(
		awl::system::create()
	);

	awl::window::instance_ptr const window(
		window_system->create(
			awl::window::parameters()
			.size(
				awl::window::dim(
					1024,
					768
				)
			)
		)
	);
	
	window->show();

	awl::window::event::processor_ptr const processor(
		awl::window::event::create_processor(
			window
		)
	);

	awl::mainloop::asio::io_service_ptr const io_service(
		awl::mainloop::asio::create_io_service()
	);

	awl::mainloop::dispatcher_ptr const dispatcher(
		io_service->create_dispatcher(
			window_system,
			std::tr1::bind(
				&awl::window::event::processor::dispatch,
				processor
			)
		)
	);

	boost::asio::deadline_timer timer(
		io_service->get()
	);

	timer.expires_from_now(
		boost::posix_time::seconds(
			1
		)
	);

	timer.async_wait(
		std::tr1::bind(
			&awl::mainloop::dispatcher::stop,
			dispatcher
		)
	);

	io_service->run();
}