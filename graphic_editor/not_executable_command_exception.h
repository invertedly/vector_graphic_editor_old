#pragma once
#include <exception>
#include <string>

namespace vector_graphic_editor_old
{
	class not_executable_command_exception final : public std::exception
	{
	public:
		explicit not_executable_command_exception(const std::string& message)
			: exception(message.c_str())
		{
		}
	};
}
