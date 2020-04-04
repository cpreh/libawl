#include <awl/exception.hpp>
#include <awl/backends/sdl/exception.hpp>
#include <awl/backends/sdl/get_error.hpp>
#include <fcppt/from_std_string.hpp>
#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <utility>
#include <fcppt/config/external_end.hpp>


awl::backends::sdl::exception::exception(
	fcppt::string &&_error
)
:
	awl::exception{
		FCPPT_TEXT("SDL error: ")
		+
		std::move(
			_error
		)
		+
		FCPPT_TEXT(", error code: ")
		+
		fcppt::optional::maybe(
			awl::backends::sdl::get_error(),
			[]{
				return
					fcppt::string{
						FCPPT_TEXT("No error")
					};
			},
			[](
				std::string &&_message
			)
			{
				return
					fcppt::from_std_string(
						std::move(
							_message
						)
					);
			}
		)
	}
{
}

awl::backends::sdl::exception::exception(
	exception const &
)
= default;

awl::backends::sdl::exception::exception(
	exception &&
)
noexcept
= default;

awl::backends::sdl::exception &
awl::backends::sdl::exception::operator=(
	exception const &
)
= default;

awl::backends::sdl::exception &
awl::backends::sdl::exception::operator=(
	exception &&
)
noexcept
= default;

awl::backends::sdl::exception::~exception()
noexcept
= default;
