#pragma once
#include <memory>
#include <unordered_map>

#include "figure_interface.h"
#include "figure_id_hash.h"
#include "figure_collection_exception.h"

namespace vector_graphic_editor
{
	class figure_collection final
	{
		std::unordered_map<
			figure_id,
			std::shared_ptr<figure_interface>,
			figure_id_hash
		> database_;
	public:
		void add(
			const figure_id& id,
			const std::shared_ptr<figure_interface>& figure_ptr
		);

		[[nodiscard]] bool contains(const figure_id& id) const noexcept;
		[[nodiscard]] std::shared_ptr<figure_interface>& get(const figure_id& id);

		auto begin() noexcept;
		auto end() noexcept;
	};
}
