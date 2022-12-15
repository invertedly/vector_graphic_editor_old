#pragma once
#include <memory>
#include <typeindex>
#include <unordered_map>

#include "figure.h"
#include "figure_id_hash.h"
#include "figure_database_exception.h"

namespace vector_graphic_editor_old
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
		void add(const std::shared_ptr<figure>& item)
		{
			if (contains(item))
			{
				throw figure_database_exception("repetative type and id");
			}

			database_[item->get_id()].insert(
				std::make_pair(std::type_index(typeid(*item)), item)
			);
		}

		[[nodiscard]] bool contains(const std::shared_ptr<figure>& item) const noexcept
		{
			const figure_id id = item->get_id();

			return database_.contains(id) &&
				database_.at(id).contains(std::type_index(typeid(*item)));
		}
	};
}
