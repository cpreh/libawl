#ifndef AWL_BACKENDS_WAYLAND_SYSTEM_EVENT_REGISTRY_SET_DECL_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_SYSTEM_EVENT_REGISTRY_SET_DECL_HPP_INCLUDED

#include <awl/backends/wayland/registry_id.hpp>
#include <awl/backends/wayland/registry_set.hpp>
#include <awl/backends/wayland/system/event/add_remove_fwd.hpp>
#include <awl/backends/wayland/system/event/registry_set_fwd.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/signal/object_decl.hpp>


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
class registry_set
{
	FCPPT_NONCOPYABLE(
		registry_set
	);
public:
	registry_set();

	registry_set(
		registry_set &&
	);

	registry_set &
	operator=(
		registry_set &&
	);

	~registry_set();

	typedef
	awl::backends::wayland::registry_set<
		Type
	>
	set_type;

	void
	add(
		Type &&
	);

	void
	remove(
		awl::backends::wayland::registry_id
	);

	typedef
	awl::backends::wayland::system::event::add_remove<
		Type
	>
	event_type;

	typedef
	void
	function_type(
		event_type const &
	);

	typedef
	fcppt::signal::object<
		function_type
	>
	signal_type;

	set_type const &
	get() const;

	signal_type &
	signal();
private:
	set_type impl_;

	signal_type signal_;
};

}
}
}
}
}

#endif
