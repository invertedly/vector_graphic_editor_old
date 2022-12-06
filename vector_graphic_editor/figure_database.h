#pragma once
#include <memory>
#include <unordered_map>

#include "figure_id.h"
#include "figure.h"
#include "figure_database_exception.h"

namespace vector_graphic_editor
{
	class figure_database final
	{
		std::unordered_multimap<figure_id, std::shared_ptr<figure>> database_;
	public:

		template< typename T >
		requires std::is_convertible_v<T, figure>
		void add(T&& item)
		{
			const auto range = database_.equal_range(item.get_id());

			for (auto iter = range.first; iter != range.second; ++iter)
			{
				if (std::is_convertible_v<decltype(*iter), T>)
				{
					throw figure_database_exception("repetative type and id");
				}
			}

			database_.insert(std::make_pair(item.get_id(), std::make_shared<figure>(std::forward<T>(item))));
		}
	};
}
