#ifndef AWL_BACKENDS_WAYLAND_MAKE_REGISTRY_OBJECT_FWD_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_MAKE_REGISTRY_OBJECT_FWD_HPP_INCLUDED

#include <awl/backends/wayland/registry_object_fwd.hpp> // IWYU pragma: keep

#define AWL_BACKENDS_WAYLAND_MAKE_REGISTRY_OBJECT_FWD(name) \
  void name##_destroy(wl_##name *); \
\
  using name = awl::backends::wayland:: \
      registry_object<wl_##name, wl_##name##_interface, awl::backends::wayland::name##_destroy>

#endif
