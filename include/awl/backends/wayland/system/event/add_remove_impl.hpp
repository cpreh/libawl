#ifndef AWL_BACKENDS_WAYLAND_SYSTEM_EVENT_ADD_REMOVE_IMPL_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_SYSTEM_EVENT_ADD_REMOVE_IMPL_HPP_INCLUDED

#include <awl/backends/wayland/system/event/add_remove_decl.hpp>
#include <awl/backends/wayland/system/event/added.hpp>


template<
	typename Type
>
awl::backends::wayland::system::event::add_remove<
	Type
>::add_remove(
	Type const &_ref,
	awl::backends::wayland::system::event::added const _added
)
:
	impl_{
		_ref
	},
	added_{
		_added
	}
{
}

template<
	typename Type
>
awl::backends::wayland::system::event::added
awl::backends::wayland::system::event::add_remove<
	Type
>::added() const
{
	return
		added_;
}

template<
	typename Type
>
Type const &
awl::backends::wayland::system::event::add_remove<
	Type
>::get() const
{
	return
		impl_.get();
}


#endif
