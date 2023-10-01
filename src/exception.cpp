#include <awl/exception.hpp>
#include <fcppt/exception.hpp>
#include <fcppt/string.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

awl::exception::exception(fcppt::string &&_string) : fcppt::exception(std::move(_string)) {}

awl::exception::exception(exception const &) = default;

awl::exception::exception(exception &&) noexcept = default;

awl::exception &awl::exception::operator=(exception const &) = default;

awl::exception &awl::exception::operator=(exception &&) noexcept = default;

awl::exception::~exception() noexcept = default;
