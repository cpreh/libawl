#ifndef AWL_BACKENDS_WAYLAND_SYSTEM_EVENT_ADD_IMPL_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_SYSTEM_EVENT_ADD_IMPL_HPP_INCLUDED

#include <awl/backends/wayland/system/event/add_decl.hpp>


template<
	typename Type
>
awl::backends::wayland::system::event::add<
	Type
>::add(
	Type const &_ref
)
:
	impl_{
		_ref
	}
{
}

template<
	typename Type
>
Type const &
awl::backends::wayland::system::event::add<
	Type
>::get() const
{
	return
		impl_.get();
}

#endif
