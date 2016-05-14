#ifndef AWL_BACKENDS_WAYLAND_SYSTEM_EVENT_REGISTRY_SET_IMPL_HPP_INCLUDED
#define AWL_BACKENDS_WAYLAND_SYSTEM_EVENT_REGISTRY_SET_IMPL_HPP_INCLUDED

#include <awl/backends/wayland/registry_id.hpp>
#include <awl/backends/wayland/system/event/add_remove_decl.hpp>
#include <awl/backends/wayland/system/event/added.hpp>
#include <awl/backends/wayland/system/event/registry_set_decl.hpp>
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
awl::backends::wayland::system::event::registry_set<
	Type
>::registry_set()
:
	impl_{},
	signal_{}
{
}

template<
	typename Type
>
awl::backends::wayland::system::event::registry_set<
	Type
>::registry_set(
	registry_set &&
)
= default;

template<
	typename Type
>
awl::backends::wayland::system::event::registry_set<
	Type
> &
awl::backends::wayland::system::event::registry_set<
	Type
>::operator=(
	registry_set &&
)
= default;

template<
	typename Type
>
awl::backends::wayland::system::event::registry_set<
	Type
>::~registry_set()
{
}

template<
	typename Type
>
void
awl::backends::wayland::system::event::registry_set<
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

	signal_(
		event_type{
			*result.first,
			awl::backends::wayland::system::event::added{
				true
			}
		}
	);
}

template<
	typename Type
>
void
awl::backends::wayland::system::event::registry_set<
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
			signal_(
				event_type{
					*_iterator,
					awl::backends::wayland::system::event::added{
						false
					}
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
awl::backends::wayland::system::event::registry_set<
	Type
>::set_type const &
awl::backends::wayland::system::event::registry_set<
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
awl::backends::wayland::system::event::registry_set<
	Type
>::signal_type &
awl::backends::wayland::system::event::registry_set<
	Type
>::signal()
{
	return
		signal_;
}

#endif
