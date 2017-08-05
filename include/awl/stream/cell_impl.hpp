#ifndef AWL_STREAM_CELL_IMPL_HPP_INCLUDED
#define AWL_STREAM_CELL_IMPL_HPP_INCLUDED

#include <awl/stream/cell_decl.hpp>
#include <awl/stream/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


template<
	typename Result
>
awl::stream::cell<
	Result
>::cell(
	Result const &_result,
	stream_type &&_tail
)
:
	value_{
		_result
	},
	tail_{
		std::move(
			_tail
		)
	}
{
}

template<
	typename Result
>
awl::stream::cell<
	Result
>::cell(
	Result &&_result,
	stream_type &&_tail
)
:
	value_{
		std::move(
			_result
		)
	},
	tail_{
		std::move(
			_tail
		)
	}
{
}

template<
	typename Result
>
awl::stream::cell<
	Result
>::cell(
	cell &&
)
=
default;

template<
	typename Result
>
awl::stream::cell<
	Result
> &
awl::stream::cell<
	Result
>::operator=(
	cell &&
)
=
default;

template<
	typename Result
>
awl::stream::cell<
	Result
>::~cell()
{
}

template<
	typename Result
>
Result const &
awl::stream::cell<
	Result
>::value() const
{
	return
		value_;
}

template<
	typename Result
>
typename
awl::stream::cell<
	Result
>::stream_type const &
awl::stream::cell<
	Result
>::tail() const
{
	return
		tail_;
}

#endif
