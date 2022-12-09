#pragma once
#include <memory>

#include "figure.h"

namespace vector_graphic_editor
{
	class scale_strategy_interface
	{
	protected:
		explicit scale_strategy_interface() noexcept = default;

	public:
		virtual void execute(
			const std::shared_ptr<figure>& subject, 
			double scale_x, 
			double scale_y
		) = 0;
		virtual ~scale_strategy_interface() = default;
	};
}
