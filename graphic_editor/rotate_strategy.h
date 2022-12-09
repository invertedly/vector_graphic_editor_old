#pragma once

#include "rotate_strategy_interface.h"

namespace vector_graphic_editor
{
	template<typename T>
	requires std::is_convertible_v<T, figure>
	class rotate_strategy;
}