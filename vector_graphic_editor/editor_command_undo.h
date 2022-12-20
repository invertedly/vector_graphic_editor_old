#pragma once

#include "command_interface.h"

namespace vector_graphic_editor
{
	class editor_command_undo final : public command_interface
	{
	public:
		void undo() override {}
		void redo() override {}
	};
}