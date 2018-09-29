#include <awl/exception.hpp>
#include <awl/backends/x11/Xlib.hpp>
#include <awl/backends/x11/display.hpp>
#include <awl/backends/x11/screen.hpp>
#include <awl/backends/x11/cursor/object.hpp>
#include <awl/backends/x11/system/event/original_processor.hpp>
#include <awl/backends/x11/visual/object.hpp>
#include <awl/backends/x11/window/class_hint.hpp>
#include <awl/backends/x11/window/const_optional_class_hint_ref.hpp>
#include <awl/backends/x11/window/create.hpp>
#include <awl/backends/x11/window/get_geometry.hpp>
#include <awl/backends/x11/window/object.hpp>
#include <awl/backends/x11/window/original_class_hint.hpp>
#include <awl/backends/x11/window/original_object.hpp>
#include <awl/backends/x11/window/rect.hpp>
#include <awl/backends/x11/window/event/atom_vector.hpp>
#include <awl/backends/x11/window/event/change_mask.hpp>
#include <awl/backends/x11/window/event/mask.hpp>
#include <awl/backends/x11/window/event/mask_bit.hpp>
#include <awl/backends/x11/window/event/mask_for_each.hpp>
#include <awl/backends/x11/window/event/mask_function.hpp>
#include <awl/backends/x11/window/event/object.hpp>
#include <awl/backends/x11/window/event/to_mask.hpp>
#include <awl/backends/x11/window/event/type.hpp>
#include <awl/event/connection_function.hpp>
#include <awl/event/connection_unique_ptr.hpp>
#include <awl/event/make_connection.hpp>
#include <awl/visual/object.hpp>
#include <awl/window/object.hpp>
#include <awl/window/parameters.hpp>
#include <fcppt/make_cref.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/to_std_string.hpp>
#include <fcppt/cast/static_downcast.hpp>
#include <fcppt/optional/apply.hpp>
#include <fcppt/optional/map.hpp>
#include <fcppt/optional/maybe_void.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/optional/static_cast.hpp>
#include <fcppt/optional/to_exception.hpp>


awl::backends::x11::window::original_object::original_object(
	awl::backends::x11::display &_display,
	awl::backends::x11::screen const _screen,
	awl::backends::x11::system::event::original_processor &_system_processor,
	awl::window::parameters const &_params
)
:
	awl::backends::x11::window::object(),
	display_(
		_display
	),
	screen_(
		_screen
	),
	visual_(
		fcppt::cast::static_downcast<
			awl::backends::x11::visual::object const &
		>(
			_params.visual()
		)
	),
	colormap_(
		display_,
		_screen,
		visual_
	),
	hints_(),
	class_hint_{
		fcppt::optional::apply(
			[](
				fcppt::string const &_title,
				fcppt::string const &_class_name
			){
				return
					fcppt::make_unique_ptr<
						awl::backends::x11::window::original_class_hint
					>(
						awl::backends::x11::window::class_hint{
							awl::backends::x11::window::class_hint::res_name_type{
								fcppt::optional::to_exception(
									fcppt::to_std_string(
										_title
									),
									[
										&_title
									]{
										return
											awl::exception{
												FCPPT_TEXT("Failed to convert window title: ")
												+
												_title
											};
									}
								)
							},
							awl::backends::x11::window::class_hint::res_class_type{
								fcppt::optional::to_exception(
									fcppt::to_std_string(
										_class_name
									),
									[
										&_class_name
									]{
										return
											awl::exception{
												FCPPT_TEXT("Failed to convert class name: ")
												+
												_class_name
											};
									}
								)
							}
						}
					);
			},
			_params.title(),
			_params.class_name()
		)
	},
	window_(
		display_,
		awl::backends::x11::window::create(
			_params.size(),
			display_,
			screen_,
			colormap_,
			visual_,
			fcppt::optional::static_cast_<
				awl::backends::x11::cursor::object const
			>(
				_params.cursor()
			)
		)
	),
	processor_connection_{
		_system_processor.add_window(
			*this
		)
	},
	mask_counts_(),
	event_mask_{
		0l
	},
	wm_protocols_(
		*this,
		awl::backends::x11::window::event::atom_vector{
			_system_processor.delete_window_atom().get()
		}
	),
	client_message_connection_{
		this->register_event(
			awl::backends::x11::window::event::type(
				ClientMessage
			)
		)
	},
	configure_connection_{
		this->register_event(
			awl::backends::x11::window::event::type(
				ConfigureNotify
			)
		)
	},
	destroy_connection_{
		this->register_event(
			awl::backends::x11::window::event::type(
				DestroyNotify
			)
		)
	},
	map_connection_{
		this->register_event(
			awl::backends::x11::window::event::type(
				MapNotify
			)
		)
	},
	unmap_connection_{
		this->register_event(
			awl::backends::x11::window::event::type(
				UnmapNotify
			)
		)
	}
{
	// always returns 1
	::XSetWMHints(
		display_.get(),
		window_.get(),
		hints_.get()
	);

	fcppt::optional::maybe_void(
		class_hint_,
		[
			this
		](
			original_class_hint_unique_ptr const &_class_hint
		)
		{
			// always returns 1
			::XSetClassHint(
				display_.get(),
				window_.get(),
				_class_hint->get()
			);
		}
	);

	fcppt::optional::maybe_void(
		_params.title(),
		[
			this
		](
			fcppt::string const &_title
		)
		{
			// always returns 1
			::XStoreName(
				display_.get(),
				window_.get(),
				fcppt::optional::to_exception(
					fcppt::to_std_string(
						_title
					),
					[
						&_title
					]{
						return
							awl::exception{
								FCPPT_TEXT("Failed to convert windows title: ")
								+
								_title
							};
					}
				).c_str()
			);
		}
	);
}

