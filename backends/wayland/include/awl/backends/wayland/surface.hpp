#ifndef AWL_BACKENDS_WAYLAND_SURFACE_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_SURFACE_HPP_INCLUDED

#include <awl/backends/wayland/compositor_fwd.hpp>
#include <awl/backends/wayland/surface_fwd.hpp>
#include <awl/detail/symbol.hpp>
#include <fcppt/nonmovable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <wayland-client-protocol.h>
#include <fcppt/config/external_end.hpp>

namespace awl::backends::wayland
{

class surface
{
  FCPPT_NONMOVABLE(surface);

public:
  AWL_DETAIL_SYMBOL
  explicit surface(awl::backends::wayland::compositor const &);

  AWL_DETAIL_SYMBOL
  ~surface();

  [[nodiscard]] AWL_DETAIL_SYMBOL wl_surface *get() const;

private:
  wl_surface *impl_;
};

}

#endif
