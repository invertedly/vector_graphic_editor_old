#pragma once
#include <exception>
#include <string>

namespace vector_graphic_editor
{
	class editor_exception final : public std::exception
	{
	public:
		explicit editor_exception(const std::string& message) : exception(message.c_str()) {}
	};
}
