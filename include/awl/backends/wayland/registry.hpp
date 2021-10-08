#ifndef AWL_BACKENDS_WAYLAND_REGISTRY_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_REGISTRY_HPP_INCLUDED

#include <awl/backends/wayland/display_fwd.hpp>
#include <awl/backends/wayland/registry_fwd.hpp>
#include <awl/detail/symbol.hpp>
#include <fcppt/nonmovable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <wayland-client-protocol.h>
#include <fcppt/config/external_end.hpp>

namespace awl::backends::wayland
{

class registry
{
  FCPPT_NONMOVABLE(registry);

public:
  AWL_DETAIL_SYMBOL
  explicit registry(awl::backends::wayland::display const &);

  AWL_DETAIL_SYMBOL
  ~registry();

  [[nodiscard]] AWL_DETAIL_SYMBOL wl_registry *get() const;

private:
  wl_registry *ptr_;
};

}

#endif
