#pragma once

#include <optional>
#include <queue>
#include "command_interface.h"

namespace vector_graphic_editor
{
	class command_queue final
	{
		std::queue<std::shared_ptr<command_interface>> command_queue_;
	public:
		void add_command(std::shared_ptr<command_interface> command);
		std::optional<std::shared_ptr<command_interface>> get_next_command();
		[[nodiscard]] bool empty() const noexcept;
	};
}