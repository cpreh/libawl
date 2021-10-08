#include <awl/backends/windows/counted_wndclass.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/wndclass.hpp>
#include <fcppt/string.hpp>
#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <fcppt/config/external_end.hpp>

awl::backends::windows::counted_wndclass::counted_wndclass(
    fcppt::string const &_name, WNDPROC const _proc)
    : wndclass_(_name, _proc), counter_(0u)
{
}

awl::backends::windows::counted_wndclass::~counted_wndclass() {}

void awl::backends::windows::counted_wndclass::add_ref() { ++counter_; }

awl::backends::windows::counted_wndclass::counter_type
awl::backends::windows::counted_wndclass::release()
{
  return --counter_;
}

awl::backends::windows::wndclass &awl::backends::windows::counted_wndclass::wndclass()
{
  return wndclass_;
}
