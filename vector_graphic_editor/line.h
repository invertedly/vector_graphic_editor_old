#pragma once
#include "figure.h"
#include "coordinate.h"

namespace vector_graphic_editor
{
	class line final : public figure
	{
		coordinate first_;
		coordinate second_;

	public:
		explicit line(
			const figure_id& id,
			const coordinate first = { 0,0 },
			const coordinate second = { 0,0 }
		) : figure(id), first_(first), second_(second) {}

		coordinate get_first_coord() const noexcept { return first_; }
		coordinate get_second_coord() const noexcept { return second_; }

		void set_first_coord(const coordinate point) noexcept { first_ = point; }
		void set_second_coord(const coordinate point) noexcept { second_ = point; }
	};
}