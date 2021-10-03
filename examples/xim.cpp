#include <awl/exception.hpp>
#include <awl/backends/x11/X.hpp>
#include <awl/backends/x11/Xlib.hpp>
#include <awl/backends/x11/display.hpp>
#include <awl/backends/x11/system/object.hpp>
#include <awl/backends/x11/window/object.hpp>
#include <awl/backends/x11/window/event/generic.hpp>
#include <awl/backends/x11/window/event/mask.hpp>
#include <awl/backends/x11/window/event/object.hpp>
#include <awl/backends/x11/window/event/type.hpp>
#include <awl/event/base.hpp>
#include <awl/event/connection.hpp>
#include <awl/event/connection_unique_ptr.hpp>
#include <awl/main/exit_success.hpp>
#include <awl/main/loop_function.hpp>
#include <awl/main/loop_next.hpp>
#include <awl/system/create.hpp>
#include <awl/system/object.hpp>
#include <awl/system/object_unique_ptr.hpp>
#include <awl/system/event/processor.hpp>
#include <awl/visual/object.hpp>
#include <awl/visual/object_unique_ptr.hpp>
#include <awl/window/dim.hpp>
#include <awl/window/object.hpp>
#include <awl/window/object_unique_ptr.hpp>
#include <awl/window/parameters.hpp>
#include <awl/window/event/close.hpp>
#include <awl/window/event/destroy.hpp>
#include <fcppt/exception.hpp>
#include <fcppt/make_ref.hpp>
#include <fcppt/nonmovable.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/text.hpp>
#include <fcppt/assert/optional_error.hpp>
#include <fcppt/cast/dynamic.hpp>
#include <fcppt/cast/dynamic_fun.hpp>
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
#include <fcppt/mpl/list/object.hpp>
#include <fcppt/optional/maybe_void.hpp>
#include <fcppt/optional/to_exception.hpp>
#include <fcppt/variant/dynamic_cast.hpp>
#include <fcppt/variant/match.hpp>
#include <fcppt/config/external_begin.hpp>
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
			fcppt::make_ref(
				log_context
			)
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
		fcppt::optional::to_exception(
			fcppt::cast::dynamic<
				awl::backends::x11::system::object
			>(
				*awl_system
			),
			[]{
				return
					awl::exception{
						FCPPT_TEXT("The X11 example can only be used with the X11 backend.")
					};
			}
		).get()
	};

	Display *const dpy{
		x11_system.display().get().get()
	};

	if(
		XSupportsLocale()
		==
		0
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
	{
		std::cerr
			<<
			"Warning: cannot set locale modifiers.\n";
	}

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
					400U,
					100U
				}
			)
		)
	};

	awl::backends::x11::window::object &x11_window{
		FCPPT_ASSERT_OPTIONAL_ERROR(
			fcppt::cast::dynamic<
				awl::backends::x11::window::object
			>(
				*awl_window
			)
		).get()
	};

	Window const win{
		x11_window.get()
	};

	class xim_wrapper
	{
		FCPPT_NONMOVABLE(
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
			{
				throw
					std::runtime_error{
						"Cannot open input method"
					};
			}
		}

		~xim_wrapper()
		{
			XCloseIM(
				impl_
			);
		}

		[[nodiscard]]
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

	XIM im{
		xim.get()
	};

	class xic_wrapper
	{
		FCPPT_NONMOVABLE(
			xic_wrapper
		);
	public:
		xic_wrapper(
			XIM _xim,
			Window const _win
		)
		:
			impl_{
				// NOLINTNEXTLINE(cppcoreguidelines-pro-type-vararg,hicpp-vararg)
				XCreateIC(
					_xim,
					XNInputStyle,
					XIMStatusNothing | XIMPreeditNothing, // NOLINT(hicpp-signed-bitwise)
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
			{
				throw
					std::runtime_error{
						"XCreateIC failed"
					};
			}
		}

		~xic_wrapper()
		{
			XDestroyIC(
				impl_
			);
		}

		[[nodiscard]]
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

	XIC ic{
		xic.get()
	};

	awl::event::connection_unique_ptr const mask_connection{
		x11_window.add_event_mask(
			[
				ic
			]{
				// NOLINTNEXTLINE(google-runtime-int)
				long im_event_mask{
					0L
				};

				// NOLINTNEXTLINE(cppcoreguidelines-pro-type-vararg,hicpp-vararg)
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
		)
	};

	XSetICFocus(
		ic
	);

	awl::event::connection_unique_ptr const key_connection{
		x11_window.register_event(
			awl::backends::x11::window::event::type{
				KeyPress
			}
		)
	};

	auto const key_press_function(
		[
			ic
		](
			awl::backends::x11::window::event::object const &_event
		)
		{
			XKeyEvent event{
				_event.get().xkey
			};

			using
			buffer_type
			=
			fcppt::container::buffer::object<
				char
			>;

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
					KeySym keysym{};

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
						0U
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
			default:
				break;
			}
		}
	);

	awl_window->show();

	awl::system::event::processor &system_processor(
		awl_system->processor()
	);

	return
		awl::main::loop_next(
			system_processor,
			awl::main::loop_function{
				[
					&key_press_function,
					&system_processor
				](
					awl::event::base const &_event
				){
					fcppt::optional::maybe_void(
						fcppt::variant::dynamic_cast_<
							fcppt::mpl::list::object<
								awl::backends::x11::window::event::generic const,
								awl::window::event::close const,
								awl::window::event::destroy const
							>,
							fcppt::cast::dynamic_fun
						>(
							_event
						),
						[
							&key_press_function,
							&system_processor
						](
							auto const &_variant
						)
						{
							fcppt::variant::match(
								_variant,
								[
									&key_press_function
								](
									fcppt::reference<
										awl::backends::x11::window::event::generic const
									> const _generic
								)
								{
									awl::backends::x11::window::event::object const &x11_event{
										_generic.get().event()
									};

									if(
										x11_event.get().type
										==
										KeyPress
									)
									{
										key_press_function(
											x11_event
										);
									}
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
