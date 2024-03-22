#ifndef AWL_CURSOR_TYPE_HPP_INCLUDED
#define AWL_CURSOR_TYPE_HPP_INCLUDED

#include <awl/cursor/type_fwd.hpp> // IWYU pragma: keep
#include <fcppt/config/external_begin.hpp>
#include <cstdint>
#include <fcppt/config/external_end.hpp>

namespace awl::cursor
{

enum class type : std::uint8_t
{
  arrow,
  cross,
  hand
};

}

#endif
