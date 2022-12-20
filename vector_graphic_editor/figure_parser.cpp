#include "figure_parser.h"

#include <functional>
#include <sstream>

namespace vector_graphic_editor
{
	namespace
	{
		std::unordered_map<std::string, std::function<std::shared_ptr<figure_interface>(std::istream&)>> figure_parser_database;
	}

	figure_parser::figure_parser(std::istream& istream) noexcept: istream_(istream)
	{
	}

	std::optional<std::shared_ptr<figure_interface>> figure_parser::get_next()
	{
		std::string line;
		if (!std::getline(istream_ >> std::ws, line))
		{
			return {};
		}

		std::stringstream ss{ line };

		std::string first_word;

		if (!(ss >> first_word))
		{
			throw figure_parser_exception("wrong input format");
		}

		const size_t delim_pos1 = first_word.find('[');
		const size_t delim_pos2 = first_word.find(']');

		if (delim_pos1 == 0 || delim_pos2 != first_word.size() - 1 || delim_pos1 == std::string::npos || delim_pos2 == std::string::npos)
		{
			throw figure_parser_exception("wrong input format");
		}

		const std::string figure_name = first_word.substr(0, delim_pos1);
		const std::string figure_id = first_word.substr(delim_pos1 + 1);

		//if (figure_parser_database.contains(figure_name))
		//{
		//	return figure_parser_database.at(figure_name)(ss);
		//}

		throw figure_parser_exception("wrong input format");
	}
}
