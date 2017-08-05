#ifndef AWL_STREAM_CELL_DECL_HPP_INCLUDED
#define AWL_STREAM_CELL_DECL_HPP_INCLUDED

#include <awl/stream/cell_fwd.hpp>
#include <awl/stream/object_decl.hpp>
#include <fcppt/noncopyable.hpp>


namespace awl
{
namespace stream
{

template<
	typename Result
>
class cell
{
	FCPPT_NONCOPYABLE(
		cell
	);
public:
	typedef
	awl::stream::object<
		Result
	>
	stream_type;

	cell(
		Result const &,
		stream_type &&
	);

	cell(
		Result &&,
		stream_type &&
	);

	cell(
		cell &&
	);

	cell &
	operator=(
		cell &&
	);

	~cell();

	Result const &
	value() const;

	stream_type const &
	tail() const;
private:
	Result value_;

	stream_type tail_;
};

}
}

#endif
