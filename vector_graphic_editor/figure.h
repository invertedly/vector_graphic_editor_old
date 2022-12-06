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
		figure(const figure&) = delete;
		figure& operator=(const figure&) = delete;

		figure(const figure&&) = default;
		figure& operator=(figure&&) = default;
		
		figure_id get_id() const noexcept { return id_; }

		virtual ~figure() = default;
	};
}