#pragma once

namespace vector_graphic_editor
{
	class coordinate final
	{
		double x_;
		double y_;

	public:
		coordinate(const double x, const double y) noexcept: x_(x), y_(y) {}

		double get_x() const noexcept { return x_; }
		double get_y() const noexcept { return y_; }

		void set_x(const double x) noexcept { x_ = x; }
		void set_y(const double y) noexcept { y_ = y; }
	};
}