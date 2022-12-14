#pragma once
#include "figure.h"
#include "coordinate.h"

namespace vector_graphic_editor_old
{
	class ellipse final : public figure
	{
		coordinate center_;
		double axis1_len_;
		double axis2_len_;
		double rotation_;
	public:
		explicit ellipse(
			const figure_id& id,
			const coordinate center = { 0,0 },
			const double axis1_len = 0,
			const double axis2_len = 0,
			const double rotation = 0
		)
		noexcept (std::is_nothrow_constructible_v<figure, figure_id>)
			: figure(id),
			  center_(center),
			  axis1_len_(axis1_len),
			  axis2_len_(axis2_len),
			  rotation_(rotation)
		{
		}

		[[nodiscard]] coordinate get_center()	const noexcept { return center_; }
		[[nodiscard]] double get_axis1_len()	const noexcept { return axis1_len_; }
		[[nodiscard]] double get_axis2_len()	const noexcept { return axis2_len_; }
		[[nodiscard]] double get_rotation()		const noexcept { return rotation_; }

		void set_center(const coordinate center)	noexcept { center_ = center; }
		void set_axis1_len(const double len)		noexcept { axis1_len_ = len; }
		void set_axis2_len(const double len)		noexcept { axis2_len_ = len; }
		void set_rotation(const double rotation)	noexcept { rotation_ = rotation; }
	};
}
