#pragma once

#include "translate_strategy.h"
#include "ellipse.h"

namespace vector_graphic_editor
{
	template<typename T>
	requires std::is_convertible_v<T, ellipse>
	class translate_strategy<T> final : public translate_strategy_interface
	{
	public:
		void execute(
			const std::shared_ptr<figure>& subject, 
			const double translate_x, 
			const double translate_y
		) override
		{
			const std::shared_ptr<ellipse> ptr = 
				std::dynamic_pointer_cast<ellipse>(subject);

			ptr->set_center(
				translate_coord(
					ptr->get_center(), 
					translate_x, 
					translate_y
				)
			);
		}
	};
}
