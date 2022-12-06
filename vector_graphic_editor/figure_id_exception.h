#pragma once
#include <exception>
#include <string>

namespace vector_graphic_editor
{
	class figure_id_exception final : public std::exception
	{
	public:
		explicit figure_id_exception(const std::string& message) : exception(message.c_str()) {}
	};
}
