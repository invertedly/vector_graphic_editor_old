#include "rectangle.h"

namespace vector_graphic_editor
{
	coordinate rectangle::get_center() const noexcept
	{
		return coordinate{
			(first_.get_x() + second_.get_x()) / 2,
			(first_.get_y() + second_.get_y()) / 2
		};
	}

	void rectangle::translate(const double translate_x, const double translate_y) noexcept
	{
		first_.translate(translate_x, translate_y);
		second_.translate(translate_x, translate_y);
	}

	void rectangle::scale(const double scale_x, const double scale_y) noexcept
	{
		const coordinate center = get_center();
		first_.scale(center, scale_x, scale_y);
		second_.scale(center, scale_x, scale_y);
	}

	void rectangle::rotate(const double angle_degrees) noexcept
	{
		const coordinate center = get_center();
		first_.rotate(center, angle_degrees);
		second_.rotate(center, angle_degrees);
	}
	coordinate rectangle::get_first() const noexcept
	{
		return first_;
	}
	coordinate rectangle::get_second() const noexcept
	{
		return second_;
	}
}
