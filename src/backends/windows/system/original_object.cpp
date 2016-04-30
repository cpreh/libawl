#include <awl/backends/windows/counted_wndclass.hpp>
#include <awl/backends/windows/default_wnd_proc.hpp>
#include <awl/backends/windows/get_focus.hpp>
#include <awl/backends/windows/wndclass_remove_callback.hpp>
#include <awl/backends/windows/system/object.hpp>
#include <awl/backends/windows/system/original_object.hpp>
#include <awl/backends/windows/system/event/original_processor.hpp>
#include <awl/backends/windows/visual/null_object.hpp>
#include <awl/backends/windows/window/object_unique_ptr.hpp>
#include <awl/backends/windows/window/original_object.hpp>
#include <awl/system/event/processor.hpp>
#include <awl/system/event/processor_unique_ptr.hpp>
#include <awl/visual/object.hpp>
#include <awl/visual/object_unique_ptr.hpp>
#include <awl/window/object.hpp>
#include <awl/window/object_unique_ptr.hpp>
#include <awl/window/parameters.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/string.hpp>
#include <fcppt/unique_ptr_to_base.hpp>
#include <fcppt/assert/optional_error.hpp>
#include <fcppt/container/find_opt_iterator.hpp>
#include <fcppt/container/get_or_insert_result.hpp>
#include <fcppt/container/get_or_insert_with_result.hpp>
#include <fcppt/optional/map.hpp>
#include <fcppt/config/external_begin.hpp>
#include <functional>
#include <utility>
#include <fcppt/config/external_end.hpp>


awl::backends::windows::system::original_object::original_object()
:
	awl::backends::windows::system::object(),
	wndclasses_()
{
}

awl::backends::windows::system::original_object::~original_object()
{
}

awl::window::object_unique_ptr
awl::backends::windows::system::original_object::create_window(
	awl::window::parameters const &_param
)
{
	fcppt::container::get_or_insert_result<
		wndclass_map::mapped_type &
	> const result(
		fcppt::container::get_or_insert_with_result(
			wndclasses_,
			_param.class_name(),
			[](
				fcppt::string const &_class_name
			)
			{
				return
					awl::backends::windows::counted_wndclass(
						_class_name,
						awl::backends::windows::default_wnd_proc
					);
			}
		)
	);

	if(
		!result.inserted()
	)
		result.element().add_ref();

	return
		fcppt::unique_ptr_to_base<
			awl::window::object
		>(
			fcppt::make_unique_ptr<
				awl::backends::windows::window::original_object
			>(
				_param,
				result.element().wndclass(),
				awl::backends::windows::wndclass_remove_callback{
					std::bind(
						&awl::backends::windows::system::original_object::unregister_wndclass,
						this,
						_param.class_name()
					)
				}
			)
		);
}

awl::system::event::processor_unique_ptr
awl::backends::windows::system::original_object::create_processor()
{
	return
		fcppt::unique_ptr_to_base<
			awl::system::event::processor
		>(
			fcppt::make_unique_ptr<
				awl::backends::windows::system::event::original_processor
			>()
		);
}

awl::visual::object_unique_ptr
awl::backends::windows::system::original_object::default_visual()
{
	return
		fcppt::unique_ptr_to_base<
			awl::visual::object
		>(
			fcppt::make_unique_ptr<
				awl::backends::windows::visual::null_object
			>()
		);
}

awl::window::optional_object_unique_ptr
awl::backends::windows::system::original_object::focus_window()
{
	return
		fcppt::optional::map(
			awl::backends::windows::get_focus(),
			[](
				awl::backends::windows::window::object_unique_ptr &&_focus
			)
			{
				return
					fcppt::unique_ptr_to_base<
						awl::window::object
					>(
						std::move(
							_focus
						)
					);
			}
		);
}

void
awl::backends::windows::system::original_object::unregister_wndclass(
	fcppt::string const &_class_name
)
{
	wndclass_map::iterator const it(
		FCPPT_ASSERT_OPTIONAL_ERROR(
			fcppt::container::find_opt_iterator(
				wndclasses_,
				_class_name
			)
		)
	);

	if(
		it->second.release()
		==
		0u
	)
		wndclasses_.erase(
			it
		);
}
