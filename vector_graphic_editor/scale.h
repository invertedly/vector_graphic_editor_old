#pragma once

#include "command_interface.h"

namespace vector_graphic_editor
{
	class scale final : public command_interface
	{
		std::shared_ptr<figure_interface> subject_;

		double scale_x_, scale_y_;
	public:
		explicit scale(
			std::shared_ptr<figure_interface> subject,
			double scale_x,
			double scale_y
		);

		void redo() override;

		void undo() override;
	};
}