#pragma once
#include <numbers>

namespace vector_graphic_editor
{
	class angle_converter final
	{
	public:
		static double degrees_to_radians(const double angle_degrees) noexcept
		{
			return angle_degrees / 180 * std::numbers::pi;
		}
	};
}
