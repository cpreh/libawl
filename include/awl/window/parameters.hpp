#ifndef AWL_WINDOW_PARAMETERS_HPP_INCLUDED
#define AWL_WINDOW_PARAMETERS_HPP_INCLUDED

#include <awl/cursor/const_optional_object_ref.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/visual/object_fwd.hpp>
#include <awl/window/dim_fwd.hpp>
#include <awl/window/optional_dim.hpp>
#include <awl/window/optional_pos.hpp>
#include <awl/window/parameters_fwd.hpp>
#include <awl/window/pos_fwd.hpp>
#include <fcppt/nonassignable.hpp>
#include <fcppt/optional_string.hpp>
#include <fcppt/string.hpp>


namespace awl
{
namespace window
{

class parameters
{
	FCPPT_NONASSIGNABLE(
		parameters
	);
public:
	AWL_DETAIL_SYMBOL
	explicit
	parameters(
		awl::visual::object const &
	);

	AWL_DETAIL_SYMBOL
	awl::window::parameters &
	position(
		awl::window::pos const &
	);

	AWL_DETAIL_SYMBOL
	awl::window::parameters &
	size(
		awl::window::dim const &
	);

	AWL_DETAIL_SYMBOL
	awl::window::parameters &
	title(
		fcppt::string const &
	);

	AWL_DETAIL_SYMBOL
	awl::window::parameters &
	class_name(
		fcppt::string const &
	);

	AWL_DETAIL_SYMBOL
	awl::window::parameters &
	cursor(
		awl::cursor::object const &
	);

	AWL_DETAIL_SYMBOL
	awl::visual::object const &
	visual() const;

	AWL_DETAIL_SYMBOL
	awl::window::optional_pos
	position() const;

	AWL_DETAIL_SYMBOL
	awl::window::optional_dim
	size() const;

	AWL_DETAIL_SYMBOL
	fcppt::optional_string const &
	title() const;

	AWL_DETAIL_SYMBOL
	fcppt::optional_string const &
	class_name() const;

	AWL_DETAIL_SYMBOL
	awl::cursor::const_optional_object_ref const &
	cursor() const;
private:
	awl::visual::object const &visual_;

	awl::window::optional_pos position_;

	awl::window::optional_dim size_;

	fcppt::optional_string title_;

	fcppt::optional_string class_name_;

	awl::cursor::const_optional_object_ref cursor_;
};

}
}

#endif
