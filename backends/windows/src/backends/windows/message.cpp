#include <awl/backends/windows/message.hpp>
#include <awl/backends/windows/windows.hpp>

awl::backends::windows::message::message(MSG const &_msg) : msg_(_msg) {}

MSG const &awl::backends::windows::message::get() const { return msg_; }
