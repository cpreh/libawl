#include <awl/event/concrete_connection.hpp>
#include <awl/event/connection.hpp>
#include <awl/event/connection_function.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


awl::event::concrete_connection::concrete_connection(
	awl::event::connection_function &&_function
)
:
	awl::event::connection(),
	function_{
		std::move(
			_function
		)
	}
{
}

awl::event::concrete_connection::~concrete_connection()
{
	function_();
}
