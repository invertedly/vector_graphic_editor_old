#pragma once
#include <string>
#include "figure_id_exception.h"

namespace vector_graphic_editor
{
	class figure_id final
	{
		std::string data_;
	public:
		explicit figure_id(const std::string& s)
			: data_(s)
		{
			if (s.find(']') != std::string::npos)
			{
				throw figure_id_exception("unresolved character");
			}
		}

		bool operator==(const figure_id& other) const noexcept
		{
			return data_ == other.data_;
		}

		[[nodiscard]] const std::string& get() const noexcept { return data_; }
	};
}
