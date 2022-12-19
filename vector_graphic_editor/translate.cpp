#include "translate.h"

namespace vector_graphic_editor
{
	translate::translate(
		std::shared_ptr<figure_interface> subject, 
		const double translate_x,
		const double translate_y
	)
		: subject_(std::move(subject)),
		  translate_x_(translate_x),
		  translate_y_(translate_y)
	{
		if (!subject_)
		{
			throw invalid_command_exception("empty figure pointer");
		}
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
