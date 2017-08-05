#include <awl/stream/lazy_function_impl.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

BOOST_AUTO_TEST_CASE(
	stream_lazy_function
)
{
FCPPT_PP_POP_WARNING

	typedef
	awl::stream::lazy_function<
		int
	>
	lazy_int;

	lazy_int const function{
		[]()
		{
			static int val{
				0
			};

			return
				val++;
		}
	};

	BOOST_CHECK_EQUAL(
		function.get(),
		0
	);

	BOOST_CHECK_EQUAL(
		function.get(),
		0
	);
}
