#pragma once

#include "command_interface.h"

namespace vector_graphic_editor
{
	class rotate final : command_interface
	{
		std::shared_ptr<figure_interface> subject_;

		double angle_degrees_;
	public:
		explicit rotate(
			std::shared_ptr<figure_interface> subject,
			double angle_degrees
		) noexcept;

		void redo() override;

		void undo() override;
	};
}
