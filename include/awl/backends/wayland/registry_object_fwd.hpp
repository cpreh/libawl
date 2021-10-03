#ifndef AWL_BACKENDS_WAYLAND_REGISTRY_OBJECT_FWD_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_REGISTRY_OBJECT_FWD_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <wayland-util.h>
#include <fcppt/config/external_end.hpp>


namespace awl::backends::wayland
{

template<
	typename Type,
	wl_interface const &Interface,
	void (&Destroy)(Type *)
>
class registry_object;

}

#endif
