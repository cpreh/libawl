#ifndef AWL_BACKENDS_WAYLAND_SYSTEM_EVENT_ADD_REMOVE_DECL_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_SYSTEM_EVENT_ADD_REMOVE_DECL_HPP_INCLUDED

#include <awl/backends/wayland/system/event/add_remove_fwd.hpp>
#include <awl/backends/wayland/system/event/added.hpp>
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
class add_remove
{
public:
	add_remove(
		Type const &,
		awl::backends::wayland::system::event::added
	);

	AWL_DETAIL_SYMBOL
	awl::backends::wayland::system::event::added
	added() const;

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

	awl::backends::wayland::system::event::added added_;
};

}
}
}
}
}

#endif
