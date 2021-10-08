#ifndef AWL_MAIN_DUMMY_OUTPUT_HPP_INCLUDED
#define AWL_MAIN_DUMMY_OUTPUT_HPP_INCLUDED

#include <awl/detail/symbol.hpp>
#include <awl/main/output.hpp>
#include <fcppt/nonmovable.hpp>

namespace awl::main
{

class dummy_output : public awl::main::output
{
  FCPPT_NONMOVABLE(dummy_output);

public:
  AWL_DETAIL_SYMBOL
  dummy_output();

  AWL_DETAIL_SYMBOL
  ~dummy_output() override;
};

}

#endif
