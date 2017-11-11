#ifndef AWL_BACKENDS_WAYLAND_REGISTRY_ID_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_REGISTRY_ID_HPP_INCLUDED

#include <fcppt/make_strong_typedef.hpp>
#include <fcppt/strong_typedef.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstdint>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace backends
{
namespace wayland
{

FCPPT_MAKE_STRONG_TYPEDEF(
	std::uint32_t,
	registry_id
);

}
}
}

#endif
