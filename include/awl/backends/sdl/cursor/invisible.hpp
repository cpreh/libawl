#ifndef AWL_BACKENDS_SDL_CURSOR_INVISIBLE_HPP_INCLUDED
#define AWL_BACKENDS_SDL_CURSOR_INVISIBLE_HPP_INCLUDED

#include <awl/backends/sdl/cursor/object.hpp>
#include <awl/detail/class_symbol.hpp>
#include <awl/detail/symbol.hpp>
#include <fcppt/nonmovable.hpp>

namespace awl::backends::sdl::cursor
{

class AWL_DETAIL_CLASS_SYMBOL invisible : public awl::backends::sdl::cursor::object
{
  FCPPT_NONMOVABLE(invisible);

public:
  AWL_DETAIL_SYMBOL
  invisible();

  AWL_DETAIL_SYMBOL
  ~invisible() override;

  [[nodiscard]] AWL_DETAIL_SYMBOL awl::backends::sdl::cursor::object::cursor_ref
  get() const override;
};

}

#endif
