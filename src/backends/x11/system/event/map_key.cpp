#include <awl/backends/x11/system/event/map_key.hpp>
#include <awl/backends/x11/system/event/opcode.hpp>
#include <awl/backends/x11/system/event/type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


awl::backends::x11::system::event::map_key::map_key(
	awl::backends::x11::system::event::opcode const &_opcode,
	awl::backends::x11::system::event::type const &_type
)
:
	opcode_(
		_opcode
	),
	type_(
		_type
	)
{
}

awl::backends::x11::system::event::opcode const &
awl::backends::x11::system::event::map_key::opcode() const
{
	return
		opcode_;
}

awl::backends::x11::system::event::type const &
awl::backends::x11::system::event::map_key::type() const
{
	return
		type_;
}

bool
awl::backends::x11::system::event::operator<(
	awl::backends::x11::system::event::map_key const &_a,
	awl::backends::x11::system::event::map_key const &_b
)
{
	return
		std::make_pair(
			_a.opcode(),
			_a.type()
		)
		<
		std::make_pair(
			_b.opcode(),
			_b.type()
		);
}
