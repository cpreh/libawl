#ifndef AWL_BACKENDS_WAYLAND_MAKE_REGISTRY_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_MAKE_REGISTRY_OBJECT_HPP_INCLUDED

#include <awl/backends/wayland/registry_object_decl.hpp> // IWYU pragma: keep
#include <awl/detail/export_class_instantiation.hpp>

#define AWL_BACKENDS_WAYLAND_MAKE_REGISTRY_OBJECT(name) \
  extern template class AWL_DETAIL_EXPORT_CLASS_INSTANTIATION awl::backends::wayland:: \
      registry_object<wl_##name, wl_##name##_interface, awl::backends::wayland::name##_destroy>

#endif
