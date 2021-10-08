#include <awl/event/concrete_connection.hpp>
#include <awl/event/connection.hpp>
#include <awl/event/connection_function.hpp>
#include <awl/event/connection_unique_ptr.hpp>
#include <awl/event/make_connection.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr_to_base.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

awl::event::connection_unique_ptr
awl::event::make_connection(awl::event::connection_function &&_function)
{
  return fcppt::unique_ptr_to_base<awl::event::connection>(
      fcppt::make_unique_ptr<awl::event::concrete_connection>(std::move(_function)));
}
