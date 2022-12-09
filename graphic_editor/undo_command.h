#pragma once

#include "command_interface.h"
#include "not_executable_command_exception.h"

namespace vector_graphic_editor
{
	class undo_command : command_interface
	{
	public:
		explicit undo_command() noexcept
			: command_interface(nullptr)
		{
		}

		void execute() override
		{
			throw not_executable_command_exception("undo is not executable");
		}
	};
}