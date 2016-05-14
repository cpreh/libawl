#ifndef AWL_BACKENDS_WAYLAND_REGISTRY_SET_DECL_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_REGISTRY_SET_DECL_HPP_INCLUDED

#include <awl/backends/wayland/registry_id.hpp>
#include <awl/backends/wayland/registry_object_less.hpp>
#include <awl/backends/wayland/registry_set_fwd.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <set>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace backends
{
namespace wayland
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
	std::set<
		Type,
		awl::backends::wayland::registry_object_less<
			Type
		>
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

	set_type const &
	get() const;
private:
	set_type impl_;
};

}
}
}

#endif
