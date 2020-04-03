#ifndef AWL_BACKENDS_X11_WINDOW_ORIGINAL_CLASS_HINT_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_ORIGINAL_CLASS_HINT_HPP_INCLUDED

#include <awl/backends/x11/window/class_hint.hpp>
#include <awl/detail/symbol.hpp>
#include <fcppt/nonmovable.hpp>
#include <fcppt/unique_ptr_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xutil.h>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace window
{

class original_class_hint
{
	FCPPT_NONMOVABLE(
		original_class_hint
	);
public:
	AWL_DETAIL_SYMBOL
	explicit
	original_class_hint(
		awl::backends::x11::window::class_hint &&
	);

	AWL_DETAIL_SYMBOL
	~original_class_hint();

	[[nodiscard]]
	AWL_DETAIL_SYMBOL
	XClassHint *
	get() const;

	[[nodiscard]]
	AWL_DETAIL_SYMBOL
	awl::backends::x11::window::class_hint const &
	hint() const;
private:
	class impl;

	fcppt::unique_ptr<
		impl
	> const impl_;

	awl::backends::x11::window::class_hint const hint_;
};

}
}
}
}

#endif
