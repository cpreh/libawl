#ifndef AWL_BACKENDS_WAYLAND_SYSTEM_EVENT_SET_DECL_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_SYSTEM_EVENT_SET_DECL_HPP_INCLUDED

#include <awl/backends/wayland/id_set.hpp>
#include <awl/backends/wayland/registry_id.hpp>
#include <awl/backends/wayland/system/event/add_fwd.hpp>
#include <awl/backends/wayland/system/event/remove_fwd.hpp>
#include <awl/backends/wayland/system/event/set_fwd.hpp>
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
class set
{
	FCPPT_NONCOPYABLE(
		set
	);
public:
	set();

	set(
		set &&
	);

	set &
	operator=(
		set &&
	);

	~set();

	typedef
	awl::backends::wayland::id_set<
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
	awl::backends::wayland::system::event::add<
		Type
	>
	add_event;

	typedef
	void
	add_function(
		add_event const &
	);

	typedef
	fcppt::signal::object<
		add_function
	>
	add_signal_type;

	typedef
	awl::backends::wayland::system::event::remove<
		Type
	>
	remove_event;

	typedef
	void
	remove_function(
		remove_event const &
	);

	typedef
	fcppt::signal::object<
		remove_function
	>
	remove_signal_type;

	set_type const &
	get() const;

	add_signal_type &
	add_signal();

	remove_signal_type &
	remove_signal();
private:
	set_type impl_;

	add_signal_type add_signal_;

	remove_signal_type remove_signal_;
};

}
}
}
}
}

#endif
