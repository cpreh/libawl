#ifndef AWL_BACKENDS_WAYLAND_SYSTEM_EVENT_REMOVE_IMPL_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_SYSTEM_EVENT_REMOVE_IMPL_HPP_INCLUDED

#include <awl/backends/wayland/system/event/remove_decl.hpp>


template<
	typename Type
>
awl::backends::wayland::system::event::remove<
	Type
>::remove(
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
awl::backends::wayland::system::event::remove<
	Type
>::get() const
{
	return
		impl_.get();
}

#endif
