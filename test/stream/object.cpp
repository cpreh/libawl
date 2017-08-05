#include <awl/stream/cell_impl.hpp>
#include <awl/stream/object_impl.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


namespace
{

awl::stream::object<
	unsigned
>
ints_from(
	unsigned const _value
)
{
	return
		awl::stream::object<
			unsigned
		>(
			[
				_value
			]{
				return
					awl::stream::cell<
						unsigned
					>{
						_value,
						ints_from(
							_value
							+
							1u
						)
					};
			}
		);
}

}

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	stream_object
)
{
FCPPT_PP_POP_WARNING

	awl::stream::object<
		unsigned
	> const stream{
		ints_from(
			5u
		)
	};

	BOOST_CHECK_EQUAL(
		stream.get().get_unsafe().get(),
		5u
	);

	awl::stream::object<
		unsigned
	> const rest{
		stream.pop_front().get_unsafe()
	};

	BOOST_CHECK_EQUAL(
		6u,
		rest.get().get_unsafe().get()
	);
}
