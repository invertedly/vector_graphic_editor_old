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
		std::string user_id_;
	public:
		explicit figure_id(std::string user_id)
			: user_id_(std::move(user_id))
		{
			if (user_id_.find(']') != std::string::npos)
			{
				throw figure_id_exception("unresolved character");
			}
		}

		bool operator==(const figure_id& other) const noexcept
		{
			return user_id_ == other.user_id_;
		}

		[[nodiscard]] const std::string& get() const noexcept { return user_id_; }
	};
}
