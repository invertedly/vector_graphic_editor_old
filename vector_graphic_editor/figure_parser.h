#pragma once

#include <istream>
#include <optional>
#include "figure_interface.h"
#include "figure_parser_exception.h"

namespace vector_graphic_editor
{
	class figure_parser final
	{
		std::istream& istream_;
	public:
		explicit figure_parser(std::istream& istream) noexcept;
		std::optional<std::shared_ptr<figure_interface>> get_next();
	};
}