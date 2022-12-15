#pragma once

#include "coordinate.h"
#include "figure_interface.h"

namespace vector_graphic_editor
{
	class ellipse final : public figure_interface
	{
		coordinate center_;
		double axis1_, axis2_, angle_degrees_;
	public:
		explicit ellipse(
			const coordinate center,
			const double axis1,
			const double axis2,
			const double angle_degrees
		) noexcept
			: center_(center),
			  axis1_(axis1),
			  axis2_(axis2),
			  angle_degrees_(angle_degrees)
		{
		}

		void translate(double translate_x, double translate_y)	noexcept override;
		void scale(double scale_x, double scale_y)				noexcept override;
		void rotate(double angle_degrees)						noexcept override;

		[[nodiscard]] coordinate get_center()			const noexcept;
		[[nodiscard]] double get_angle_degrees()		const noexcept;
		[[nodiscard]] double get_axis1()				const noexcept;
		[[nodiscard]] double get_axis2()				const noexcept;
	};
}