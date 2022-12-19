#pragma once
#include <exception>
#include <string>

namespace vector_graphic_editor
{
	class invalid_command_exception final : public std::exception
	{
	public:
		explicit invalid_command_exception(const std::string& message) : exception(message.c_str()) {}
	};
}
