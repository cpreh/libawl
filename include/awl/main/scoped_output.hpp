#ifndef AWL_MAIN_SCOPED_OUTPUT_HPP_INCLUDED
#define AWL_MAIN_SCOPED_OUTPUT_HPP_INCLUDED

#include <awl/detail/symbol.hpp>
#include <awl/main/output_fwd.hpp>
#include <awl/main/scoped_output_fwd.hpp>
#include <fcppt/nonmovable.hpp>
#include <fcppt/unique_ptr_impl.hpp>
#include <fcppt/io/ostream_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <filesystem>
#include <fcppt/config/external_end.hpp>

namespace awl::main
{

class scoped_output
{
  FCPPT_NONMOVABLE(scoped_output);

public:
  AWL_DETAIL_SYMBOL
  scoped_output(fcppt::io::ostream &, std::filesystem::path const &);

  AWL_DETAIL_SYMBOL
  ~scoped_output();

private:
  fcppt::unique_ptr<awl::main::output> const impl_;
};

}

#endif
