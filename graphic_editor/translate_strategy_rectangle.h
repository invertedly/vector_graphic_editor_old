#pragma once

#include "translate_strategy_figure_with_two_coordinates.h"
#include "rectangle.h"

namespace vector_graphic_editor_old
{
	template<typename T>
	requires std::is_convertible_v<T, rectangle>
	class translate_strategy<T> final : public translate_strategy_figure_with_two_coordinates<T>
	{
	};
}