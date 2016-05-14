#ifndef AWL_BACKENDS_WAYLAND_REGISTRY_SET_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_REGISTRY_SET_HPP_INCLUDED

#include <awl/backends/wayland/registry_object_less.hpp>
#include <fcppt/config/external_begin.hpp>
#include <set>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace backends
{
namespace wayland
{

template<
	typename Type
>
using
registry_set
=
std::set<
	Type,
	awl::backends::wayland::registry_object_less<
		Type
	>
>;

}
}
}

#endif
