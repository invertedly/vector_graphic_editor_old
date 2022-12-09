#pragma once

#include <cmath>

#include "figure_with_two_coordinates.h"
#include "rotate_strategy.h"

namespace vector_graphic_editor
{
	template<typename T>
	requires std::is_convertible_v<T, figure_with_two_coordinates>
	class rotate_strategy_figure_with_two_coordinates : public rotate_strategy_interface
	{
		[[nodiscard]] coordinate get_rotated_coord(
			const coordinate coord,
			const coordinate center,
			const double angle_radians
		) const noexcept
		{
			const double x_relative = coord.get_x() - center.get_x();
			const double y_relative = coord.get_y() - center.get_y();

			const double x_relative_rotated =
				x_relative * std::cos(angle_radians) - 
				y_relative * std::sin(angle_radians);

			const double y_relative_rotated =
				x_relative * std::sin(angle_radians) +
				y_relative * std::cos(angle_radians);

			return {
				x_relative_rotated + center.get_x(),
				y_relative_rotated + center.get_y()
			};
		}

	public:
		void execute(
			const std::shared_ptr<figure>& subject, 
			const double angle_radians
		) override
		{
			const std::shared_ptr<figure_with_two_coordinates> ptr = 
				std::dynamic_pointer_cast<figure_with_two_coordinates>(subject);

			const coordinate center = ptr->get_center_coord();

			ptr->set_first_coord(
				get_rotated_coord(
					ptr->get_first_coord(),
					center,
					angle_radians
				)
			);

			ptr->set_second_coord(
				get_rotated_coord(
					ptr->get_second_coord(),
					center,
					angle_radians
				)
			);
		}
	};
}