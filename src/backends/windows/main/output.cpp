#include <awl/exception.hpp>
#include <awl/backends/windows/main/output.hpp>
#include <awl/main/output.hpp>
#include <fcppt/char_type.hpp>
#include <fcppt/make_ref.hpp>
#include <fcppt/reference_to_base.hpp>
#include <fcppt/filesystem/ofstream.hpp>
#include <fcppt/filesystem/open_exn.hpp>
#include <fcppt/io/ostream_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <filesystem>
#include <ios>
#include <streambuf>
#include <fcppt/config/external_end.hpp>

awl::backends::windows::main::output::output(
    fcppt::io::ostream &_stream, std::filesystem::path const &_path)
    : awl::main::output(),
      filebuf_(fcppt::filesystem::open_exn<filebuf_type, awl::exception>(
          _path, std::ios_base::openmode{})),
      scoped_rdbuf_(
          fcppt::reference_to_base<std::basic_ios<fcppt::char_type>>(fcppt::make_ref(_stream)),
          fcppt::reference_to_base<std::basic_streambuf<fcppt::char_type>>(
              fcppt::make_ref(filebuf_)))
{
}

awl::backends::windows::main::output::~output() {}