awl::backends::x11::window::original_object::~original_object()
{
}

bool
awl::backends::x11::window::original_object::destroyed() const
{
	return
		window_.destroyed();
}

awl::backends::x11::display &
awl::backends::x11::window::original_object::display() const
{
	return
		display_;
}

awl::backends::x11::screen
awl::backends::x11::window::original_object::screen() const
{
	return
		screen_;
}

awl::backends::x11::visual::object const &
awl::backends::x11::window::original_object::x11_visual() const
{
	return
		visual_;
}

awl::backends::x11::window::rect
awl::backends::x11::window::original_object::rect() const
{
	return
		awl::backends::x11::window::get_geometry(
			*this
		);
}

Window
awl::backends::x11::window::original_object::get() const
{
	return
		window_.get();
}

awl::backends::x11::window::const_optional_class_hint_ref
awl::backends::x11::window::original_object::class_hint() const
{
	return
		fcppt::optional::map(
			class_hint_,
			[](
				original_class_hint_unique_ptr const &_class_hint
			)
			{
				return
					fcppt::make_cref(
						_class_hint->hint()
					);
			}
		);
}

void
awl::backends::x11::window::original_object::destroy()
{
	window_.destroy();
}

awl::event::connection_unique_ptr
awl::backends::x11::window::original_object::register_event(
	awl::backends::x11::window::event::type const _event_type
)
{
	fcppt::optional::maybe_void(
		awl::backends::x11::window::event::to_mask(
			_event_type
		),
		[
			this
		](
			awl::backends::x11::window::event::mask_bit const _mask
		)
		{
			this->add_mask_bit(
				_mask
			);
		}
	);

	return
		awl::event::make_connection(
			awl::event::connection_function{
				[
					this,
					_event_type
				]{
					this->unregister_event(
						_event_type
					);
				}
			}
		);
}

awl::event::connection_unique_ptr
awl::backends::x11::window::original_object::add_event_mask(
	awl::backends::x11::window::event::mask const _mask
)
{
	awl::backends::x11::window::event::mask_for_each(
		_mask,
		awl::backends::x11::window::event::mask_function{
			[
				this
			](
				awl::backends::x11::window::event::mask_bit const _mask_bit
			)
			{
				this->add_mask_bit(
					_mask_bit
				);
			}
		}
	);

	return
		awl::event::make_connection(
			awl::event::connection_function{
				[
					this,
					_mask
				]{
					return
						this->remove_event_mask(
							_mask
						);
				}
			}
		);
}

void
awl::backends::x11::window::original_object::unregister_event(
	awl::backends::x11::window::event::type const _event_type
)
{
	fcppt::optional::maybe_void(
		awl::backends::x11::window::event::to_mask(
			_event_type
		),
		[
			this
		](
			awl::backends::x11::window::event::mask_bit const _old_mask
		)
		{
			this->remove_mask_bit(
				_old_mask
			);
		}
	);
}

void
awl::backends::x11::window::original_object::remove_event_mask(
	awl::backends::x11::window::event::mask const _mask
)
{
	awl::backends::x11::window::event::mask_for_each(
		_mask,
		awl::backends::x11::window::event::mask_function{
			[
				this
			](
				awl::backends::x11::window::event::mask_bit const _mask_bit
			)
			{
				this->remove_mask_bit(
					_mask_bit
				);
			}
		}
	);
}

void
awl::backends::x11::window::original_object::add_mask_bit(
	awl::backends::x11::window::event::mask_bit const _mask_bit
)
{
	mask_count const count(
		++mask_counts_[
			_mask_bit
		]
	);

	if(
		count
		==
		1u
	)
	{
		event_mask_ |=
			awl::backends::x11::window::event::mask{
				_mask_bit.get()
			};

		awl::backends::x11::window::event::change_mask(
			*this,
			event_mask_
		);
	};
}

void
awl::backends::x11::window::original_object::remove_mask_bit(
	awl::backends::x11::window::event::mask_bit const _mask_bit
)
{
	mask_count const count(
		--mask_counts_[
			_mask_bit
		]
	);

	if(
		count
		==
		0u
	)
	{
		event_mask_ &=
			~(
				awl::backends::x11::window::event::mask{
					_mask_bit.get()
				}
			);

		awl::backends::x11::window::event::change_mask(
			*this,
			event_mask_
		);
	}
}
