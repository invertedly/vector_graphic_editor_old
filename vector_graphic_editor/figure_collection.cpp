#include "figure_collection.h"
#include "figure_collection_exception.h"

namespace vector_graphic_editor
{
	void figure_collection::add(
		const figure_id& id,
		const std::shared_ptr<figure_interface>& figure_ptr
	)
	{
		if (contains(id))
		{
			throw figure_collection_exception("repetitive id");
		}

		database_[id] = figure_ptr;
	}

	bool figure_collection::contains(
		const figure_id& id
	) const noexcept
	{
		return database_.contains(id);
	}

	std::shared_ptr<figure_interface>& figure_collection::get(
		const figure_id& id
	)
	{
		if (!contains(id))
		{
			throw figure_collection_exception("no figure with provided id");
		}

		return database_.at(id);
	}

	auto figure_collection::end() noexcept
	{
		return database_.end();
	}

	auto figure_collection::begin() noexcept
	{
		return database_.begin();
	}
}
