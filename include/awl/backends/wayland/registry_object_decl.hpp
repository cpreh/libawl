#ifndef AWL_BACKENDS_WAYLAND_REGISTRY_OBJECT_DECL_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_REGISTRY_OBJECT_DECL_HPP_INCLUDED

#include <awl/backends/wayland/registry_id.hpp>
#include <awl/backends/wayland/registry_object_fwd.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <wayland-client-protocol.h>
#include <wayland-util.h>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace backends
{
namespace wayland
{

template<
	typename Type,
	wl_interface const &Interface,
	void (&Destroy)(Type *)
>
class registry_object
{
	FCPPT_NONCOPYABLE(
		registry_object
	);
public:
	registry_object(
		wl_registry *,
		awl::backends::wayland::registry_id
	);

	registry_object(
		registry_object &&
	);

	registry_object &
	operator=(
		registry_object &&
	);

	~registry_object();

	Type *
	get() const;

	awl::backends::wayland::registry_id
	name() const;
private:
	Type *value_;

	awl::backends::wayland::registry_id name_;
};

}
}
}

#endif
