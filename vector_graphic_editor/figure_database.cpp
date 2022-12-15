#include "figure_database.h"
#include "figure_database_exception.h"

namespace vector_graphic_editor
{
	void figure_database::add(const std::shared_ptr<figure_interface>& figure_ptr, const figure_id& id)
	{
		if (contains(figure_ptr, id))
		{
			throw figure_database_exception("repetitive type and id");
		}

		database_[id].insert(std::make_pair(std::type_index(typeid(*figure_ptr)), figure_ptr));
	}

	bool figure_database::contains(const std::shared_ptr<figure_interface>& figure_ptr,
		const figure_id& id) const noexcept
	{
		return database_.contains(id) && database_.at(id).contains(std::type_index(typeid(*figure_ptr)));
	}
}
