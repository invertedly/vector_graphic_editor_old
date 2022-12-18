#pragma once

#include "command_interface.h"

namespace vector_graphic_editor
{
	class translate final : public command_interface
	{
		std::shared_ptr<figure_interface> subject_;

		double translate_x_, translate_y_;
	public:
		explicit translate(
			std::shared_ptr<figure_interface> subject,
			double translate_x,
			double translate_y
		) noexcept;

		void redo() override;

		void undo() override;
	};
}