#ifndef AWL_BACKENDS_X11_INTERN_ATOM_HPP_INCLUDED
#define AWL_BACKENDS_X11_INTERN_ATOM_HPP_INCLUDED

#include <awl/backends/x11/atom.hpp>
#include <awl/backends/x11/display_ref.hpp>
#include <awl/detail/symbol.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>

namespace awl::backends::x11
{

AWL_DETAIL_SYMBOL
awl::backends::x11::atom intern_atom(awl::backends::x11::display_ref, std::string const &);

}

#endif
