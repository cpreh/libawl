#include <awl/exception.hpp>
#include <awl/backends/x11/atom.hpp>
#include <awl/backends/x11/display.hpp>
#include <awl/backends/x11/display_ref.hpp>
#include <awl/backends/x11/intern_atom.hpp>
#include <fcppt/text.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xlib.h>
#include <string>
#include <fcppt/config/external_end.hpp>


awl::backends::x11::atom
awl::backends::x11::intern_atom(
	awl::backends::x11::display_ref const _display,
	std::string const &_name
)
{
	Atom const ret(
		::XInternAtom(
			_display.get().get(),
			_name.c_str(),
			True // Create the atom if it does not exist
		)
	);

	// This should not happen
	if(
		ret
		==
		None
	)
	{
		throw
			awl::exception{
				FCPPT_TEXT("XInternAtom() failed!")
			};
	}

	return
		awl::backends::x11::atom(
			ret
		);
}
