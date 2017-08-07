#ifndef AWL_EVENT_CONNECTION_HPP_INCLUDED
#define AWL_EVENT_CONNECTION_HPP_INCLUDED

#include <awl/event/connection_fwd.hpp>
#include <awl/detail/symbol.hpp>
#include <fcppt/noncopyable.hpp>


namespace awl
{
namespace event
{

class connection
{
	FCPPT_NONCOPYABLE(
		connection
	);
protected:
	connection();
public:
	AWL_DETAIL_SYMBOL
	virtual
	~connection() = 0;
};

}
}

#endif
