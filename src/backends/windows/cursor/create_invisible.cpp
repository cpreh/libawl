#include <awl/backends/windows/system_metrics.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/cursor/create_invisible.hpp>
#include <awl/backends/windows/cursor/created.hpp>
#include <awl/backends/windows/cursor/dim.hpp>
#include <awl/backends/windows/cursor/object.hpp>
#include <awl/backends/windows/cursor/object_unique_ptr.hpp>
#include <awl/backends/windows/cursor/size.hpp>
#include <awl/cursor/hotspot.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr_to_base.hpp>
#include <fcppt/cast/to_unsigned.hpp>
#include <fcppt/math/dim/contents.hpp>
#include <fcppt/math/vector/null.hpp>
#include <fcppt/config/external_begin.hpp>
#include <limits>
#include <vector>
#include <fcppt/config/external_end.hpp>

awl::backends::windows::cursor::object_unique_ptr awl::backends::windows::cursor::create_invisible()
{
  awl::backends::windows::cursor::dim const dim(
      fcppt::cast::to_unsigned(awl::backends::windows::system_metrics(SM_CXCURSOR)),
      fcppt::cast::to_unsigned(awl::backends::windows::system_metrics(SM_CYCURSOR)));

  typedef std::vector<BYTE> byte_vector;

  awl::backends::windows::cursor::size const size(fcppt::math::dim::contents(dim) / 8);

  byte_vector const and_vector(size, std::numeric_limits<BYTE>::max());

  byte_vector const xor_vector(size, 0);

  return fcppt::unique_ptr_to_base<awl::backends::windows::cursor::object>(
      fcppt::make_unique_ptr<awl::backends::windows::cursor::created>(
          fcppt::math::vector::null<awl::cursor::hotspot>(),
          dim,
          awl::backends::windows::cursor::and_plane(and_vector.data()),
          awl::backends::windows::cursor::xor_plane(xor_vector.data())));
}
