#include <awl/exception.hpp>
#include <fcppt/string.hpp>
#include <fcppt/assert/information_fwd.hpp>
#include <fcppt/assert/make_message.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


awl::exception::exception(
	fcppt::string &&_string
)
:
	fcppt::exception(
		std::move(
			_string
		)
	)
{
}

awl::exception::exception(
	fcppt::assert_::information const &_info
)
:
	fcppt::exception(
		fcppt::assert_::make_message(
			_info
		)
	)
{
}

awl::exception::~exception() noexcept
{
}
