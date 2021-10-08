#ifndef AWL_BACKENDS_SDL_WINDOW_ORIGINAL_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_SDL_WINDOW_ORIGINAL_OBJECT_HPP_INCLUDED

#include <awl/backends/sdl/cursor/object_fwd.hpp>
#include <awl/backends/sdl/window/holder.hpp>
#include <awl/backends/sdl/window/native_reference.hpp>
#include <awl/backends/sdl/window/object.hpp>
#include <awl/detail/class_symbol.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/visual/object_fwd.hpp>
#include <awl/window/parameters_fwd.hpp>
#include <fcppt/nonmovable.hpp>
#include <fcppt/optional/reference.hpp>

namespace awl::backends::sdl::window
{

class AWL_DETAIL_CLASS_SYMBOL original_object : public awl::backends::sdl::window::object
{
  FCPPT_NONMOVABLE(original_object);

public:
  AWL_DETAIL_SYMBOL
  explicit original_object(awl::window::parameters const &);

  AWL_DETAIL_SYMBOL
  ~original_object() override;

  [[nodiscard]] AWL_DETAIL_SYMBOL awl::backends::sdl::window::native_reference get() const override;

  [[nodiscard]] AWL_DETAIL_SYMBOL awl::visual::object const &visual() const override;

  AWL_DETAIL_SYMBOL
  void set_cursor() override;

private:
  awl::visual::object const &visual_;

  fcppt::optional::reference<awl::backends::sdl::cursor::object const> const cursor_;

  awl::backends::sdl::window::holder const impl_;
};

}

#endif
