#include <awl/backends/windows/cursor/convert_predefined.hpp>
#include <awl/backends/windows/cursor/create_predefined.hpp>
#include <awl/backends/windows/cursor/load.hpp>
#include <awl/backends/windows/cursor/object.hpp>
#include <awl/backends/windows/cursor/object_unique_ptr.hpp>
#include <awl/backends/windows/cursor/shared.hpp>
#include <awl/cursor/type.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr_to_base.hpp>

awl::backends::windows::cursor::object_unique_ptr
awl::backends::windows::cursor::create_predefined(awl::cursor::type const _type)
{
  return fcppt::unique_ptr_to_base<awl::backends::windows::cursor::object>(
      fcppt::make_unique_ptr<awl::backends::windows::cursor::shared>(
          awl::backends::windows::cursor::load(
              awl::backends::windows::cursor::convert_predefined(_type))));
}
