#ifndef AWL_BACKENDS_WAYLAND_SYSTEM_EVENT_SET_IMPL_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_SYSTEM_EVENT_SET_IMPL_HPP_INCLUDED

#include <awl/backends/wayland/registry_id.hpp>
#include <awl/backends/wayland/system/event/add_decl.hpp>
#include <awl/backends/wayland/system/event/remove_decl.hpp>
#include <awl/backends/wayland/system/event/set_decl.hpp>
#include <fcppt/assert/error.hpp>
#include <fcppt/container/find_opt_iterator.hpp>
#include <fcppt/optional/maybe_void.hpp>
#include <fcppt/signal/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


template<
	typename Type
>
awl::backends::wayland::system::event::set<
	Type
>::set()
:
	impl_{},
	add_signal_{},
	remove_signal_{}
{
}

template<
	typename Type
>
awl::backends::wayland::system::event::set<
	Type
>::set(
	set &&
)
= default;

template<
	typename Type
>
awl::backends::wayland::system::event::set<
	Type
> &
awl::backends::wayland::system::event::set<
	Type
>::operator=(
	set &&
)
= default;

template<
	typename Type
>
awl::backends::wayland::system::event::set<
	Type
>::~set()
{
}

template<
	typename Type
>
void
awl::backends::wayland::system::event::set<
	Type
>::add(
	Type &&_other
)
{
	std::pair<
		typename
		set_type::iterator,
		bool
	> const result{
		impl_.insert(
			std::move(
				_other
			)
		)
	};

	FCPPT_ASSERT_ERROR(
		result.second
	);

	add_signal_(
		add_event{
			*result.first
		}
	);
}

template<
	typename Type
>
void
awl::backends::wayland::system::event::set<
	Type
>::remove(
	awl::backends::wayland::registry_id const _id
)
{
	fcppt::optional::maybe_void(
		fcppt::container::find_opt_iterator(
			impl_,
			_id
		),
		[
			this
		](
			typename
			set_type::iterator const _iterator
		)
		{
			remove_signal_(
				remove_event{
					*_iterator
				}
			);

			impl_.erase(
				_iterator
			);
		}
	);
}

template<
	typename Type
>
typename
awl::backends::wayland::system::event::set<
	Type
>::set_type const &
awl::backends::wayland::system::event::set<
	Type
>::get() const
{
	return
		impl_;
}

template<
	typename Type
>
typename
awl::backends::wayland::system::event::set<
	Type
>::add_signal_type &
awl::backends::wayland::system::event::set<
	Type
>::add_signal()
{
	return
		add_signal_;
}

template<
	typename Type
>
typename
awl::backends::wayland::system::event::set<
	Type
>::remove_signal_type &
awl::backends::wayland::system::event::set<
	Type
>::remove_signal()
{
	return
		remove_signal_;
}

#endif
