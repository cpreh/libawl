#include <awl/event/base.hpp>
#include <awl/timer/event.hpp>
#include <awl/timer/object_fwd.hpp>
#include <awl/timer/reference.hpp>

awl::timer::event::event(awl::timer::reference const _timer) : awl::event::base{}, timer_{_timer} {}

awl::timer::event::~event() = default;

awl::timer::object &awl::timer::event::get() const { return timer_.get(); }
