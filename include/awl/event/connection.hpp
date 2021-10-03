#ifndef AWL_EVENT_CONNECTION_HPP_INCLUDED
#define AWL_EVENT_CONNECTION_HPP_INCLUDED

#include <awl/detail/symbol.hpp>
#include <awl/event/connection_fwd.hpp>
#include <fcppt/nonmovable.hpp>


namespace awl::event
{

class connection
{
	FCPPT_NONMOVABLE(
		connection
	);
protected:
	connection();
public:
	AWL_DETAIL_SYMBOL
	virtual
	~connection();
};

}

#endif
