#pragma once

#include "command_interface.h"

namespace vector_graphic_editor
{
	class editor_command_redo final : public command_interface
	{
	public:
		void undo() override {}
		void redo() override {}
	};
}