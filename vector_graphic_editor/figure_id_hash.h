#pragma once

#include "figure_id.h"

namespace vector_graphic_editor
{
	struct figure_id_hash final
	{
        std::size_t operator()(figure_id const& object) const noexcept
        {
            return std::hash<std::string>{}(object.get_type_id() + object.get_user_id());
        }
	};
}
