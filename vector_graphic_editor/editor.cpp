#include "editor.h"
#include "editor_command_redo.h"
#include "editor_command_undo.h"

namespace vector_graphic_editor
{
	void clear_stack(std::stack<std::shared_ptr<command_interface>>& stack)
	{
		while (!stack.empty())
		{
			stack.pop();
		}
	}

	void editor::undo()
	{
		if (undo_stack_.empty())
		{
			return;
		}
		const std::shared_ptr<command_interface> command = undo_stack_.top();
		command->undo();
		undo_stack_.pop();
		redo_stack_.push(command);
	}

	void editor::redo()
	{
		while (!redo_stack_.empty())
		{
			const std::shared_ptr<command_interface> command = redo_stack_.top();
			command->redo();
			redo_stack_.pop();
			undo_stack_.push(command);
		}
	}

	editor::editor(std::shared_ptr<command_queue> command_queue): command_queue_(std::move(command_queue))
	{
		if (!command_queue)
		{
			throw editor_exception("empty command queue pointer");
		}
	}

	bool editor::execute_next_command()
	{
		const auto next_command_optional = command_queue_->get_next_command();

		if (!next_command_optional)
		{
			return false;
		}

		if (std::is_convertible_v<std::remove_reference_t<decltype(*next_command_optional.value())>, editor_command_redo>)
		{
			redo();
			return true;
		}

		if (std::is_convertible_v<std::remove_reference_t<decltype(*next_command_optional.value())>, editor_command_undo>)
		{
			undo();
			return true;
		}

		next_command_optional.value()->redo();
		undo_stack_.push(next_command_optional.value());

		clear_stack(redo_stack_);

		return true;
	}
}
