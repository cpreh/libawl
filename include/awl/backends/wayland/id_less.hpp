#ifndef AWL_BACKENDS_WAYLAND_ID_LESS_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_ID_LESS_HPP_INCLUDED

#include <awl/backends/wayland/registry_id.hpp>
#include <fcppt/shared_ptr_impl.hpp>
#include <fcppt/strong_typedef_comparison.hpp> // IWYU pragma: keep

namespace awl::backends::wayland
{

template <typename Type>
struct id_less
{
  using is_transparent = void;

  using impl = fcppt::shared_ptr<Type>;

  bool operator()(impl const &_left, awl::backends::wayland::registry_id const _right) const
  {
    return _left->name() < _right;
  }

  bool operator()(awl::backends::wayland::registry_id const _left, impl const &_right) const
  {
    return _left < _right->name();
  }

  bool operator()(impl const &_left, impl const &_right) const
  {
    return _left->name() < _right->name();
  }
};

}

#endif
