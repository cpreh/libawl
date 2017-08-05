#ifndef AWL_STREAM_OBJECT_IMPL_HPP_INCLUDED
#define AWL_STREAM_OBJECT_IMPL_HPP_INCLUDED

#include <awl/stream/empty_fwd.hpp>
#include <awl/stream/lazy_function_impl.hpp>
#include <fcppt/function_impl.hpp>
#include <fcppt/make_cref.hpp>
#include <fcppt/make_shared_ptr.hpp>
#include <fcppt/shared_ptr_impl.hpp>
#include <fcppt/optional/map.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/optional/reference.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


template<
	typename Result
>
awl::stream::object<
	Result
>::object(
	awl::stream::empty const &
)
:
	impl_{}
{
}

template<
	typename Result
>
awl::stream::object<
	Result
>::object(
	function_type &&_function
)
:
	impl_{
		fcppt::make_shared_ptr<
			lazy_function_type
		>(
			std::move(
				_function
			)
		)
	}
{
}

template<
	typename Result
>
template<
	typename Function
>
awl::stream::object<
	Result
>::object(
	Function const &_function
)
:
	object(
		function_type{
			_function
		}
	)
{
}

template<
	typename Result
>
typename
awl::stream::object<
	Result
>::optional_result_ref
awl::stream::object<
	Result
>::get() const
{
	return
		fcppt::optional::map(
			impl_,
			[](
				shared_ptr_type const &_impl
			)
			{
				return
					fcppt::make_cref(
						_impl->get().value()
					);
			}
		);
}

template<
	typename Result
>
typename
awl::stream::object<
	Result
>::optional_object
awl::stream::object<
	Result
>::pop_front() const
{
	return
		fcppt::optional::map(
			impl_,
			[](
				shared_ptr_type const &_impl
			)
			->
			object
			{
				return
					_impl->get().tail();
			}
		);
}

#endif
