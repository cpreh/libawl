#include <awl/backends/x11/intern_atom.hpp>
#include <awl/backends/x11/window/original_object.hpp>
#include <awl/backends/x11/window/event/atom_vector.hpp>
#include <awl/backends/x11/window/event/callback.hpp>
#include <awl/backends/x11/window/event/change_mask.hpp>
#include <awl/backends/x11/window/event/mask.hpp>
#include <awl/backends/x11/window/event/mask_bit.hpp>
#include <awl/backends/x11/window/event/mask_callback.hpp>
#include <awl/backends/x11/window/event/mask_for_each.hpp>
#include <awl/backends/x11/window/event/object.hpp>
#include <awl/backends/x11/window/event/original_processor.hpp>
#include <awl/backends/x11/window/event/to_mask.hpp>
#include <awl/backends/x11/window/event/type.hpp>
#include <awl/window/dim.hpp>
#include <awl/window/event/close.hpp>
#include <awl/window/event/close_callback.hpp>
#include <awl/window/event/destroy.hpp>
#include <awl/window/event/destroy_callback.hpp>
#include <awl/window/event/hide.hpp>
#include <awl/window/event/hide_callback.hpp>
#include <awl/window/event/resize.hpp>
#include <awl/window/event/resize_callback.hpp>
#include <awl/window/event/show.hpp>
#include <awl/window/event/show_callback.hpp>
#include <fcppt/assign/make_container.hpp>
#include <fcppt/cast/to_unsigned.hpp>
#include <fcppt/optional/maybe_void.hpp>
#include <fcppt/signal/auto_connection.hpp>
#include <fcppt/signal/auto_connection_container.hpp>
#include <fcppt/signal/object_impl.hpp>
#include <fcppt/signal/unregister/base_impl.hpp>
#include <fcppt/signal/unregister/function.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/X.h>
#include <X11/Xlib.h>
#include <functional>
#include <fcppt/config/external_end.hpp>


awl::backends::x11::window::event::original_processor::original_processor(
	awl::backends::x11::window::original_object &_window
)
:
	window_(
		_window
	),
	signals_(),
	mask_counts_(),
	event_mask_{
		0l
	},
	wm_protocols_atom_(
		awl::backends::x11::intern_atom(
			_window.display(),
			"WM_PROTOCOLS"
		)
	),
	wm_delete_window_atom_(
		awl::backends::x11::intern_atom(
			_window.display(),
			"WM_DELETE_WINDOW"
		)
	),
	wm_protocols_(
		_window,
		awl::backends::x11::window::event::atom_vector{
			wm_delete_window_atom_.get()
		}
	),
	close_signal_(
		awl::window::event::close_signal::combiner_function{
			[](
				bool const _arg1,
				bool const _arg2
			)
			{
				return
					_arg1
					&&
					_arg2;
			}
		},
		awl::window::event::close_signal::initial_value{
			true
		}
	),
	destroy_signal_(),
	hide_signal_(),
	resize_signal_(),
	show_signal_(),
	connections_(
		fcppt::assign::make_container<
			fcppt::signal::auto_connection_container
		>(
			this->register_callback(
				awl::backends::x11::window::event::type(
					ClientMessage
				),
				awl::backends::x11::window::event::callback{
					std::bind(
						&awl::backends::x11::window::event::original_processor::on_client_message,
						this,
						std::placeholders::_1
					)
				}
			),
			this->register_callback(
				awl::backends::x11::window::event::type(
					ConfigureNotify
				),
				awl::backends::x11::window::event::callback{
					std::bind(
						&awl::backends::x11::window::event::original_processor::on_configure,
						this,
						std::placeholders::_1
					)
				}
			),
			this->register_callback(
				awl::backends::x11::window::event::type(
					DestroyNotify
				),
				awl::backends::x11::window::event::callback{
					std::bind(
						&awl::backends::x11::window::event::original_processor::on_destroy,
						this,
						std::placeholders::_1
					)
				}
			),
			this->register_callback(
				awl::backends::x11::window::event::type(
					MapNotify
				),
				awl::backends::x11::window::event::callback{
					std::bind(
						&awl::backends::x11::window::event::original_processor::on_map,
						this,
						std::placeholders::_1
					)
				}
			),
			this->register_callback(
				awl::backends::x11::window::event::type(
					UnmapNotify
				),
				awl::backends::x11::window::event::callback{
					std::bind(
						&awl::backends::x11::window::event::original_processor::on_unmap,
						this,
						std::placeholders::_1
					)
				}
			)
		)
	)
{
}

