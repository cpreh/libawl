#ifndef AWL_EVENT_VARIANT_FWD_HPP_INCLUDED
#define AWL_EVENT_VARIANT_FWD_HPP_INCLUDED

#include <fcppt/variant/object_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>


namespace awl::event
{

template<
	typename Type
>
using
variant
=
fcppt::variant::object<
	std::vector<
		Type
	>,
	Type
>;

}

#endif
