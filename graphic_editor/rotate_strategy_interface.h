#pragma once

#include <memory>

#include "figure.h"

namespace vector_graphic_editor
{
	class rotate_strategy_interface
	{
	protected:
		explicit rotate_strategy_interface() noexcept = default;

	public:
		virtual void execute(
			const std::shared_ptr<figure>& subject, 
			double angle_radians
		) = 0;
		virtual ~rotate_strategy_interface() = default;
	};
}