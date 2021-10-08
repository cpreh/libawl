#include <awl/main/create_output.hpp>
#include <awl/main/output.hpp>
#include <awl/main/scoped_output.hpp>
#include <fcppt/io/ostream_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <filesystem>
#include <fcppt/config/external_end.hpp>

awl::main::scoped_output::scoped_output(
    fcppt::io::ostream &_stream, std::filesystem::path const &_path)
    : impl_(awl::main::create_output(_stream, _path))
{
}

awl::main::scoped_output::~scoped_output() = default;
