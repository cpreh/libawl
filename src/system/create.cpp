#include <awl/exception.hpp>
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
#include <fcppt/function_impl.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/unique_ptr_to_base.hpp>
#include <fcppt/algorithm/join_strings.hpp>
#include <fcppt/container/array/make.hpp>
#undef Success
#include <fcppt/either/first_success.hpp>
#include <fcppt/either/object.hpp>
#include <fcppt/either/to_exception.hpp>
#include <fcppt/either/try_call.hpp>
#include <fcppt/log/context_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
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

}

awl::system::object_unique_ptr
awl::system::create(
	fcppt::log::context &_log_context
)
{
	return
		fcppt::either::to_exception(
			fcppt::either::first_success(
				fcppt::container::array::make(
#if defined(AWL_WAYLAND_BACKEND)
					try_create<
						awl::backends::wayland::system::original_object
					>(
						_log_context
					)
					,
#endif
#if defined(AWL_X11_BACKEND)
					try_create<
						awl::backends::x11::system::original_object
					>(
						_log_context
					)
					,
#endif
#if defined(AWL_WINDOWS_BACKEND)
					try_create<
						awl::backends::windows::system::original_object
					>(
						_log_context
					)
					,
#endif
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
