#include <awl/exception.hpp>
#include <awl/impl/log_name.hpp>
#include <awl/system/create.hpp>
#include <awl/system/object.hpp>
#include <awl/system/object_unique_ptr.hpp>
#include <awl/config.hpp>
#if defined(AWL_X11_BACKEND)
#include <awl/backends/x11/system/original_object.hpp>
#endif
#if defined(AWL_WAYLAND_BACKEND)
#include <awl/backends/wayland/system/original_object.hpp>
#endif
#if defined(AWL_WINDOWS_BACKEND)
#include <awl/backends/windows/system/original_object.hpp>
#endif
#if defined(AWL_SDL_BACKEND)
#include <awl/backends/sdl/system/original_object.hpp>
#endif
#include <fcppt/function_impl.hpp>
#include <fcppt/from_std_string.hpp>
#include <fcppt/getenv.hpp>
#include <fcppt/make_strong_typedef.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/not.hpp>
#include <fcppt/string.hpp>
#include <fcppt/strong_typedef_impl.hpp>
#include <fcppt/text.hpp>
#include <fcppt/unique_ptr_to_base.hpp>
#include <fcppt/algorithm/contains_if.hpp>
#include <fcppt/algorithm/find_by_opt.hpp>
#include <fcppt/algorithm/join_strings.hpp>
#include <fcppt/algorithm/map.hpp>
#include <fcppt/container/join.hpp>
#undef Success
#include <fcppt/either/bind.hpp>
#include <fcppt/either/first_success.hpp>
#include <fcppt/either/from_optional.hpp>
#include <fcppt/either/object.hpp>
#include <fcppt/either/to_exception.hpp>
#include <fcppt/either/try_call.hpp>
#include <fcppt/log/context_fwd.hpp>
#include <fcppt/log/error.hpp>
#include <fcppt/log/object.hpp>
#include <fcppt/log/out.hpp>
#include <fcppt/log/parameters.hpp>
#include <fcppt/log/format/optional_function.hpp>
#include <fcppt/optional/make_if.hpp>
#include <fcppt/optional/maybe_void.hpp>
#include <fcppt/optional/map.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <utility>
#include <vector>
#include <fcppt/config/external_end.hpp>


