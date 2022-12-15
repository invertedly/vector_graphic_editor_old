#include "coordinate.h"

#include "angle_converter.h"
#include <cmath>

namespace vector_graphic_editor
{
	void coordinate::rotate(const coordinate invariant_point, const double angle_degrees) noexcept
	{
		const double angle_radians = angle_converter::degrees_to_radians(angle_degrees);

		const double x_relative = x_ - invariant_point.get_x();
		const double y_relative = y_ - invariant_point.get_y();

		const double x_relative_rotated =
			x_relative * std::cos(angle_radians) -
			y_relative * std::sin(angle_radians);

		const double y_relative_rotated =
			x_relative * std::sin(angle_radians) +
			y_relative * std::cos(angle_radians);

		x_ = x_relative_rotated + invariant_point.get_x();
		y_ = y_relative_rotated + invariant_point.get_y();
	}

	void coordinate::translate(const double translate_x, const double translate_y) noexcept
	{
		x_ = x_ + translate_x;
		y_ = y_ + translate_y;
	}

	void coordinate::scale(const coordinate invariant_point, const double scale_x, const double scale_y) noexcept
	{
		x_ =  invariant_point.get_x() + (x_ - invariant_point.get_x()) * scale_x;
		y_ =  invariant_point.get_y() + (y_ - invariant_point.get_y()) * scale_y;
	}
}
