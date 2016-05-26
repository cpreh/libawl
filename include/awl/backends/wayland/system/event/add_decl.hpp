#ifndef AWL_BACKENDS_WAYLAND_SYSTEM_EVENT_ADD_DECL_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_SYSTEM_EVENT_ADD_DECL_HPP_INCLUDED

#include <awl/backends/wayland/system/event/add_fwd.hpp>
#include <awl/detail/symbol.hpp>
#include <fcppt/reference_impl.hpp>


namespace awl
{
namespace backends
{
namespace wayland
{
namespace system
{
namespace event
{

template<
	typename Type
>
class add
{
public:
	explicit
	add(
		Type const &
	);

	AWL_DETAIL_SYMBOL
	Type const &
	get() const;
private:
	typedef
	fcppt::reference<
		Type const
	>
	ref;

	ref impl_;
};

}
}
}
}
}

#endif
