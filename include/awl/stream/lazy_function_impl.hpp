#ifndef AWL_STREAM_LAZY_FUNCTION_IMPL_HPP_INCLUDED
#define AWL_STREAM_LAZY_FUNCTION_IMPL_HPP_INCLUDED

#include <awl/stream/lazy_function_decl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


template<
	typename Result
>
template<
	typename Function
>
awl::stream::lazy_function<
	Result
>::lazy_function(
	Function const &_function
)
:
	lazy_function(
		function_type{
			_function
		}
	)
{
}

template<
	typename Result
>
awl::stream::lazy_function<
	Result
>::lazy_function(
	function_type &&_function
)
:
	result_{},
	function_{
		std::move(
			_function
		)
	},
	thunk_{
		&thunk_force
	}
{
}

template<
	typename Result
>
Result const &
awl::stream::lazy_function<
	Result
>::get() const
{
	return
		thunk_(
			*this
		);
}

template<
	typename Result
>
Result const &
awl::stream::lazy_function<
	Result
>::thunk_force(
	lazy_function const &_this
)
{
	_this.result_ =
		optional_result{
			_this.function_()
		};

	_this.thunk_ =
		&thunk_get;

	return
		_this.get();
}

template<
	typename Result
>
Result const &
awl::stream::lazy_function<
	Result
>::thunk_get(
	lazy_function const &_this
)
{
	return
		_this.result_.get_unsafe();
}

#endif
