#pragma once

#include "figure_id.h"

namespace vector_graphic_editor
{
	class figure
	{
		figure_id id_;
	protected:
		explicit figure(figure_id id)
		noexcept (std::is_nothrow_constructible_v<figure_id, figure_id&&>)
			: id_(std::move(id))
		{
		}
	public:
		[[nodiscard]] figure_id get_id() const noexcept { return id_; }

		figure(const figure&)				= default;
		figure(figure&&)					= default;
		figure& operator=(const figure&)	= default;
		figure& operator=(figure&&)			= default;

		virtual ~figure() = default;
	};
}
