#ifndef AWL_BACKENDS_SDL_SYSTEM_INIT_HPP_INCLUDED
#define AWL_BACKENDS_SDL_SYSTEM_INIT_HPP_INCLUDED

#include <fcppt/noncopyable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstdint>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace backends
{
namespace sdl
{
namespace system
{

class init
{
	FCPPT_NONCOPYABLE(
		init
	);
public:
	explicit
	init(
		std::uint32_t
	);

	~init();
private:
	std::uint32_t const systems_;
};

}
}
}
}

#endif
