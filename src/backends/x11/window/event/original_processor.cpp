#include <awl/backends/x11/intern_atom.hpp>
#include <awl/backends/x11/window/original_object.hpp>
#include <awl/backends/x11/window/event/atom_vector.hpp>
#include <awl/backends/x11/window/event/callback.hpp>
#include <awl/backends/x11/window/event/change_mask.hpp>
#include <awl/backends/x11/window/event/filter.hpp>
#include <awl/backends/x11/window/event/mask.hpp>
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
#include <fcppt/assert/optional_error.hpp>
#include <fcppt/assign/make_container.hpp>
#include <fcppt/cast/to_unsigned.hpp>
#include <fcppt/container/find_opt_iterator.hpp>
#include <fcppt/optional/maybe.hpp>
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
	type_counts_(),
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
	fcppt::optional::maybe(
		awl::backends::x11::window::event::to_mask(
			_event_type
		),
		[
			this,
			_event_type
		]{
			++type_counts_[
				_event_type
			];
		},
		[
			this
		](
			awl::backends::x11::window::event::mask const _mask
		)
		{
			mask_count const count(
				++mask_counts_[
					_mask
				]
			);

			if(
				count == 1u
			)
				awl::backends::x11::window::event::change_mask(
					window_,
					event_mask_ |= _mask
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
	if(
		awl::backends::x11::window::event::filter(
			_event,
			window_
		)
	)
		return;

	signals_[
		awl::backends::x11::window::event::type(
			_event.get().type
		)
	](
		_event
	);
}

void
awl::backends::x11::window::event::original_processor::unregister(
	awl::backends::x11::window::event::type const _event_type
)
{
	fcppt::optional::maybe(
		awl::backends::x11::window::event::to_mask(
			_event_type
		),
		[
			this,
			_event_type
		]{
			type_count_map::iterator const it(
				FCPPT_ASSERT_OPTIONAL_ERROR(
					fcppt::container::find_opt_iterator(
						type_counts_,
						_event_type
					)
				)
			);

			if(
				--it->second == 0u
			)
				type_counts_.erase(
					it
				);
		},
		[
			this
		](
			awl::backends::x11::window::event::mask const _old_mask
		)
		{
			mask_count const count(
				--mask_counts_[
					_old_mask
				]
			);

			if(
				count == 0u
			)
				awl::backends::x11::window::event::change_mask(
					window_,
					event_mask_ &= ~(_old_mask)
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
