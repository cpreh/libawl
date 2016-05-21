#ifndef AWL_BACKENDS_POSIX_FD_HPP_INCLUDED
#define AWL_BACKENDS_POSIX_FD_HPP_INCLUDED

#include <fcppt/strong_typedef.hpp>


namespace awl
{
namespace backends
{
namespace posix
{

FCPPT_MAKE_STRONG_TYPEDEF(
	int,
	fd
);

}
}
}

#endif
