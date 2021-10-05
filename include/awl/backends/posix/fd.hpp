#ifndef AWL_BACKENDS_POSIX_FD_HPP_INCLUDED
#define AWL_BACKENDS_POSIX_FD_HPP_INCLUDED

#include <fcppt/declare_strong_typedef.hpp>
#include <fcppt/strong_typedef.hpp>


namespace awl::backends::posix
{

FCPPT_DECLARE_STRONG_TYPEDEF(
	int,
	fd
);

}

#endif
