#pragma once

#include <numbers>

namespace vector_graphic_editor_old
{
	class coordinate final
	{
		double x_;
		double y_;

	public:
		coordinate(const double x, const double y) noexcept
			: x_(x),
			  y_(y)
		{
		}

		[[nodiscard]] double get_x() const noexcept { return x_; }
		[[nodiscard]] double get_y() const noexcept { return y_; }

		void set_x(const double x) noexcept { x_ = x; }
		void set_y(const double y) noexcept { y_ = y; }

		void rotate(
			const coordinate pivot,
			const double angle_degrees
		) noexcept
		{
			const double angle_radians = angle_degrees / 180 * std::numbers::pi;

			const double x_relative = x_ - pivot.get_x();
			const double y_relative = y_ - pivot.get_y();

			const double x_relative_rotated =
				x_relative * std::cos(angle_radians) -
				y_relative * std::sin(angle_radians);

			const double y_relative_rotated =
				x_relative * std::sin(angle_radians) +
				y_relative * std::cos(angle_radians);

			x_ = x_relative_rotated + pivot.get_x();
			y_ = y_relative_rotated + pivot.get_y();
		}
	};
}