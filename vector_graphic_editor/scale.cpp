#include "scale.h"

namespace vector_graphic_editor
{
	constexpr double default_double_compare_precision = 1E-20;

	double get_inverted_scale(
		const double scale, 
		const double precision = default_double_compare_precision
	)
	{
		if (-precision < scale && scale < precision)
		{
			return 0;
		}
		return 1 / scale;
	}

	scale::scale(
		std::shared_ptr<figure_interface> subject, 
		const double scale_x, 
		const double scale_y
	)
		: subject_(std::move(subject)),
		  scale_x_(scale_x),
		  scale_y_(scale_y)
	{
		if (!subject_)
		{
			throw invalid_command_exception("empty figure pointer");
		}
	}

	void scale::redo()
	{
		subject_->scale(scale_x_, scale_y_);
	}

	void scale::undo()
	{
		subject_->scale(get_inverted_scale(scale_x_), get_inverted_scale(scale_y_));
	}
}
