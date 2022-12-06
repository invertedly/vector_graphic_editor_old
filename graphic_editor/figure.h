#pragma once

#include "figure_id.h"

namespace vector_graphic_editor
{
	class figure
	{
		figure_id id_;
	protected:
		explicit figure(figure_id id) : id_(std::move(id)) {}
	public:
		[[nodiscard]] figure_id get_id() const noexcept { return id_; }
		virtual ~figure() = default;
	};
}