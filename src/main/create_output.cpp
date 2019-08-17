#include <awl/main/create_output.hpp>
#include <awl/main/output.hpp>
#include <awl/main/output_unique_ptr.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr_to_base.hpp>
#include <fcppt/io/ostream_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <filesystem>
#include <fcppt/config/external_end.hpp>
#include <fcppt/config/platform.hpp>
#if defined(FCPPT_CONFIG_WINDOWS_PLATFORM)
#include <awl/backends/windows/main/output.hpp>
#else
#include <awl/main/dummy_output.hpp>
#endif


awl::main::output_unique_ptr
awl::main::create_output(
#if defined(FCPPT_CONFIG_WINDOWS_PLATFORM)
	fcppt::io::ostream &_stream,
	std::filesystem::path const &_path
#else
	fcppt::io::ostream &,
	std::filesystem::path const &
#endif
)
{
	return
		fcppt::unique_ptr_to_base<
			awl::main::output
		>(
#if defined(FCPPT_CONFIG_WINDOWS_PLATFORM)
			fcppt::make_unique_ptr<
				awl::backends::windows::main::output
			>(
				_stream,
				_path
			)
#else
			fcppt::make_unique_ptr<
				awl::main::dummy_output
			>()
#endif
		);
}
