#pragma once
#include <memory>
#include <typeindex>
#include <unordered_map>
#include <iterator>

#include "figure_interface.h"
#include "figure_id_hash.h"

namespace vector_graphic_editor
{
	class figure_database final
	{
		std::unordered_map<
			figure_id,
			std::unordered_map<
				std::type_index,
				std::shared_ptr<figure_interface>
			>,
			figure_id_hash
		> database_;
	public:
		void add(
			const std::shared_ptr<figure_interface>& figure_ptr, 
			const figure_id& id
		);

		[[nodiscard]] bool contains(
			const figure_id& id,
			const std::type_index& figure_type_index
		) const noexcept;

		[[nodiscard]] std::shared_ptr<figure_interface>& get(
			const figure_id& id,
			const std::type_index& figure_type_index
		);

		class iterator final
		{
			using outer_iterator_t = decltype(database_)::iterator;
			using inner_iterator_t = decltype(database_)::mapped_type::iterator;

			outer_iterator_t outer_iterator_;
			inner_iterator_t inner_iterator_;
			outer_iterator_t outer_iterator_end_;

		public:
			using iterator_category = std::input_iterator_tag;
			using value_type = inner_iterator_t::value_type;
			using reference = inner_iterator_t::reference;
			using pointer = inner_iterator_t::pointer;
			using difference_type = void;

			explicit iterator(
				outer_iterator_t outer_iterator,
				inner_iterator_t inner_iterator,
				outer_iterator_t outer_iterator_end
			) noexcept;

			reference operator*() const;
			iterator& operator++() noexcept;
			iterator operator++(int) noexcept;
			bool operator==(const iterator& rhs) const noexcept;
		};

		auto begin() noexcept;
		auto end() noexcept;
	};
}
