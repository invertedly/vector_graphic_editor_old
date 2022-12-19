#pragma once
#include <string>
#include <typeinfo>
#include <typeindex>
#include "figure_interface.h"
#include "figure_id_exception.h"

namespace vector_graphic_editor
{
	class figure_id final
	{
		std::string type_id_;
		std::string user_id_;
	public:
		explicit figure_id(
			std::string figure_type_id,
			std::string user_id
		);

		bool operator==(const figure_id& other) const noexcept;

		[[nodiscard]] const std::string& get_user_id() const noexcept;
		[[nodiscard]] const std::string& get_type_id() const noexcept;
	};
}
