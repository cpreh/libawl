#ifndef AWL_BACKENDS_X11_WINDOW_ORIGINAL_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_ORIGINAL_OBJECT_HPP_INCLUDED

#include <awl/backends/x11/atom.hpp>
#include <awl/backends/x11/colormap.hpp>
#include <awl/backends/x11/display_fwd.hpp>
#include <awl/backends/x11/screen.hpp>
#include <awl/backends/x11/system/event/original_processor_fwd.hpp>
#include <awl/backends/x11/visual/object_fwd.hpp>
#include <awl/backends/x11/window/const_optional_class_hint_ref_fwd.hpp>
#include <awl/backends/x11/window/hints.hpp>
#include <awl/backends/x11/window/holder.hpp>
#include <awl/backends/x11/window/object.hpp>
#include <awl/backends/x11/window/original_class_hint.hpp>
#include <awl/backends/x11/window/original_object_fwd.hpp>
#include <awl/backends/x11/window/rect_fwd.hpp>
#include <awl/backends/x11/window/event/mask.hpp>
#include <awl/backends/x11/window/event/mask_bit.hpp>
#include <awl/backends/x11/window/event/type.hpp>
#include <awl/backends/x11/window/event/wm_protocols.hpp>
#include <awl/detail/class_symbol.hpp>
#include <awl/detail/symbol.hpp>
#include <awl/event/connection_unique_ptr.hpp>
#include <awl/window/parameters_fwd.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/unique_ptr_impl.hpp>
#include <fcppt/optional/object_decl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <map>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace window
{

class AWL_DETAIL_CLASS_SYMBOL original_object
:
	public awl::backends::x11::window::object
{
	FCPPT_NONCOPYABLE(
		original_object
	);
public:
	AWL_DETAIL_SYMBOL
	original_object(
		awl::backends::x11::display &,
		awl::backends::x11::screen,
		awl::backends::x11::system::event::original_processor &,
		awl::window::parameters const &
	);

	AWL_DETAIL_SYMBOL
	~original_object()
	override;

	AWL_DETAIL_SYMBOL
	bool
	destroyed() const
	override;

	AWL_DETAIL_SYMBOL
	awl::backends::x11::display &
	display() const
	override;

	AWL_DETAIL_SYMBOL
	awl::backends::x11::screen
	screen() const
	override;

	AWL_DETAIL_SYMBOL
	awl::backends::x11::visual::object const &
	x11_visual() const
	override;

	AWL_DETAIL_SYMBOL
	awl::backends::x11::window::rect
	rect() const
	override;

	AWL_DETAIL_SYMBOL
	Window
	get() const
	override;

	AWL_DETAIL_SYMBOL
	awl::backends::x11::window::const_optional_class_hint_ref
	class_hint() const
	override;

	AWL_DETAIL_SYMBOL
	void
	destroy();

	awl::event::connection_unique_ptr
	register_event(
		awl::backends::x11::window::event::type
	)
	override;

	awl::event::connection_unique_ptr
	add_event_mask(
		awl::backends::x11::window::event::mask
	)
	override;
private:
	void
	unregister_event(
		awl::backends::x11::window::event::type
	);

	void
	remove_event_mask(
		awl::backends::x11::window::event::mask
	);

	void
	add_mask_bit(
		awl::backends::x11::window::event::mask_bit
	);

	void
	remove_mask_bit(
		awl::backends::x11::window::event::mask_bit
	);

	awl::backends::x11::display &display_;

	awl::backends::x11::screen const screen_;

	awl::backends::x11::visual::object const &visual_;

	awl::backends::x11::colormap const colormap_;

	awl::backends::x11::window::hints const hints_;

	typedef
	fcppt::unique_ptr<
		awl::backends::x11::window::original_class_hint
	>
	original_class_hint_unique_ptr;

	typedef
	fcppt::optional::object<
		original_class_hint_unique_ptr
	>
	optional_original_class_hint_unique_ptr;

	optional_original_class_hint_unique_ptr const class_hint_;

	awl::backends::x11::window::holder window_;

	awl::event::connection_unique_ptr const processor_connection_;

	typedef
	unsigned
	mask_count;

	typedef
	std::map<
		awl::backends::x11::window::event::mask_bit,
		mask_count
	>
	mask_count_map;

	mask_count_map mask_counts_;

	awl::backends::x11::window::event::mask event_mask_;

	awl::backends::x11::window::event::wm_protocols const wm_protocols_;

	awl::event::connection_unique_ptr const client_message_connection_;

	awl::event::connection_unique_ptr const configure_connection_;

	awl::event::connection_unique_ptr const destroy_connection_;

	awl::event::connection_unique_ptr const map_connection_;

	awl::event::connection_unique_ptr const unmap_connection_;
};

}
}
}
}

#endif
