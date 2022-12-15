#include "ellipse.h"
#include "angle_converter.h"
#include <cmath>

namespace vector_graphic_editor
{
	[[nodiscard]] double get_scaled_axis(
		const double axis_len,
		const double angle_degrees,
		const double cos_projection_scale,
		const double sin_projection_scale
	) noexcept
	{
		const double angle_radians = angle_converter::degrees_to_radians(angle_degrees);

		return axis_len * sqrt(
			std::pow(std::cos(angle_radians) * cos_projection_scale, 2) +
			std::pow(std::sin(angle_radians) * sin_projection_scale, 2)
		);
	}

	void ellipse::translate(const double translate_x, const double translate_y) noexcept
	{
		center_.translate(translate_x, translate_y);
	}

	void ellipse::scale(const double scale_x, const double scale_y) noexcept
	{
		axis1_ = get_scaled_axis(axis1_, angle_degrees_, scale_x, scale_y);
		axis2_ = get_scaled_axis(axis2_, angle_degrees_, scale_y, scale_x);
	}

	void ellipse::rotate(const double angle_degrees) noexcept
	{
		angle_degrees_ += angle_degrees;
	}

	coordinate ellipse::get_center() const noexcept
	{
		return center_;
	}

	double ellipse::get_angle_degrees() const noexcept
	{
		return angle_degrees_;
	}

	double ellipse::get_axis1() const noexcept
	{
		return axis1_;
	}

	double ellipse::get_axis2() const noexcept
	{
		return axis2_;
	}
}
