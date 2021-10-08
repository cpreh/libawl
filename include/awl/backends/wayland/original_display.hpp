#ifndef AWL_BACKENDS_WAYLAND_ORIGINAL_DISPLAY_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_ORIGINAL_DISPLAY_HPP_INCLUDED

#include <awl/backends/wayland/display.hpp>
#include <awl/detail/symbol.hpp>
#include <fcppt/nonmovable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <wayland-client-core.h>
#include <fcppt/config/external_end.hpp>

namespace awl::backends::wayland
{

class original_display : public awl::backends::wayland::display
{
  FCPPT_NONMOVABLE(original_display);

public:
  AWL_DETAIL_SYMBOL
  original_display();

  [[nodiscard]] AWL_DETAIL_SYMBOL wl_display *get() const override;

  AWL_DETAIL_SYMBOL
  ~original_display() override;

private:
  wl_display *const ptr_;
};

}

#endif
