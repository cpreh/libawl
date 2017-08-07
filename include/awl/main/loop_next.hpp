#ifndef AWL_MAIN_LOOP_NEXT_HPP_INCLUDED
#define AWL_MAIN_LOOP_NEXT_HPP_INCLUDED

#include <awl/detail/symbol.hpp>
#include <awl/main/exit_code.hpp>
#include <awl/main/loop_function.hpp>
#include <awl/system/event/processor_fwd.hpp>


namespace awl
{
namespace main
{

AWL_DETAIL_SYMBOL
awl::main::exit_code
loop_next(
	awl::system::event::processor &,
	awl::main::loop_function const &
);

}
}

#endif
