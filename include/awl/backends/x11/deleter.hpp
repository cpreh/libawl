#ifndef AWL_BACKENDS_X11_DELETER_HPP_INCLUDED
#define AWL_BACKENDS_X11_DELETER_HPP_INCLUDED

#include <awl/backends/x11/free.hpp>

namespace awl::backends::x11
{

struct deleter
{
  template <typename T>
  void operator()(T *const _param) const
  {
    awl::backends::x11::free(_param);
  }
};

}

#endif
