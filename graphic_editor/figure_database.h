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
			std::unordered_map<std::type_index, std::shared_ptr<figure>>,
			figure_id_hash
		> database_;
	public:
		void add(const std::shared_ptr<figure>& item)
		{
			if (has(item))
			{
				throw figure_database_exception("repetative type and id");
			}

			database_[item->get_id()].insert(std::make_pair(std::type_index(typeid(*item)), item));
		}

		bool has(const std::shared_ptr<figure>& item) const noexcept
		{
			return database_.contains(item->get_id()) && database_.at(item->get_id()).contains(std::type_index(typeid(*item)));
		}
	};
}
