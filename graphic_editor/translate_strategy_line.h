#pragma once

#include "translate_strategy_figure_with_two_coordinates.h"
#include "line.h"

namespace vector_graphic_editor
{
	template<typename T>
	requires std::is_convertible_v<T, line>
	class translate_strategy<T> final : public translate_strategy_figure_with_two_coordinates<T>
	{
	};
}