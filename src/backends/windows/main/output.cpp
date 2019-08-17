#include <awl/exception.hpp>
#include <awl/backends/windows/main/output.hpp>
#include <awl/main/output.hpp>
#include <fcppt/filesystem/ofstream.hpp>
#include <fcppt/filesystem/open_exn.hpp>
#include <fcppt/io/ostream_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <filesystem>
#include <ios>
#include <fcppt/config/external_end.hpp>


awl::backends::windows::main::output::output(
	fcppt::io::ostream &_stream,
	std::filesystem::path const &_path
)
:
	awl::main::output(),
	stream_(
		fcppt::filesystem::open_exn<
			fcppt::filesystem::ofstream,
			awl::exception
		>(
			_path,
			std::ios_base::openmode{}
		)
	),
	scoped_rdbuf_(
		stream_,
		_stream
	)
{
}

awl::backends::windows::main::output::~output()
{
}
