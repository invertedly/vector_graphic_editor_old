#pragma once
#include <memory>

#include "coordinate.h"
#include "figure.h"

namespace vector_graphic_editor_old
{
	class translate_strategy_interface
	{
	protected:
		translate_strategy_interface() = default;

		[[nodiscard]] coordinate translate_coord(
			const coordinate old_coord, 
			const double translate_x, 
			const double translate_y
		) const noexcept
		{
			return coordinate{ old_coord.get_x() + translate_x, old_coord.get_y() + translate_y };
		}

	public:
		virtual void execute(
			const std::shared_ptr<figure>& subject, 
			double dx, 
			double dy
		) = 0;
		virtual ~translate_strategy_interface() = default;
	};
}
