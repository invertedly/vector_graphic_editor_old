#pragma once

namespace vector_graphic_editor
{
	class coordinate final
	{
		double x_;
		double y_;

	public:
		coordinate(const double x = 0, const double y = 0) noexcept
			: x_(x),
			  y_(y)
		{
		}

		[[nodiscard]] double get_x() const noexcept { return x_; }
		[[nodiscard]] double get_y() const noexcept { return y_; }

		void set_x(const double x) noexcept { x_ = x; }
		void set_y(const double y) noexcept { y_ = y; }

		void rotate(coordinate invariant_point, double angle_degrees)			noexcept;
		void translate(double translate_x, double translate_y)					noexcept;
		void scale(coordinate invariant_point, double scale_x, double scale_y)	noexcept;
	};
}