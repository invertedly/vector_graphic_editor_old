#include "command_pool.h"

namespace vector_graphic_editor_old
{
	void command_pool::add(std::shared_ptr<command_interface> command)
	{
		pool_.emplace_back(std::move(command));
	}

	void command_pool::make_executable()
	{
		size_t remove_counter = 0;
		for (auto iter = pool_.rbegin(); iter != pool_.rend(); ++iter)
		{
			if (std::is_convertible_v<
					std::remove_reference_t<decltype(* *iter)>,
					undo_command
					>
			)
			{
				++remove_counter;
				//remove undo command
			}
			else if (remove_counter--)
			{
				//remove command
			}
		}
	}
}
