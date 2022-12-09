#pragma once
#include <memory>
#include <typeindex>
#include <unordered_map>

#include "figure.h"
#include "figure_id_hash.h"
#include "figure_database_exception.h"

namespace vector_graphic_editor
{
	class figure_database final
	{
		std::unordered_map<
			figure_id,
			std::unordered_map<
				std::type_index,
				std::shared_ptr<figure>
			>,
			figure_id_hash
		> database_;
	public:
		void add(const std::shared_ptr<figure>& item);

		[[nodiscard]] bool contains(const std::shared_ptr<figure>& item) const noexcept;
	};
}
