#ifndef AWL_STREAM_OBJECT_DECL_HPP_INCLUDED
#define AWL_STREAM_OBJECT_DECL_HPP_INCLUDED

#include <awl/stream/cell_fwd.hpp>
#include <awl/stream/empty_fwd.hpp>
#include <awl/stream/lazy_function_fwd.hpp>
#include <awl/stream/object_fwd.hpp>
#include <fcppt/function_fwd.hpp>
#include <fcppt/shared_ptr_decl.hpp>
#include <fcppt/optional/object_decl.hpp>
#include <fcppt/optional/reference_fwd.hpp>


namespace awl
{
namespace stream
{

template<
	typename Result
>
class object
{
public:
	typedef
	awl::stream::cell<
		Result
	>
	cell_type;

	typedef
	fcppt::function<
		cell_type ()
	>
	function_type;

	explicit
	object(
		awl::stream::empty const &
	);

	explicit
	object(
		function_type &&
	);

	template<
		typename Function
	>
	explicit
	object(
		Function const &
	);

	typedef
	fcppt::optional::reference<
		Result const
	>
	optional_result_ref;

	optional_result_ref
	get() const;

	typedef
	fcppt::optional::object<
		object
	>
	optional_object;

	optional_object
	pop_front() const;
private:
	typedef
	awl::stream::lazy_function<
		cell_type
	>
	lazy_function_type;

	typedef
	fcppt::shared_ptr<
		lazy_function_type
	>
	shared_ptr_type;

	fcppt::optional::object<
		shared_ptr_type
	>
	impl_;
};

}
}

#endif
