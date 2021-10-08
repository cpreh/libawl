#ifndef AWL_BACKENDS_WINDOWS_MESSAGE_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_MESSAGE_HPP_INCLUDED

#include <awl/backends/windows/message_fwd.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/detail/symbol.hpp>

namespace awl
{
namespace backends
{
namespace windows
{

class message
{
public:
  AWL_DETAIL_SYMBOL
  explicit message(MSG const &);

  AWL_DETAIL_SYMBOL
  MSG const &get() const;

private:
  MSG msg_;
};

}
}
}

#endif
