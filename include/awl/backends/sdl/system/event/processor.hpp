#ifndef AWL_BACKENDS_SDL_SYSTEM_EVENT_PROCESSOR_HPP_INCLUDED
#define AWL_BACKENDS_SDL_SYSTEM_EVENT_PROCESSOR_HPP_INCLUDED

#include <awl/backends/sdl/system/event/processor_fwd.hpp>
#include <awl/detail/class_symbol.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/system/event/processor.hpp>
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

class AWL_DETAIL_CLASS_SYMBOL processor
:
	public awl::system::event::processor
{
	FCPPT_NONCOPYABLE(
		processor
	);
protected:
	AWL_DETAIL_SYMBOL
	processor();
public:
	AWL_DETAIL_SYMBOL
	~processor()
	override;
};

}
}
}
}
}

#endif
