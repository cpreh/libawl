#ifndef AWL_BACKENDS_WAYLAND_ID_LESS_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_ID_LESS_HPP_INCLUDED

#include <awl/backends/wayland/registry_id.hpp>


namespace awl
{
namespace backends
{
namespace wayland
{

template<
	typename Type
>
struct id_less
{
	typedef
	void
	is_transparent;

	bool
	operator()(
		Type const &_left,
		awl::backends::wayland::registry_id const _right
	) const
	{
		return
			_left.name()
			<
			_right;
	}

	bool
	operator()(
		awl::backends::wayland::registry_id const _left,
		Type const &_right
	) const
	{
		return
			_left
			<
			_right.name();
	}

	bool
	operator()(
		Type const &_left,
		Type const &_right
	) const
	{
		return
			_left.name()
			<
			_right.name();
	}
};

}
}
}

#endif
