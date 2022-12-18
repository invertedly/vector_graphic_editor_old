#include "figure_database.h"
#include "figure_database_exception.h"

namespace vector_graphic_editor
{
	void figure_database::add(
		const std::shared_ptr<figure_interface>& figure_ptr, 
		const figure_id& id
	)
	{
		if (contains(id, typeid(*figure_ptr)))
		{
			throw figure_database_exception("repetitive type and id");
		}

		database_[id].insert(std::make_pair(std::type_index(typeid(*figure_ptr)), figure_ptr));
	}

	bool figure_database::contains(
		const figure_id& id,
		const std::type_index& figure_type_index
	) const noexcept
	{
		return database_.contains(id) && database_.at(id).contains(figure_type_index);
	}

	std::shared_ptr<figure_interface>& figure_database::get(
		const figure_id& id,
		const std::type_index& figure_type_index
	)
	{
		if (!contains(id, figure_type_index))
		{
			throw figure_database_exception("no figure with provided id and type index");
		}

		return database_.at(id).at(figure_type_index);
	}

	figure_database::iterator::iterator(
		outer_iterator_t outer_iterator,
		inner_iterator_t inner_iterator,
		outer_iterator_t outer_iterator_end
	) noexcept
		: outer_iterator_(std::move(outer_iterator)),
		  inner_iterator_(std::move(inner_iterator)),
		  outer_iterator_end_(std::move(outer_iterator_end))
	{
	}

	figure_database::iterator::reference figure_database::iterator::operator*() const
	{
		return *inner_iterator_;
	}

	figure_database::iterator& figure_database::iterator::operator++() noexcept
	{
		if (inner_iterator_ != outer_iterator_->second.end() && 
			++inner_iterator_ != outer_iterator_->second.end())
		{
			return *this;
		}

		const outer_iterator_t outer_iterator_prev_value = outer_iterator_;

		if (++outer_iterator_ != outer_iterator_end_)
		{
			inner_iterator_ = outer_iterator_->second.begin();
		}
		else
		{
			outer_iterator_ = outer_iterator_prev_value;
		}

		return *this;
	}

	figure_database::iterator figure_database::iterator::operator++(int) noexcept
	{
		iterator result = *this;
		++* this;
		return result;
	}

	bool figure_database::iterator::operator==(const iterator& rhs) const noexcept
	{
		return inner_iterator_ == rhs.inner_iterator_;
	}

	auto figure_database::begin() noexcept
	{
		return iterator(
			database_.begin(),
			database_.begin()->second.begin(),
			database_.end()
		);
	}

	auto figure_database::end() noexcept
	{
		return iterator(
			database_.
		);
	}
}
