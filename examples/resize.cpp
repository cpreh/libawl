#include <awl/event/base.hpp>
#include <awl/main/exit_success.hpp>
#include <awl/main/loop_function.hpp>
#include <awl/main/loop_next.hpp>
#include <awl/system/create.hpp>
#include <awl/system/object.hpp>
#include <awl/system/object_unique_ptr.hpp>
#include <awl/system/event/processor.hpp>
#include <awl/visual/object.hpp>
#include <awl/visual/object_unique_ptr.hpp>
#include <awl/window/object.hpp>
#include <awl/window/object_unique_ptr.hpp>
#include <awl/window/parameters.hpp>
#include <awl/window/event/close.hpp>
#include <awl/window/event/destroy.hpp>
#include <awl/window/event/resize.hpp>
#include <fcppt/exception.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/text.hpp>
#include <fcppt/cast/dynamic_fun.hpp>
#include <fcppt/io/cerr.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/log/context.hpp>
#include <fcppt/log/default_level_streams.hpp>
#include <fcppt/log/level.hpp>
#include <fcppt/log/optional_level.hpp>
#include <fcppt/math/dim/output.hpp>
#include <fcppt/optional/maybe_void.hpp>
#include <fcppt/variant/dynamic_cast.hpp>
#include <fcppt/variant/match.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/vector/vector10.hpp>
#include <cstdlib>
#include <fcppt/config/external_end.hpp>


int
main()
try
{
	fcppt::log::context log_context{
		fcppt::log::optional_level{
			fcppt::log::level::debug
		},
		fcppt::log::default_level_streams()
	};

	awl::system::object_unique_ptr const window_system(
		awl::system::create(
			log_context
		)
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

	awl::system::event::processor &system_processor(
		window_system->processor()
	);

	return
		awl::main::loop_next(
			system_processor,
			awl::main::loop_function{
				[
					&system_processor
				](
					awl::event::base const &_event
				){
					fcppt::optional::maybe_void(
						fcppt::variant::dynamic_cast_<
							boost::mpl::vector3<
								awl::window::event::resize const,
								awl::window::event::close const,
								awl::window::event::destroy const
							>,
							fcppt::cast::dynamic_fun
						>(
							_event
						),
						[
							&system_processor
						](
							auto const &_variant
						)
						{
							fcppt::variant::match(
								_variant,
								[](
									fcppt::reference<
										awl::window::event::resize const
									> const _resize
								)
								{
									fcppt::io::cout()
										<<
										FCPPT_TEXT("Resize: ")
										<<
										_resize.get().dim()
										<<
										FCPPT_TEXT('\n');
								},
								[
									&system_processor
								](
									fcppt::reference<
										awl::window::event::close const
									>
								)
								{
									system_processor.quit(
										awl::main::exit_success()
									);
								},
								[
									&system_processor
								](
									fcppt::reference<
										awl::window::event::destroy const
									>
								)
								{
									system_processor.quit(
										awl::main::exit_success()
									);
								}
							);
						}
					);
				}
			}
		).get();
}
catch(
	fcppt::exception const &_exception
)
{
	fcppt::io::cerr()
		<<
		_exception.string()
		<<
		FCPPT_TEXT('\n');

	return
		EXIT_FAILURE;
}
