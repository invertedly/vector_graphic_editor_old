#pragma once

#include "coordinate.h"
#include "figure_interface.h"

namespace vector_graphic_editor
{
	class rectangle final : public figure_interface
	{
		coordinate first_, second_;

		[[nodiscard]] coordinate get_center() const noexcept;

	public:
		explicit rectangle(
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