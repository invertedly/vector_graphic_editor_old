#include "command_queue.h"
#include "invalid_command_exception.h"

namespace vector_graphic_editor
{
	void command_queue::add_command(std::shared_ptr<command_interface> command)
	{
		if (!command)
		{
			throw invalid_command_exception("empty command pointer");
		}
		command_queue_.push(std::move(command));
	}

	std::optional<std::shared_ptr<command_interface>> command_queue::get_next_command()
	{
		if (command_queue_.empty())
		{
			return {};
		}

		std::shared_ptr<command_interface> return_value = command_queue_.front();

		command_queue_.pop();

		return return_value;
	}

	bool command_queue::empty() const noexcept
	{
		return command_queue_.empty();
	}
}
