#ifndef AWL_IMPL_BACKENDS_WAYLAND_MAKE_REGISTRY_OBJECT_HPP_INCLUDED
#define AWL_IMPL_BACKENDS_WAYLAND_MAKE_REGISTRY_OBJECT_HPP_INCLUDED

#include <awl/backends/wayland/registry_object_impl.hpp> // IWYU pragma: keep

#define AWL_IMPL_BACKENDS_WAYLAND_MAKE_REGISTRY_OBJECT(name) \
\
  void awl::backends::wayland::name##_destroy(wl_##name *const _object) \
  { \
    wl_##name##_destroy(_object); \
  } \
\
  template class awl::backends::wayland:: \
      registry_object<wl_##name, wl_##name##_interface, awl::backends::wayland::name##_destroy>

#endif
