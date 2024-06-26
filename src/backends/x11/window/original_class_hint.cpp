#include <awl/exception.hpp>
#include <awl/backends/x11/window/class_hint.hpp>
#include <awl/backends/x11/window/original_class_hint.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/nonmovable.hpp>
#include <fcppt/text.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <utility>
#include <fcppt/config/external_end.hpp>

class awl::backends::x11::window::original_class_hint::impl
{
public:
  FCPPT_NONMOVABLE(impl);

  impl();

  ~impl();

  [[nodiscard]] XClassHint *get() const;

private:
  XClassHint *const hint_;
};

awl::backends::x11::window::original_class_hint::original_class_hint(
    awl::backends::x11::window::class_hint &&_hint)
    : impl_(fcppt::make_unique_ptr<impl>()), hint_(std::move(_hint))
{
  XClassHint *const hint(this->get());

  hint->res_name =
      // NOLINTNEXTLINE(cppcoreguidelines-pro-type-const-cast)
      const_cast<char *>(hint_.res_name().c_str());

  hint->res_class =
      // NOLINTNEXTLINE(cppcoreguidelines-pro-type-const-cast)
      const_cast<char *>(hint_.res_class().c_str());
}

awl::backends::x11::window::original_class_hint::~original_class_hint() = default;

XClassHint *awl::backends::x11::window::original_class_hint::get() const { return impl_->get(); }

awl::backends::x11::window::class_hint const &
awl::backends::x11::window::original_class_hint::hint() const
{
  return hint_;
}

awl::backends::x11::window::original_class_hint::impl::impl() : hint_(::XAllocClassHint())
{
  if (hint_ == nullptr)
  {
    throw awl::exception{FCPPT_TEXT("XAllocClassHint() failed!")};
  }
}

awl::backends::x11::window::original_class_hint::impl::~impl() { ::XFree(hint_); }

XClassHint *awl::backends::x11::window::original_class_hint::impl::get() const { return hint_; }
