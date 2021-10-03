#ifndef AWL_BACKENDS_POSIX_EVENT_HPP_INCLUDED
#define AWL_BACKENDS_POSIX_EVENT_HPP_INCLUDED

#include <awl/backends/posix/event_fwd.hpp>
#include <awl/backends/posix/fd.hpp>
#include <awl/detail/class_symbol.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/event/base.hpp>
#include <fcppt/nonmovable.hpp>


namespace awl::backends::posix
{

class AWL_DETAIL_CLASS_SYMBOL event
:
	public awl::event::base
{
	FCPPT_NONMOVABLE(
		event
	);
public:
	AWL_DETAIL_SYMBOL
	explicit
	event(
		awl::backends::posix::fd
	);

	AWL_DETAIL_SYMBOL
	~event()
	override;

	[[nodiscard]]
	AWL_DETAIL_SYMBOL
	awl::backends::posix::fd
	fd() const;
private:
	awl::backends::posix::fd const fd_;
};

}

#endif
