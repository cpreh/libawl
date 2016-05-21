#ifndef AWL_BACKENDS_POSIX_POSTED_HPP_INCLUDED
#define AWL_BACKENDS_POSIX_POSTED_HPP_INCLUDED

#include <awl/class_symbol.hpp>
#include <awl/backends/posix/posted_fwd.hpp>
#include <awl/detail/symbol.hpp>
#include <fcppt/noncopyable.hpp>


namespace awl
{
namespace backends
{
namespace posix
{

class AWL_CLASS_SYMBOL posted
{
	FCPPT_NONCOPYABLE(
		posted
	);
protected:
	AWL_DETAIL_SYMBOL
	posted();
public:
	AWL_DETAIL_SYMBOL
	virtual
	~posted() = 0;
};

}
}
}

#endif
