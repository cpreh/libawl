#ifndef AWL_STREAM_LAZY_FUNCTION_DECL_HPP_INCLUDED
#define AWL_STREAM_LAZY_FUNCTION_DECL_HPP_INCLUDED

#include <awl/stream/lazy_function_fwd.hpp>
#include <fcppt/function_impl.hpp>
#include <fcppt/optional/object_impl.hpp>


namespace awl
{
namespace stream
{

template<
	typename Result
>
class lazy_function
{
public:
	typedef
	fcppt::function<
		Result ()
	>
	function_type;

	template<
		typename Function
	>
	explicit
	lazy_function(
		Function const &
	);

	explicit
	lazy_function(
		function_type &&
	);

	Result const &
	get() const;
private:
	static
	Result const &
	thunk_force(
		lazy_function const &
	);

	static
	Result const &
	thunk_get(
		lazy_function const &
	);

	typedef
	fcppt::optional::object<
		Result
	>
	optional_result;

	mutable optional_result result_;

	using
	thunk_type
	=
	Result const &(*)(
		lazy_function const &
	);

	function_type function_;

	mutable thunk_type thunk_;
};

}
}

#endif
