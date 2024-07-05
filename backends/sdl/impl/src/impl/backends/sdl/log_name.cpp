#include <awl/impl/backends/sdl/log_name.hpp>
#include <fcppt/text.hpp>
#include <fcppt/log/name.hpp>

fcppt::log::name awl::impl::backends::sdl::log_name()
{
  return fcppt::log::name{FCPPT_TEXT("sdl")};
}
