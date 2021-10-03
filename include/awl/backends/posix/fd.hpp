#ifndef AWL_BACKENDS_POSIX_FD_HPP_INCLUDED
#define AWL_BACKENDS_POSIX_FD_HPP_INCLUDED

#include <fcppt/make_strong_typedef.hpp>
#include <fcppt/strong_typedef.hpp>


namespace awl::backends::posix
{

FCPPT_MAKE_STRONG_TYPEDEF(
	int,
	fd
);

}

#endif
