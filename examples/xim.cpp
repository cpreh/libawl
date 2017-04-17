#include <awl/backends/x11/display.hpp>
#include <awl/backends/x11/system/object.hpp>
#include <awl/backends/x11/window/object.hpp>
#include <awl/backends/x11/window/event/callback.hpp>
#include <awl/backends/x11/window/event/mask.hpp>
#include <awl/backends/x11/window/event/object.hpp>
#include <awl/backends/x11/window/event/processor.hpp>
#include <awl/backends/x11/window/event/scoped_mask.hpp>
#include <awl/backends/x11/window/event/type.hpp>
#include <awl/main/exit_success.hpp>
#include <awl/main/loop_callback.hpp>
#include <awl/main/loop_next.hpp>
#include <awl/system/object_unique_ptr.hpp>
#include <awl/system/create.hpp>
#include <awl/system/object.hpp>
#include <awl/system/event/processor.hpp>
#include <awl/visual/object.hpp>
#include <awl/visual/object_unique_ptr.hpp>
#include <awl/window/dim.hpp>
#include <awl/window/object.hpp>
#include <awl/window/object_unique_ptr.hpp>
#include <awl/window/parameters.hpp>
#include <awl/window/event/destroy_fwd.hpp>
#include <awl/window/event/destroy_callback.hpp>
#include <awl/window/event/processor.hpp>
#include <fcppt/exception.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/text.hpp>
#include <fcppt/cast/dynamic_cross_exn.hpp>
#include <fcppt/cast/dynamic_exn.hpp>
#include <fcppt/cast/size.hpp>
#include <fcppt/cast/to_signed.hpp>
#include <fcppt/cast/to_unsigned.hpp>
#include <fcppt/container/buffer/object.hpp>
#include <fcppt/container/buffer/read_from.hpp>
#include <fcppt/io/cerr.hpp>
#include <fcppt/log/context.hpp>
#include <fcppt/log/default_level_streams.hpp>
#include <fcppt/log/level.hpp>
#include <fcppt/log/optional_level.hpp>
#include <fcppt/signal/auto_connection.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xlib.h>
#include <clocale>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <string>
#include <fcppt/config/external_end.hpp>


