#pragma once

#include "rotate_strategy.h"
#include "ellipse.h"

namespace vector_graphic_editor_old
{
	template<typename T>
	requires std::is_convertible_v<T, ellipse>
	class rotate_strategy<T> final : public rotate_strategy_interface
	{
	public:
		void execute(
			const std::shared_ptr<figure>& subject, 
			const double angle_radians
		) override
		{
			const std::shared_ptr<ellipse> ptr =
				std::dynamic_pointer_cast<ellipse>(subject);

			ptr->set_rotation(
				ptr->get_rotation() + angle_radians
			);
		}
	};
}