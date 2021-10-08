#ifndef AWL_BACKENDS_X11_WINDOW_ATOMS_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_ATOMS_HPP_INCLUDED

#include <awl/backends/x11/X.hpp>
#include <awl/backends/x11/window/atom_count.hpp>
#include <awl/backends/x11/window/atoms_fwd.hpp>
#include <awl/detail/symbol.hpp>

namespace awl::backends::x11::window
{

class atoms
{
public:
  AWL_DETAIL_SYMBOL
  atoms(Atom const *, awl::backends::x11::window::atom_count);

  [[nodiscard]] AWL_DETAIL_SYMBOL Atom const *get() const;

  [[nodiscard]] AWL_DETAIL_SYMBOL awl::backends::x11::window::atom_count count() const;

private:
  Atom const *atoms_;

  awl::backends::x11::window::atom_count count_;
};

}

#endif
