#pragma once

#include "figure_interface.h"
#include "coordinate.h"

namespace vector_graphic_editor
{
	class line final : public figure_interface
	{
		coordinate first_, second_;

		[[nodiscard]] coordinate get_center() const noexcept;

	public:
		explicit line(
			const coordinate first, 
			const coordinate second
		) noexcept
			: first_(first),
			  second_(second)
		{
		}

		void translate(double translate_x, double translate_y)	noexcept override;
		void scale(double scale_x, double scale_y)				noexcept override;
		void rotate(double angle_degrees)						noexcept override;

		[[nodiscard]] coordinate get_first()	const noexcept;
		[[nodiscard]] coordinate get_second()	const noexcept;
	};
}