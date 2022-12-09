#pragma once

#include "figure_with_two_coordinates.h"
#include "translate_strategy.h"

namespace vector_graphic_editor
{
	template<typename T>
	requires std::is_convertible_v<T, figure_with_two_coordinates>
	class translate_strategy_figure_with_two_coordinates : public translate_strategy_interface
	{
	public:
		void execute(
			const std::shared_ptr<figure>& subject, 
			const double translate_x, 
			const double translate_y
		) override
		{
			const std::shared_ptr<figure_with_two_coordinates> ptr = 
				std::dynamic_pointer_cast<figure_with_two_coordinates>(subject);

			ptr->set_first_coord(
				translate_coord(
					ptr->get_first_coord(), 
					translate_x, 
					translate_y
				)
			);

			ptr->set_second_coord(
				translate_coord(
					ptr->get_second_coord(), 
					translate_x, 
					translate_y
				)
			);
		}
	};
}
