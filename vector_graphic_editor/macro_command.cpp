#include "macro_command.h"
#include "invalid_command_exception.h"

namespace vector_graphic_editor
{
	void macro_command::redo()
	{
		for (auto iter = command_list_.begin(); iter != command_list_.end(); ++iter)
		{
			(*iter)->redo();
		}
	}

	void macro_command::undo()
	{
		for (auto iter = command_list_.rbegin(); iter != command_list_.rend(); ++iter)
		{
			(*iter)->undo();
		}
	}

	void macro_command::add(std::unique_ptr<command_interface> command)
	{
		if (!command)
		{
			throw invalid_command_exception("empty command pointer");
		}

		command_list_.push_back(std::move(command));
	}
}
