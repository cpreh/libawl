#include <awl/event/create_processor.hpp>
#include <awl/event/processor.hpp>
#include <awl/event/processor_unique_ptr.hpp>
#include <awl/event/scoped_window_processor.hpp>
#include <awl/system/create.hpp>
#include <awl/system/object.hpp>
#include <awl/system/object_unique_ptr.hpp>
#include <awl/system/event/optional_processor_ref.hpp>
#include <awl/visual/object.hpp>
#include <awl/visual/object_unique_ptr.hpp>
#include <awl/window/object.hpp>
#include <awl/window/object_unique_ptr.hpp>
#include <awl/window/parameters.hpp>
#include <awl/window/event/create_processor.hpp>
#include <awl/window/event/destroy_callback.hpp>
#include <awl/window/event/processor.hpp>
#include <awl/window/event/processor_unique_ptr.hpp>
#include <awl/window/event/resize.hpp>
#include <awl/window/event/resize_callback.hpp>
#include <fcppt/exception.hpp>
#include <fcppt/text.hpp>
#include <fcppt/io/cerr.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/math/dim/output.hpp>
#include <fcppt/signal/auto_connection.hpp>
#include <fcppt/signal/scoped_connection.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstdlib>
#include <fcppt/config/external_end.hpp>


namespace
{

}

int
main()
try
{
	awl::system::object_unique_ptr const window_system(
		awl::system::create()
	);

	awl::visual::object_unique_ptr const visual(
		window_system->default_visual()
	);

	awl::window::object_unique_ptr const window(
		window_system->create_window(
			awl::window::parameters(
				*visual
			)
			.title(
				FCPPT_TEXT("awltest")
			)
			.class_name(
				FCPPT_TEXT("awltest")
			)
			.size(
				awl::window::dim(
					1024u,
					768u
				)
			)
		)
	);

	window->show();

	awl::event::processor_unique_ptr const processor(
		awl::event::create_processor(
			*window_system,
			awl::system::event::optional_processor_ref()
		)
	);

	awl::window::event::processor_unique_ptr const window_processor(
		awl::window::event::create_processor(
			*window
		)
	);

	awl::event::scoped_window_processor const scoped_window_processor(
		*processor,
		*window_processor
	);

	fcppt::signal::scoped_connection const resize_connection(
		window_processor->resize_callback(
			awl::window::event::resize_callback(
				[](
					awl::window::event::resize const &_size
				)
				{
					fcppt::io::cout()
						<< FCPPT_TEXT("Resize: ")
						<< _size.dim()
						<< FCPPT_TEXT('\n');
				}
			)
		)
	);

	bool running(
		true
	);

	fcppt::signal::scoped_connection const destroy_connection(
		window_processor->destroy_callback(
			awl::window::event::destroy_callback(
				[
					&running
				](
					awl::window::event::destroy const &
				){
					running =
						false;
				}
			)
		)
	);

	while(
		running
	)
		processor->next();

	return
		EXIT_SUCCESS;
}
catch(
	fcppt::exception const &_exception
)
{
	fcppt::io::cerr()
		<< _exception.string()
		<< FCPPT_TEXT('\n');

	return
		EXIT_FAILURE;
}
