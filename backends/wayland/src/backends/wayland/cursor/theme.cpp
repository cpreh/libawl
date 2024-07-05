#include <awl/exception.hpp>
#include <awl/backends/wayland/shm.hpp>
#include <awl/backends/wayland/cursor/theme.hpp>
#include <fcppt/text.hpp>
#include <fcppt/config/external_begin.hpp>
#include <wayland-cursor.h>
#include <fcppt/config/external_end.hpp>

namespace
{

constexpr int const cursor_size{32};

}

awl::backends::wayland::cursor::theme::theme(awl::backends::wayland::shm const &_shm)
    : impl_{::wl_cursor_theme_load(nullptr, cursor_size, _shm.get())}
{
  if (impl_ == nullptr)
  {
    throw awl::exception{FCPPT_TEXT("Loading a cursor theme failed")};
  }
}

awl::backends::wayland::cursor::theme::~theme() { ::wl_cursor_theme_destroy(impl_); }

wl_cursor_theme *awl::backends::wayland::cursor::theme::get() const { return impl_; }
