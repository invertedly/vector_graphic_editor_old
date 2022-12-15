#include "figure_database.h"

namespace vector_graphic_editor_old
{
	//void figure_database::add(const std::shared_ptr<figure>& item)
	//{
	//	if (contains(item))
	//	{
	//		throw figure_database_exception("repetative type and id");
	//	}

	//	database_[item->get_id()].insert(
	//		std::make_pair(std::type_index(typeid(*item)), item)
	//	);
	//}

	//bool figure_database::contains(const std::shared_ptr<figure>& item) const noexcept
	//{
	//	const figure_id id = item->get_id();

	//	return database_.contains(id) && 
	//		database_.at(id).contains(std::type_index(typeid(*item)));
	//}
}
