#pragma once

#include <stack>
#include "editor_exception.h"
#include "command_queue.h"

namespace vector_graphic_editor
{
	class editor final
	{
		std::stack<std::shared_ptr<command_interface>> undo_stack_;
		std::stack<std::shared_ptr<command_interface>> redo_stack_;
		std::shared_ptr<command_queue> command_queue_;
		void undo();
		void redo();
	public:
		explicit editor(std::shared_ptr<command_queue> command_queue);
		bool execute_next_command();
	};
}