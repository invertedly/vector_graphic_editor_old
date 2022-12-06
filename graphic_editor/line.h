#pragma once
#include "figure_with_two_coordinates.h"
#include "coordinate.h"

namespace vector_graphic_editor
{
	class line final : public figure_with_two_coordinates
	{
	public:
		explicit line(
			const figure_id& id,
			const coordinate first = {0,0},
			const coordinate second = {0,0}
		) : figure_with_two_coordinates(id, first, second)
		{
		}
	};
}