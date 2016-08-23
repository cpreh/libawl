#ifndef AWL_MAIN_CREATE_OUTPUT_HPP_INCLUDED
#define AWL_MAIN_CREATE_OUTPUT_HPP_INCLUDED

#include <awl/detail/symbol.hpp>
#include <awl/main/output_unique_ptr.hpp>
#include <fcppt/io/ostream_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/filesystem/path.hpp>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace main
{

AWL_DETAIL_SYMBOL
awl::main::output_unique_ptr
create_output(
	fcppt::io::ostream &,
	boost::filesystem::path const &
);

}
}

#endif
