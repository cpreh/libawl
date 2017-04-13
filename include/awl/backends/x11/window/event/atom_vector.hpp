#ifndef AWL_BACKENDS_X11_WINDOW_EVENT_ATOM_VECTOR_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_EVENT_ATOM_VECTOR_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <X11/Xlib.h>
#include <vector>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace window
{
namespace event
{

typedef
std::vector<
	Atom
>
atom_vector;

}
}
}
}
}

#endif
