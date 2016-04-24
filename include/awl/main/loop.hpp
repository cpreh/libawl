#ifndef AWL_MAIN_LOOP_HPP_INCLUDED
#define AWL_MAIN_LOOP_HPP_INCLUDED

#include <awl/detail/symbol.hpp>
#include <awl/main/exit_code.hpp>
#include <awl/main/loop_callback.hpp>
#include <awl/main/loop_process_callback.hpp>


namespace awl
{
namespace main
{

AWL_DETAIL_SYMBOL
awl::main::exit_code
loop(
	awl::main::loop_process_callback const &,
	awl::main::loop_callback const &
);

}
}

#endif
