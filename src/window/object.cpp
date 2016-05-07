#include <awl/window/dim.hpp>
#include <awl/window/object.hpp>
#include <awl/window/rect.hpp>
#include <fcppt/math/dim/to_unsigned.hpp>


awl::window::object::object()
{
}

awl::window::object::~object()
{
}

awl::window::dim
awl::window::object::size() const
{
	return
		fcppt::math::dim::to_unsigned(
			this->rect().size()
		);
}
