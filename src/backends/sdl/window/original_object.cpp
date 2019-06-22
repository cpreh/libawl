#include <awl/backends/sdl/visual/object.hpp>
#include <awl/backends/sdl/window/object.hpp>
#include <awl/backends/sdl/window/original_object.hpp>
#include <awl/backends/sdl/window/set_object.hpp>
#include <awl/visual/object_fwd.hpp>
#include <awl/window/dim.hpp>
#include <awl/window/parameters.hpp>
#include <fcppt/make_ref.hpp>
#include <fcppt/reference_to_base.hpp>
#include <fcppt/string.hpp>
#include <fcppt/to_std_string.hpp>
#include <fcppt/cast/dynamic_exn.hpp>
#include <fcppt/cast/to_signed.hpp>
#include <fcppt/optional/from.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/config/external_begin.hpp>
#include <SDL_video.h>
#include <string>
#include <fcppt/config/external_end.hpp>


awl::backends::sdl::window::original_object::original_object(
	awl::window::parameters const &_parameters
)
:
	awl::backends::sdl::window::object{},
	visual_{
		_parameters.visual()
	},
	cursor_{
		_parameters.cursor()
	},
	impl_{
		SDL_CreateWindow(
			fcppt::optional::maybe(
				_parameters.title(),
				[]{
					return
						std::string{};
				},
				[](
					fcppt::string const &_title
				)
				{
					return
						fcppt::optional::from(
							fcppt::to_std_string(
								_title
							),
							[]{
								return
									std::string{
										"Invalid title"
									};
							}
						);
				}
			).c_str(),
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			fcppt::cast::to_signed(
				fcppt::optional::maybe(
					_parameters.size(),
					[]{
						return
							1024u;
					},
					[](
						awl::window::dim const &_dim
					)
					{
						return
							_dim.w();
					}
				)
			),
			fcppt::cast::to_signed(
				fcppt::optional::maybe(
					_parameters.size(),
					[]{
						return
							768u;
					},
					[](
						awl::window::dim const &_dim
					)
					{
						return
							_dim.h();
					}
				)
			),
			fcppt::cast::dynamic_exn<
				awl::backends::sdl::visual::object const &
			>(
				_parameters.visual()
			).flags().get()
		)
	}
{
	awl::backends::sdl::window::set_object(
		this->get(),
		fcppt::reference_to_base<
			awl::window::object
		>(
			fcppt::make_ref(
				*this
			)
		)
	);
	// TODO: Set cursor when the window becomes active?
}

awl::backends::sdl::window::original_object::~original_object()
{
}

SDL_Window &
awl::backends::sdl::window::original_object::get() const
{
	return
		this->impl_.get();
}

awl::visual::object const &
awl::backends::sdl::window::original_object::visual() const
{
	return
		this->visual_;
}
