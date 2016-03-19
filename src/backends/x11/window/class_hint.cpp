#include <awl/backends/x11/window/class_hint.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <utility>
#include <fcppt/config/external_end.hpp>


awl::backends::x11::window::class_hint::class_hint(
	res_name_type &&_res_name,
	res_class_type &&_res_class
)
:
	res_name_(
		std::move(
			_res_name
		)
	),
	res_class_(
		std::move(
			_res_class
		)
	)
{
}

std::string const &
awl::backends::x11::window::class_hint::res_name() const
{
	return
		res_name_.get();
}

std::string const &
awl::backends::x11::window::class_hint::res_class() const
{
	return
		res_class_.get();
}
