#pragma once
#include "figure_with_two_coordinates.h"
#include "coordinate.h"

namespace vector_graphic_editor
{
	class rectangle final : public figure_with_two_coordinates
	{
	public:
		explicit rectangle(
			const figure_id& id,
			const coordinate first = {0,0},
			const coordinate second = {0,0}
		)
		noexcept (
			std::is_nothrow_constructible_v<
				figure_with_two_coordinates,
				const figure_id&,
				coordinate,
				coordinate
			>
		)
			: figure_with_two_coordinates(id, first, second)
		{
		}
	};
}
