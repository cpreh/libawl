#include <awl/exception.hpp>
#include <awl/backends/windows/counted_wndclass.hpp>
#include <awl/backends/windows/get_focus.hpp>
#include <awl/backends/windows/wndclass_remove_callback.hpp>
#include <awl/backends/windows/cursor/create_invisible.hpp>
#include <awl/backends/windows/cursor/create_predefined.hpp>
#include <awl/backends/windows/cursor/object.hpp>
#include <awl/backends/windows/system/object.hpp>
#include <awl/backends/windows/system/original_object.hpp>
#include <awl/backends/windows/system/event/original_processor.hpp>
#include <awl/backends/windows/visual/null_object.hpp>
#include <awl/backends/windows/window/original_object.hpp>
#include <awl/backends/windows/window/event/wnd_proc.hpp>
#include <awl/cursor/object.hpp>
#include <awl/cursor/object_unique_ptr.hpp>
#include <awl/cursor/optional_type.hpp>
#include <awl/cursor/type.hpp>
#include <awl/system/event/processor.hpp>
#include <awl/visual/object.hpp>
#include <awl/visual/object_unique_ptr.hpp>
#include <awl/window/object.hpp>
#include <awl/window/object_unique_ptr.hpp>
#include <awl/window/parameters.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/unique_ptr_to_base.hpp>
#include <fcppt/container/find_opt_iterator.hpp>
#include <fcppt/container/get_or_insert_result.hpp>
#include <fcppt/container/get_or_insert_with_result.hpp>
#include <fcppt/log/context_reference.hpp>
#include <fcppt/optional/from.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/optional/to_exception.hpp>
#include <fcppt/config/external_begin.hpp>
#include <functional>
#include <fcppt/config/external_end.hpp>

awl::backends::windows::system::original_object::original_object(fcppt::log::context_reference)
    : awl::backends::windows::system::object(),
      wndclasses_(),
      processor_{
          fcppt::make_unique_ptr<awl::backends::windows::system::event::original_processor>()}
{
}

awl::backends::windows::system::original_object::~original_object() {}

awl::window::object_unique_ptr awl::backends::windows::system::original_object::create_window(
    awl::window::parameters const &_param)
{
  fcppt::string const class_name{
      fcppt::optional::from(_param.class_name(), [] { return fcppt::string{}; })};

  fcppt::container::get_or_insert_result<wndclass_map::mapped_type &> const result(
      fcppt::container::get_or_insert_with_result(
          wndclasses_,
          class_name,
          [](fcppt::string const &_class_name)
          {
            return fcppt::make_unique_ptr<awl::backends::windows::counted_wndclass>(
                _class_name, awl::backends::windows::window::event::wnd_proc);
          }));

  // FIXME: This is not exception-safe
  if (!result.inserted())
    result.element()->add_ref();

  return fcppt::unique_ptr_to_base<awl::window::object>(
      fcppt::make_unique_ptr<awl::backends::windows::window::original_object>(
          _param,
          result.element()->wndclass(),
          processor_->next_events(),
          awl::backends::windows::wndclass_remove_callback{std::bind(
              &awl::backends::windows::system::original_object::unregister_wndclass,
              this,
              class_name)}));
}

awl::system::event::processor &awl::backends::windows::system::original_object::processor()
{
  return *processor_;
}

awl::visual::object_unique_ptr awl::backends::windows::system::original_object::default_visual()
{
  return fcppt::unique_ptr_to_base<awl::visual::object>(
      fcppt::make_unique_ptr<awl::backends::windows::visual::null_object>());
}

awl::cursor::object_unique_ptr awl::backends::windows::system::original_object::create_cursor(
    awl::cursor::optional_type const &_optional_type)
{
  return fcppt::unique_ptr_to_base<awl::cursor::object>(fcppt::optional::maybe(
      _optional_type,
      [] { return awl::backends::windows::cursor::create_invisible(); },
      [](awl::cursor::type const _type)
      { return awl::backends::windows::cursor::create_predefined(_type); }));
}

void awl::backends::windows::system::original_object::unregister_wndclass(
    fcppt::string const &_class_name)
{
  wndclass_map::iterator const it{fcppt::optional::to_exception(
      fcppt::container::find_opt_iterator(wndclasses_, _class_name),
      [] { return awl::exception{FCPPT_TEXT("Unable to unregister wndclass.")}; })};

  if (it->second->release() == 0u)
    wndclasses_.erase(it);
}
