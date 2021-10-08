#ifndef AWL_BACKENDS_WAYLAND_REGISTRY_OBJECT_IMPL_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_REGISTRY_OBJECT_IMPL_HPP_INCLUDED

#include <awl/exception.hpp>
#include <awl/backends/wayland/registry_id.hpp>
#include <awl/backends/wayland/registry_object_decl.hpp>
#include <fcppt/text.hpp>
#include <fcppt/cast/from_void_ptr.hpp>
#include <fcppt/config/external_begin.hpp>
#include <wayland-client-protocol.h>
#include <wayland-util.h>
#include <utility>
#include <fcppt/config/external_end.hpp>

template <typename Type, wl_interface const &Interface, void (&Destroy)(Type *)>
awl::backends::wayland::registry_object<Type, Interface, Destroy>::registry_object(
    wl_registry *const _registry, awl::backends::wayland::registry_id const _id)
    : value_{fcppt::cast::from_void_ptr<Type *>(
          ::wl_registry_bind(_registry, _id.get(), &Interface, 1U))},
      name_{_id}
{
  if (value_ == nullptr)
  {
    throw awl::exception{FCPPT_TEXT("wl_registry_bind failed")};
  }
}

template <typename Type, wl_interface const &Interface, void (&Destroy)(Type *)>
awl::backends::wayland::registry_object<Type, Interface, Destroy>::registry_object(
    registry_object &&_other) noexcept
    : value_{_other.value_}, name_{_other.name_}
{
  _other.value_ = nullptr;
}

template <typename Type, wl_interface const &Interface, void (&Destroy)(Type *)>
awl::backends::wayland::registry_object<Type, Interface, Destroy> &
awl::backends::wayland::registry_object<Type, Interface, Destroy>::operator=(
    registry_object &&_other) noexcept
{
  std::swap(value_, _other.value_);

  name_ = _other.name_;

  return *this;
}

namespace awl::backends::wayland
{
template <typename Type, wl_interface const &Interface, void (&Destroy)(Type *)>
registry_object<Type, Interface, Destroy>::~registry_object()
{
  if (value_ != nullptr)
  {
    Destroy(value_);
  }
}
}

template <typename Type, wl_interface const &Interface, void (&Destroy)(Type *)>
Type *awl::backends::wayland::registry_object<Type, Interface, Destroy>::get() const
{
  return value_;
}

template <typename Type, wl_interface const &Interface, void (&Destroy)(Type *)>
awl::backends::wayland::registry_id
awl::backends::wayland::registry_object<Type, Interface, Destroy>::name() const
{
  return name_;
}

#endif
