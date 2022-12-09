#pragma once

#include <memory>

#include <list>
#include "command_interface.h"
#include "undo_command.h"

namespace vector_graphic_editor
{
	class command_pool final
	{
		std::list<std::shared_ptr<command_interface>> pool_;
	public:
		void add(std::shared_ptr<command_interface> command);
		void make_executable();


	};
}
