#ifndef AWL_BACKENDS_WINDOWS_WINDOW_ORIGINAL_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_WINDOW_ORIGINAL_OBJECT_HPP_INCLUDED

#include <awl/class_symbol.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/wndclass_fwd.hpp>
#include <awl/backends/windows/wndclass_remove_callback.hpp>
#include <awl/backends/windows/cursor/const_optional_object_ref.hpp>
#include <awl/backends/windows/system/event/original_processor_fwd.hpp>
#include <awl/backends/windows/window/holder.hpp>
#include <awl/backends/windows/window/object.hpp>
#include <awl/backends/windows/window/event/processor_fwd.hpp>
#include <awl/backends/windows/window/event/scoped_processor.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/visual/object_fwd.hpp>
#include <awl/window/dim_fwd.hpp>
#include <awl/window/object.hpp>
#include <awl/window/parameters_fwd.hpp>
#include <awl/window/event/processor_fwd.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/unique_ptr_impl.hpp>


namespace awl
{
namespace backends
{
namespace windows
{
namespace window
{

class AWL_CLASS_SYMBOL original_object
:
	public awl::backends::windows::window::object,
	public awl::window::object
{
	FCPPT_NONCOPYABLE(
		original_object
	);
public:
	AWL_DETAIL_SYMBOL
	original_object(
		awl::window::parameters const &,
		awl::backends::windows::system::event::original_processor &,
		awl::backends::windows::wndclass &,
		awl::backends::windows::wndclass_remove_callback const &
	);

	AWL_DETAIL_SYMBOL
	~original_object()
	override;

	AWL_DETAIL_SYMBOL
	void
	show()
	override;

	AWL_DETAIL_SYMBOL
	awl::window::dim
	size() const
	override;

	AWL_DETAIL_SYMBOL
	awl::visual::object const &
	visual() const
	override;

	AWL_DETAIL_SYMBOL
	awl::window::event::processor &
	processor()
	override;

	AWL_DETAIL_SYMBOL
	HWND
	hwnd() const
	override;

	AWL_DETAIL_SYMBOL
	awl::backends::windows::cursor::const_optional_object_ref
	cursor() const
	override;
private:
	awl::visual::object const &visual_;

	awl::backends::windows::window::holder const holder_;

	awl::backends::windows::cursor::const_optional_object_ref const cursor_;

	fcppt::unique_ptr<
		awl::backends::windows::window::event::processor
	> const processor_;

	awl::backends::windows::window::event::scoped_processor const scoped_processor_;
};

}
}
}
}

#endif
