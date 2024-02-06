#include <awl/system/create.hpp>
#include <awl/system/object.hpp> // NOLINT(misc-include-cleaner)
#include <awl/system/object_unique_ptr.hpp>
#include <awl/visual/object.hpp> // NOLINT(misc-include-cleaner)
#include <awl/visual/object_unique_ptr.hpp>
#include <awl/window/dim.hpp>
#include <awl/window/object.hpp> // NOLINT(misc-include-cleaner)
#include <awl/window/object_unique_ptr.hpp>
#include <awl/window/parameters.hpp>
#include <fcppt/exception.hpp>
#include <fcppt/make_ref.hpp>
#include <fcppt/text.hpp>
#include <fcppt/io/cerr.hpp>
#include <fcppt/log/context.hpp>
#include <fcppt/log/default_level_streams.hpp>
#include <fcppt/log/level.hpp>
#include <fcppt/log/optional_level.hpp>
#include <fcppt/config/external_begin.hpp>
#include <chrono>
#include <cstdlib>
#include <thread>
#include <fcppt/config/external_end.hpp>

int main()
try
{
  fcppt::log::context log_context{
      fcppt::log::optional_level{fcppt::log::level::debug}, fcppt::log::default_level_streams()};

  awl::system::object_unique_ptr const window_system(
      awl::system::create(fcppt::make_ref(log_context)));

  awl::visual::object_unique_ptr const visual(window_system->default_visual());

  awl::window::object_unique_ptr const window(
      window_system->create_window(awl::window::parameters(*visual)
                                       .class_name(FCPPT_TEXT("awltest"))
                                       .size(awl::window::dim(1024U, 768U))));

  window->show();

  std::this_thread::sleep_for(
      // NOLINTNEXTLINE(fuchsia-default-arguments-calls)
      std::chrono::seconds(1));

  return EXIT_SUCCESS;
}
catch (fcppt::exception const &_exception)
{
  fcppt::io::cerr() << _exception.string() << FCPPT_TEXT('\n');

  return EXIT_FAILURE;
}
