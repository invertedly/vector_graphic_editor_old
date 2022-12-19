#include "figure_id.h"

namespace vector_graphic_editor
{
	figure_id::figure_id(std::string figure_type_id, std::string user_id): type_id_(std::move(figure_type_id)),
	                                                                       user_id_(std::move(user_id))
	{
		if (user_id_.find(']') != std::string::npos)
		{
			throw figure_id_exception("unresolved character user id");
		}
	}

	bool figure_id::operator==(const figure_id& other) const noexcept
	{
		return user_id_ == other.user_id_ && type_id_ == other.type_id_;
	}

	const std::string& figure_id::get_user_id() const noexcept
	{
		return user_id_;
	}

	const std::string& figure_id::get_type_id() const noexcept
	{
		return type_id_;
	}
}
