#pragma once

#include <vector>
#include <memory>
#include "command_interface.h"

#include "rotate.h"

namespace vector_graphic_editor
{
	class macro_command final : public command_interface
	{
		std::vector<std::unique_ptr<command_interface>> command_list_;
	public:
		explicit macro_command() = default;

		void add(std::unique_ptr<command_interface> command);

		void redo() override;
		void undo() override;
	};
}
