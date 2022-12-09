#pragma once

#include "scale_strategy.h"
#include "ellipse.h"

namespace vector_graphic_editor
{
	template<typename T>
	requires std::is_convertible_v<T, ellipse>
	class scale_strategy<T> final : public scale_strategy_interface
	{
		[[nodiscard]] double get_scaled_axis(
			const double axis_len,
			const double angle,
			const double cos_projection_scale,
			const double sin_projection_scale
		) const noexcept
		{
			return axis_len * sqrt(
				std::pow(std::cos(angle) * cos_projection_scale, 2) +
				std::pow(std::sin(angle) * sin_projection_scale, 2)
			);
		}

	public:
		void execute(
			const std::shared_ptr<figure>& subject, 
			const double scale_x, 
			const double scale_y
		) override
		{
			const std::shared_ptr<ellipse> ptr = 
				std::dynamic_pointer_cast<ellipse>(subject);

			ptr->set_axis1_len(
				get_scaled_axis(
					ptr->get_axis1_len(),
					ptr->get_rotation(),
					scale_x,
					scale_y
				)
			);

			ptr->set_axis2_len(
				get_scaled_axis(
					ptr->get_axis2_len(),
					ptr->get_rotation(),
					scale_y,
					scale_x
				)
			);
		}
	};
}