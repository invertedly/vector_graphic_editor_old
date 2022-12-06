#pragma once
#include <exception>
#include <string>

namespace vector_graphic_editor
{
	class figure_database_exception final : public std::exception
	{
	public:
		explicit figure_database_exception(const std::string& message) : exception(message.c_str()) {}
	};
}
