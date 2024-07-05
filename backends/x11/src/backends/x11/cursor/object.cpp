#include <awl/backends/x11/cursor/holder.hpp> // NOLINT(misc-include-cleaner)
#include <awl/backends/x11/cursor/holder_unique_ptr.hpp>
#include <awl/backends/x11/cursor/object.hpp>
#include <awl/cursor/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/X.h>
#include <utility>
#include <fcppt/config/external_end.hpp>

awl::backends::x11::cursor::object::object(awl::backends::x11::cursor::holder_unique_ptr &&_holder)
    : awl::cursor::object(), holder_(std::move(_holder))
{
}

awl::backends::x11::cursor::object::~object() = default;

Cursor awl::backends::x11::cursor::object::get() const { return holder_->get(); }
