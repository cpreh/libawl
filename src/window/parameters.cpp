#include <awl/cursor/const_optional_object_ref.hpp>
#include <awl/visual/object_fwd.hpp>
#include <awl/window/dim.hpp>
#include <awl/window/optional_dim.hpp>
#include <awl/window/parameters.hpp>
#include <fcppt/make_cref.hpp>
#include <fcppt/optional_string.hpp>
#include <fcppt/string.hpp>


awl::window::parameters::parameters(
	awl::visual::object const &_visual
)
:
	visual_(
		_visual
	),
	size_(),
	title_(),
	class_name_(),
	cursor_()
{
}

awl::window::parameters &
awl::window::parameters::size(
	awl::window::dim const &_size
)
{
	size_ =
		awl::window::optional_dim(
			_size
		);

	return
		*this;
}

awl::window::parameters &
awl::window::parameters::title(
	fcppt::string const &_title
)
{
	title_ =
		fcppt::optional_string{
			_title
		};

	return
		*this;
}

awl::window::parameters &
awl::window::parameters::class_name(
	fcppt::string const &_class_name
)
{
	class_name_ =
		fcppt::optional_string{
			_class_name
		};

	return
		*this;
}

awl::window::parameters &
awl::window::parameters::cursor(
	awl::cursor::object const &_cursor
)
{
	cursor_ =
		awl::cursor::const_optional_object_ref{
			fcppt::make_cref(
				_cursor
			)
		};

	return
		*this;
}

awl::visual::object const &
awl::window::parameters::visual() const
{
	return
		visual_;
}

awl::window::optional_dim
awl::window::parameters::size() const
{
	return
		size_;
}

fcppt::optional_string const &
awl::window::parameters::title() const
{
	return
		title_;
}

fcppt::optional_string const &
awl::window::parameters::class_name() const
{
	return
		class_name_;
}

awl::cursor::const_optional_object_ref const &
awl::window::parameters::cursor() const
{
	return
		cursor_;
}
