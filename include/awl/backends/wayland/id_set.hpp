#ifndef AWL_BACKENDS_WAYLAND_ID_SET_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_ID_SET_HPP_INCLUDED

#include <awl/backends/wayland/id_less.hpp>
#include <fcppt/shared_ptr_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <set>
#include <fcppt/config/external_end.hpp>

namespace awl::backends::wayland
{

template <typename Type>
using id_set = std::set<fcppt::shared_ptr<Type>, awl::backends::wayland::id_less<Type>>;

}

#endif
