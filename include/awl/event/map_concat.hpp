#ifndef AWL_EVENT_MAP_CONCAT_HPP_INCLUDED
#define AWL_EVENT_MAP_CONCAT_HPP_INCLUDED

#include <fcppt/container/join.hpp>
#include <fcppt/variant/match.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <vector>
#include <fcppt/config/external_end.hpp>

namespace awl::event
{

template <typename Result, typename Source, typename Function>
std::vector<Result> map_concat(std::vector<Source> &&_source, Function const &_function)
{
  std::vector<Result> result;

  // Estimate size.
  result.reserve(_source.size());

  for (Source &element : _source)
  {
    fcppt::variant::match(
        _function(std::move(element)),
        [&result](std::vector<Result> &&_container)
        { result = fcppt::container::join(std::move(result), std::move(_container)); },
        [&result](Result &&_inner) { result.push_back(std::move(_inner)); });
  }

  return result;
}

}

#endif
