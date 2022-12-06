#pragma once
#include <type_traits>

#include "command.h"
#include "line.h"

namespace vector_graphic_editor
{
	template <typename T>
	requires std::is_convertible_v<T, figure>
	class translate : public command<T>
	{
	private:
		double dx_;
		double dy_;
	public:
		translate(const std::shared_ptr<T>& subject, const double dx, const double dy) : command(subject), dx_(dx), dy_(dy) { }
	};

	class translate<line> final
	{
		
	};
}
