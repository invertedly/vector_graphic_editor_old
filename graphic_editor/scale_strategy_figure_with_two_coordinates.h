#pragma once

#include "figure_with_two_coordinates.h"
#include "scale_strategy.h"

namespace vector_graphic_editor
{
	template<typename T>
	requires std::is_convertible_v<T, figure_with_two_coordinates>
	class scale_strategy_figure_with_two_coordinates : public scale_strategy_interface
	{
		[[nodiscard]] coordinate get_scaled_coord(
			const coordinate center,
			const coordinate coord,
			const double scale_x,
			const double scale_y
		) const noexcept
		{
			auto scale = [](
				const double center, 
				const double coord,
				const double scale
				)
			{
				return center + (coord - center) * scale;
			};

			return {
				scale(center.get_x(), coord.get_x(), scale_x),
				scale(center.get_y(), coord.get_y(), scale_y)
			};
		}

	public:
		void execute(
			const std::shared_ptr<figure>& subject, 
			const double scale_x, 
			const double scale_y
		) override
		{
			const std::shared_ptr<figure_with_two_coordinates> ptr = 
				std::dynamic_pointer_cast<figure_with_two_coordinates>(subject);

			const coordinate center = ptr->get_center_coord();

			ptr->set_first_coord(
				get_scaled_coord(
					center,
					ptr->get_first_coord(),
					scale_x,
					scale_y
				)
			);

			ptr->set_second_coord(
				get_scaled_coord(
					center,
					ptr->get_second_coord(),
					scale_x,
					scale_y
				)
			);
		}
	};
}