awl::backends::x11::window::event::original_processor::~original_processor()
{
}

fcppt::signal::auto_connection
awl::backends::x11::window::event::original_processor::close_callback(
	awl::window::event::close_callback const &_callback
)
{
	return
		close_signal_.connect(
			_callback
		);
}

fcppt::signal::auto_connection
awl::backends::x11::window::event::original_processor::destroy_callback(
	awl::window::event::destroy_callback const &_callback
)
{
	return
		destroy_signal_.connect(
			_callback
		);
}

fcppt::signal::auto_connection
awl::backends::x11::window::event::original_processor::hide_callback(
	awl::window::event::hide_callback const &_callback
)
{
	return
		hide_signal_.connect(
			_callback
		);
}

fcppt::signal::auto_connection
awl::backends::x11::window::event::original_processor::resize_callback(
	awl::window::event::resize_callback const &_callback
)
{
	return
		resize_signal_.connect(
			_callback
		);
}

fcppt::signal::auto_connection
awl::backends::x11::window::event::original_processor::show_callback(
	awl::window::event::show_callback const &_callback
)
{
	return
		show_signal_.connect(
			_callback
		);
}

fcppt::signal::auto_connection
awl::backends::x11::window::event::original_processor::register_callback(
	awl::backends::x11::window::event::type const _event_type,
	awl::backends::x11::window::event::callback const &_callback
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
		signals_[
			_event_type
		].connect(
			_callback,
			fcppt::signal::unregister::function{
				std::bind(
					&awl::backends::x11::window::event::original_processor::unregister,
					this,
					_event_type
				)
			}
		);
}

void
awl::backends::x11::window::event::original_processor::process(
	awl::backends::x11::window::event::object const &_event
)
{
	signals_[
		awl::backends::x11::window::event::type(
			_event.get().type
		)
	](
		_event
	);
}

void
awl::backends::x11::window::event::original_processor::add_event_mask(
	awl::backends::x11::window::event::mask const _mask
)
{
	awl::backends::x11::window::event::mask_for_each(
		_mask,
		awl::backends::x11::window::event::mask_callback{
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
}

void
awl::backends::x11::window::event::original_processor::remove_event_mask(
	awl::backends::x11::window::event::mask const _mask
)
{
	awl::backends::x11::window::event::mask_for_each(
		_mask,
		awl::backends::x11::window::event::mask_callback{
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
awl::backends::x11::window::event::original_processor::add_mask_bit(
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
			window_,
			event_mask_
		);
	};
}

void
awl::backends::x11::window::event::original_processor::remove_mask_bit(
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
			window_,
			event_mask_
		);
	}
}

void
awl::backends::x11::window::event::original_processor::unregister(
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
awl::backends::x11::window::event::original_processor::on_client_message(
	awl::backends::x11::window::event::object const &_event
)
{
	XClientMessageEvent const request(
		_event.get().xclient
	);

	if(
		request.message_type
		!=
		wm_protocols_atom_.get()
	)
		return;
	if(
		static_cast<
			Atom
		>(
			request.data.l[0]
		)
		!=
		wm_delete_window_atom_.get()
	)
		return;

	if(
		close_signal_(
			awl::window::event::close()
		)
	)
	{
		window_.destroy();

		destroy_signal_(
			awl::window::event::destroy()
		);
	}
}

void
awl::backends::x11::window::event::original_processor::on_configure(
	awl::backends::x11::window::event::object const &_event
)
{
	XConfigureEvent const request(
		_event.get().xconfigure
	);

	resize_signal_(
		awl::window::event::resize(
			awl::window::dim(
				fcppt::cast::to_unsigned(
					request.width
				),
				fcppt::cast::to_unsigned(
					request.height
				)
			)
		)
	);
}

void
awl::backends::x11::window::event::original_processor::on_destroy(
	awl::backends::x11::window::event::object const &
)
{
	destroy_signal_(
		awl::window::event::destroy()
	);
}

void
awl::backends::x11::window::event::original_processor::on_map(
	awl::backends::x11::window::event::object const &
)
{
	show_signal_(
		awl::window::event::show()
	);
}

void
awl::backends::x11::window::event::original_processor::on_unmap(
	awl::backends::x11::window::event::object const &
)
{
	hide_signal_(
		awl::window::event::hide()
	);
}
