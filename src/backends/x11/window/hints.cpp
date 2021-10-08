#include <awl/exception.hpp>
#include <awl/backends/x11/free.hpp>
#include <awl/backends/x11/window/hints.hpp>
#include <fcppt/text.hpp>

awl::backends::x11::window::hints::hints() : hints_(::XAllocWMHints())
{
  if (hints_ == nullptr)
  {
    throw awl::exception{FCPPT_TEXT("XAllocWMHints() failed!")};
  }

  hints_->input = True;

  hints_->initial_state = NormalState;

  hints_->flags = InputHint | StateHint; // NOLINT(hicpp-signed-bitwise)
}

awl::backends::x11::window::hints::~hints() { awl::backends::x11::free(hints_); }

XWMHints *awl::backends::x11::window::hints::get() const { return hints_; }
