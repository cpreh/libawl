#ifndef AWL_BACKENDS_SDL_SYSTEM_EVENT_ORIGINAL_PROCESSOR_HPP_INCLUDED
#define AWL_BACKENDS_SDL_SYSTEM_EVENT_ORIGINAL_PROCESSOR_HPP_INCLUDED

#include <awl/backends/sdl/system/event/processor.hpp>
#include <awl/backends/sdl/system/event/timer_type.hpp>
#include <awl/detail/class_symbol.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/event/base_unique_ptr.hpp>
#include <awl/event/container.hpp>
#include <awl/main/exit_code_fwd.hpp>
#include <awl/main/optional_exit_code.hpp>
#include <awl/system/event/result_fwd.hpp>
#include <awl/timer/setting_fwd.hpp>
#include <awl/timer/unique_ptr.hpp>
#include <fcppt/function_fwd.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <SDL_events.h>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace backends
{
namespace sdl
{
namespace system
{
namespace event
{

class AWL_DETAIL_CLASS_SYMBOL original_processor
:
	public awl::backends::sdl::system::event::processor
{
	FCPPT_NONCOPYABLE(
		original_processor
	);
public:
	AWL_DETAIL_SYMBOL
	original_processor();

	AWL_DETAIL_SYMBOL
	~original_processor()
	override;

	AWL_DETAIL_SYMBOL
	awl::system::event::result
	poll()
	override;

	AWL_DETAIL_SYMBOL
	awl::system::event::result
	next()
	override;

	AWL_DETAIL_SYMBOL
	void
	quit(
		awl::main::exit_code
	)
	override;

	AWL_DETAIL_SYMBOL
	awl::timer::unique_ptr
	create_timer(
		awl::timer::setting const &
	)
	override;
private:
	typedef
	fcppt::function<
		awl::event::container ()
	>
	process_function;

	awl::system::event::result
	process(
		process_function const &
	);

	awl::event::container
	process_events();

	awl::event::base_unique_ptr
	translate(
		SDL_Event const &
	) const;

	awl::backends::sdl::system::event::timer_type const timer_event_;

	awl::main::optional_exit_code exit_code_;
};

}
}
}
}
}

#endif
