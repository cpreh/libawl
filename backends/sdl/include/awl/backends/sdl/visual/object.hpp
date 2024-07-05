#ifndef AWL_BACKENDS_SDL_VISUAL_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_SDL_VISUAL_OBJECT_HPP_INCLUDED

#include <awl/backends/sdl/visual/flags.hpp>
#include <awl/backends/sdl/visual/object_fwd.hpp>
#include <awl/detail/class_symbol.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/visual/object.hpp>
#include <fcppt/nonmovable.hpp>

namespace awl::backends::sdl::visual
{

class AWL_DETAIL_CLASS_SYMBOL object : public awl::visual::object
{
  FCPPT_NONMOVABLE(object);

public:
  AWL_DETAIL_SYMBOL
  explicit object(awl::backends::sdl::visual::flags);

  AWL_DETAIL_SYMBOL
  ~object() override;

  [[nodiscard]] AWL_DETAIL_SYMBOL awl::backends::sdl::visual::flags flags() const;

  AWL_DETAIL_SYMBOL
  virtual void apply() const;

private:
  awl::backends::sdl::visual::flags const flags_;
};

}

#endif
