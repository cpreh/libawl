#ifndef AWL_BACKENDS_SDL_SYSTEM_EVENT_ORIGINAL_PROCESSOR_HPP_INCLUDED
#define AWL_BACKENDS_SDL_SYSTEM_EVENT_ORIGINAL_PROCESSOR_HPP_INCLUDED

#include <awl/backends/sdl/system/event/processor.hpp>
#include <awl/backends/sdl/system/event/type.hpp>
#include <awl/event/container.hpp>
#include <awl/detail/class_symbol.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/main/exit_code_fwd.hpp>
#include <awl/system/event/result_fwd.hpp>
#include <awl/timer/setting_fwd.hpp>
#include <awl/timer/unique_ptr.hpp>
#include <fcppt/noncopyable.hpp>


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
	awl::backends::sdl::system::event::type const timer_event_;
};

}
}
}
}
}

#endif
