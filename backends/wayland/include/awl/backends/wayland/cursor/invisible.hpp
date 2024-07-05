#ifndef AWL_BACKENDS_WAYLAND_CURSOR_INVISIBLE_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_CURSOR_INVISIBLE_HPP_INCLUDED

#include <awl/backends/wayland/cursor/object.hpp>
#include <awl/backends/wayland/cursor/optional_fwd.hpp>
#include <fcppt/nonmovable.hpp>

namespace awl::backends::wayland::cursor
{

class invisible : public awl::backends::wayland::cursor::object
{
  FCPPT_NONMOVABLE(invisible);

public:
  invisible();

  ~invisible() override;

  [[nodiscard]] awl::backends::wayland::cursor::optional get() const override;
};

}

#endif
