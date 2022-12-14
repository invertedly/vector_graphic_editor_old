#pragma once
#include <exception>
#include <string>

namespace vector_graphic_editor
{
	class figure_collection_exception final : public std::exception
	{
	public:
		explicit figure_collection_exception(const std::string& message) : exception(message.c_str()) {}
	};
}
