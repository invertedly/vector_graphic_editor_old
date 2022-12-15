#pragma once
#include "figure.h"
#include "coordinate.h"

namespace vector_graphic_editor_old
{
	class figure_with_two_coordinates : public figure
	{
		coordinate first_;
		coordinate second_;

	public:
		explicit figure_with_two_coordinates(
			const figure_id& id,
			const coordinate first = { 0,0 },
			const coordinate second = { 0,0 }
		)
		noexcept (std::is_nothrow_constructible_v<figure_id, const figure_id&>)
			: figure(id),
			  first_(first),
			  second_(second)
		{
		}

		[[nodiscard]] coordinate get_first_coord()	const noexcept { return first_; }
		[[nodiscard]] coordinate get_second_coord()	const noexcept { return second_; }
		[[nodiscard]] coordinate get_center_coord() const noexcept
		{
			const double x_center = (first_.get_x() + second_.get_x()) / 2;
			const double y_center = (first_.get_y() + second_.get_y()) / 2;
			return coordinate{x_center, y_center};
		}
		void set_first_coord(const coordinate point)	noexcept { first_ = point; }
		void set_second_coord(const coordinate point)	noexcept { second_ = point; }

		~figure_with_two_coordinates() override = default;
	};
}