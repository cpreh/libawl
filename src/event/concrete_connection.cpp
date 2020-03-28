#include <awl/event/concrete_connection.hpp>
#include <awl/event/connection.hpp>
#include <awl/event/connection_function.hpp>
#include <fcppt/exception.hpp>
#include <fcppt/text.hpp>
#include <fcppt/io/cerr.hpp>
#include <fcppt/config/external_begin.hpp>
#include <exception>
#include <iostream>
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
	// TODO(philipp): Use fcppt::log.
	try
	{
		function_();
	}
	catch(
		fcppt::exception const &_error
	)
	{
		fcppt::io::cerr()
			<<
			_error.string()
			<<
			FCPPT_TEXT('\n');
	}
	catch(
		std::exception const &_error
	)
	{
		std::cerr
			<<
			_error.what()
			<<
			'\n';
	}
	catch(
		...
	)
	{
		std::cerr
			<<
			"Unknown error in ~concrete_connection\n";
	}
}
