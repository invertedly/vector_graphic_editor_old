#include "translate.h"

namespace vector_graphic_editor
{
	translate::translate(std::shared_ptr<figure_interface> subject, const double translate_x,
		const double translate_y) noexcept: subject_(std::move(subject)),
		                                    translate_x_(translate_x),
		                                    translate_y_(translate_y)
	{
	}

	void translate::redo()
	{
		subject_->translate(translate_x_, translate_y_);
	}

	void translate::undo()
	{
		subject_->translate(-translate_x_, -translate_y_);
	}
}
