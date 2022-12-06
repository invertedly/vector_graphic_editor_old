#pragma once
#include "figure.h"
#include "coordinate.h"

namespace vector_graphic_editor
{
	class ellipse final : public figure
	{
		coordinate center_;
		double height_;
		double width_;
		double rotation_;
	public:
		explicit ellipse(
			const figure_id& id,
			const coordinate center = { 0,0 },
			const double height = 0,
			const double width = 0,
			const double rotation = 0
		) : figure(id), center_(center), height_(height), width_(width), rotation_(rotation) {}

		coordinate get_center() const noexcept { return center_; }
		double get_height() const noexcept { return height_; }
		double get_width() const noexcept { return width_; }
		double get_rotation() const noexcept { return rotation_; }

		void set_center(const coordinate center) noexcept { center_ = center; }
		void set_height(const double height) noexcept { height_ = height; }
		void set_width(const double width) noexcept { width_ = width; }
		void set_rotation(const double rotation) noexcept { rotation_ = rotation; }
	};
}
