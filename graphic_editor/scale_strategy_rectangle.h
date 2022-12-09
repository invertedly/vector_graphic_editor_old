#pragma once

#include "scale_strategy_figure_with_two_coordinates.h"
#include "rectangle.h"

namespace vector_graphic_editor
{
	template<typename T>
	requires std::is_convertible_v<T, rectangle>
	class scale_strategy<T> final : public scale_strategy_figure_with_two_coordinates<T>
	{
	};
}