#ifndef AWL_EXCEPTION_HPP_INCLUDED
#define AWL_EXCEPTION_HPP_INCLUDED

#include <awl/detail/class_symbol.hpp>
#include <awl/detail/symbol.hpp>
#include <fcppt/exception.hpp>
#include <fcppt/string.hpp>
#include <fcppt/assert/information_fwd.hpp>

namespace awl
{

class AWL_DETAIL_CLASS_SYMBOL exception : public fcppt::exception
{
public:
  explicit exception(fcppt::string &&);

  explicit exception(fcppt::assert_::information const &);

  AWL_DETAIL_SYMBOL
  exception(exception const &);

  AWL_DETAIL_SYMBOL
  exception(exception &&) noexcept;

  AWL_DETAIL_SYMBOL
  exception &operator=(exception const &);

  AWL_DETAIL_SYMBOL
  exception &operator=(exception &&) noexcept;

  AWL_DETAIL_SYMBOL
  ~exception() noexcept override;
};

}

#endif