namespace
{

typedef
fcppt::either::object<
	fcppt::string,
	awl::system::object_unique_ptr
>
either_type;

typedef
fcppt::function<
	either_type ()
>
function_type;

template<
	typename Result
>
function_type
try_create(
	fcppt::log::context &_log_context
)
{
	return
		function_type{
			[
				&_log_context
			]{
				return
					fcppt::either::try_call<
						awl::exception
					>(
						[
							&_log_context
						]{
							return
								fcppt::unique_ptr_to_base<
									awl::system::object
								>(
									fcppt::make_unique_ptr<
										Result
									>(
										_log_context
									)
								);
						},
						[](
							awl::exception const &_error
						)
						{
							return
								_error.string();
						}
					);
			}
		};
}

typedef
std::vector<
	std::pair<
		std::string,
		function_type
	>
>
backend_list;

backend_list
get_backends(
	fcppt::log::context &_log_context
)
{
	return
		backend_list{
#if defined(AWL_WAYLAND_BACKEND)
			std::make_pair(
				std::string{
					"wayland"
				},
				try_create<
					awl::backends::wayland::system::original_object
				>(
					_log_context
				)
			)
			,
#endif
#if defined(AWL_X11_BACKEND)
			std::make_pair(
				std::string{
					"X11"
				},
				try_create<
					awl::backends::x11::system::original_object
				>(
					_log_context
				)
			)
			,
#endif
#if defined(AWL_WINDOWS_BACKEND)
			std::make_pair(
				std::string{
					"Windows"
				},
				try_create<
					awl::backends::windows::system::original_object
				>(
					_log_context
				)
			)
			,
#endif
#if defined(AWL_SDL_BACKEND)
			std::make_pair(
				std::string{
					"SDL"
				},
				try_create<
					awl::backends::sdl::system::original_object
				>(
					_log_context
				)
			)
			,
#endif
			std::make_pair(
				std::string{},
				function_type{
					[]{
						return
							either_type{
								fcppt::string{
									FCPPT_TEXT("All possibilities exhausted.")
								}
							};
					}
				}
			)
		};
}

FCPPT_MAKE_STRONG_TYPEDEF(
	std::string,
	backend_name
);

fcppt::optional::object<
	backend_name
>
env_backend()
{
	return
		fcppt::optional::map(
			fcppt::getenv(
				"AWL_BACKEND"
			),
			[](
				std::string &&_name
			)
			{
				return
					backend_name{
						std::move(
							_name
						)
					};
			}
		);
}

function_type
create_from_env(
	backend_list const &_backend_list
)
{
	return
		function_type{
			[
				&_backend_list
			]()
			->
			either_type
			{
				return
					fcppt::either::bind(
						fcppt::either::bind(
							fcppt::either::from_optional(
								env_backend(),
								[]{
									return
										fcppt::string{
											FCPPT_TEXT("AWL_BACKEND not set.")
										};
								}
							),
							[
								&_backend_list
							](
								backend_name const &_backend
							)
							{
								return
									fcppt::either::from_optional(
										fcppt::algorithm::find_by_opt(
											_backend_list,
											[
												&_backend
											](
												std::pair<
													std::string,
													function_type
												> const &_element
											)
											{
												return
													fcppt::optional::make_if(
														_element.first
														==
														_backend.get(),
														[
															&_element
														]{
															return
																_element.second;
														}
													);
											}
										),
										[
											&_backend
										]{
											return
												fcppt::string{
													FCPPT_TEXT("Backend ")
													+
													fcppt::from_std_string(
														_backend.get()
													)
													+
													FCPPT_TEXT("not available!")
												};
										}
									);
							}
						),
						[](
							function_type const &_function
						)
						{
							return
								_function();
						}
					);
			}
		};
}

}

awl::system::object_unique_ptr
awl::system::create(
	fcppt::log::context &_log_context
)
{
	backend_list const backends{
		get_backends(
			_log_context
		)
	};

	fcppt::optional::maybe_void(
		env_backend(),
		[
			&_log_context,
			&backends
		](
			backend_name const &_backend
		)
		{
			if(
				fcppt::not_(
					fcppt::algorithm::contains_if(
						backends,
						[
							&_backend
						](
							std::pair<
								std::string,
								function_type
							> const &_cur
						)
						{
							return
								_cur.first
								==
								_backend.get();
						}
					)
				)
			)
			{
				fcppt::log::object log{
					_log_context,
					fcppt::log::parameters{
						awl::impl::log_name(),
						fcppt::log::format::optional_function{}
					}
				};

				FCPPT_LOG_ERROR(
					log,
					fcppt::log::out
						<<
						FCPPT_TEXT("AWL_BACKEND ")
						<<
						fcppt::from_std_string(
							_backend.get()
						)
						<<
						FCPPT_TEXT(" not available!")
				)
			}
		}
	);

	return
		fcppt::either::to_exception(
			fcppt::either::first_success(
				fcppt::container::join(
					std::vector<
						function_type
					>{
						create_from_env(
							backends
						)
					},
					fcppt::algorithm::map<
						std::vector<
							function_type
						>
					>(
						backends,
						[](
							std::pair<
								std::string,
								function_type
							> const &_backend
						)
						{
							return
								_backend.second;
						}
					)
				)
			),
			[](
				std::vector<
					fcppt::string
				> const &_failures
			)
			{
				return
					awl::exception{
						FCPPT_TEXT("Cannot create any system: ")
						+
						fcppt::algorithm::join_strings(
							_failures,
							fcppt::string{
								FCPPT_TEXT(", ")
							}
						)
					};
			}
		);
}