int
main(
	int,
	char *[]
)
try
{
	fcppt::log::context log_context{
		fcppt::log::optional_level{
			fcppt::log::level::debug
		},
		fcppt::log::default_level_streams()
	};

	awl::system::object_unique_ptr const awl_system{
		awl::system::create(
			log_context
		)
	};

	if(
		std::setlocale(LC_ALL, "")
		==
		nullptr
	)
	{
		std::cerr
			<<
			"Cannot set locale\n";
		return
			EXIT_FAILURE;
	}

	awl::backends::x11::system::object &x11_system{
		fcppt::cast::dynamic_exn<
			awl::backends::x11::system::object &
		>(
			*awl_system
		)
	};

	Display *const dpy{
		x11_system.display().get()
	};

	if(
		!XSupportsLocale()
	)
	{
		std::cerr
			<<
			"X does not support locale \""
			<<
			std::setlocale(LC_ALL, nullptr)
			<<
			"\"\n";

		return
			EXIT_FAILURE;
	}

	if(
		XSetLocaleModifiers("")
		==
		nullptr
	)
		std::cerr
			<<
			"Warning: cannot set locale modifiers.\n";

	awl::visual::object_unique_ptr const visual{
		awl_system->default_visual()
	};

	awl::window::object_unique_ptr const awl_window{
		awl_system->create_window(
			awl::window::parameters{
				*visual
			}
			.size(
				awl::window::dim{
					400u,
					100u
				}
			)
		)
	};

	Window const win{
		fcppt::cast::dynamic_cross_exn<
			awl::backends::x11::window::object &
		>(
			*awl_window
		).get()
	};

	class xim_wrapper
	{
		FCPPT_NONCOPYABLE(
			xim_wrapper
		);
	public:
		explicit
		xim_wrapper(
			Display *const _display
		)
		:
			impl_{
				XOpenIM(
					_display,
					nullptr,
					nullptr,
					nullptr
				)
			}
		{
			if(
				impl_
				==
				nullptr
			)
				throw
					std::runtime_error{
						"Cannot open input method"
					};
		}

		~xim_wrapper()
		{
			XCloseIM(
				impl_
			);
		}

		XIM
		get() const
		{
			return
				impl_;
		}
	private:
		XIM impl_;
	};

	xim_wrapper xim{
		dpy
	};

	XIM const im{
		xim.get()
	};

	class xic_wrapper
	{
		FCPPT_NONCOPYABLE(
			xic_wrapper
		);
	public:
		xic_wrapper(
			XIM const _xim,
			Window const _win
		)
		:
			impl_{
				XCreateIC(
					_xim,
					XNInputStyle,
					XIMStatusNothing | XIMPreeditNothing,
					XNClientWindow,
					_win,
					nullptr
				)
			}
		{
			if(
				impl_
				==
				nullptr
			)
				throw
					std::runtime_error{
						"XCreateIC failed"
					};
		}

		~xic_wrapper()
		{
			XDestroyIC(
				impl_
			);
		}

		XIC
		get() const
		{
			return
				impl_;
		}
	private:
		XIC impl_;
	};

	xic_wrapper xic{
		im,
		win
	};

	XIC const ic{
		xic.get()
	};

	awl::backends::x11::window::event::processor &x11_window_processor{
		fcppt::cast::dynamic_exn<
			awl::backends::x11::window::event::processor &
		>(
			awl_window->processor()
		)
	};

	awl::backends::x11::window::event::scoped_mask const scoped_mask{
		x11_window_processor,
		[
			ic
		]{
			long im_event_mask{
				0l
			};

			XGetICValues(
				ic,
				XNFilterEvents,
				&im_event_mask,
				nullptr
			);

			return
				awl::backends::x11::window::event::mask{
					im_event_mask
				};
		}()
	};

	XSetICFocus(
		ic
	);

	awl_window->show();

	fcppt::signal::auto_connection const key_connection{
		x11_window_processor.register_callback(
			awl::backends::x11::window::event::type{
				KeyPress
			},
			awl::backends::x11::window::event::callback{
				[
					ic
				](
					awl::backends::x11::window::event::object const &_event
				)
				{
					XKeyEvent event{
						_event.get().xkey
					};

					typedef
					fcppt::container::buffer::object<
						char
					>
					buffer_type;

					Status status{
						0
					};

					auto const lookup(
						[
							ic,
							&event,
							&status
						](
							buffer_type::pointer const _data,
							buffer_type::size_type const _size
						){
							KeySym keysym;

							return
								fcppt::cast::to_unsigned(
									XmbLookupString(
										ic,
										&event,
										_data,
										fcppt::cast::size<
											int
										>(
											fcppt::cast::to_signed(
												_size
											)
										),
										&keysym,
										&status
									)
								);
						}
					);

					buffer_type const buffer{
						fcppt::container::buffer::read_from<
							buffer_type
						>(
							lookup(
								nullptr,
								0u
							),
							lookup
						)
					};

					switch(
						status
					)
					{
					case XLookupNone:
					case XLookupKeySym:
						break;
					case XLookupBoth:
					case XLookupChars:
						std::cout
							<<
							std::string(
								buffer.begin(),
								buffer.end()
							)
							<<
							'\n';
						break;
					}
				}
			}
		)
	};

	fcppt::signal::auto_connection const destroy_connection{
		awl_window->processor().destroy_callback(
			awl::window::event::destroy_callback{
				[
					&awl_system
				](
					awl::window::event::destroy const &
				)
				{
					awl_system->processor().quit(
						awl::main::exit_success()
					);
				}
			}
		)
	};

	return
		awl::main::loop_next(
			awl_system->processor(),
			awl::main::loop_callback{
				[]{}
			}
		).get();
}
catch(
	fcppt::exception const &_error
)
{
	fcppt::io::cerr()
		<<
		_error.string()
		<<
		FCPPT_TEXT('\n');

	return
		EXIT_FAILURE;
}
catch(
	std::exception const &_error
)
{
	std::cerr
		<<
		_error.what()
		<<
		'\n';

	return
		EXIT_FAILURE;
}
