#include "rotate.h"

namespace vector_graphic_editor
{
	rotate::rotate(std::shared_ptr<figure_interface> subject, const double angle_degrees) noexcept:
		subject_(std::move(subject)),
		angle_degrees_(angle_degrees)
	{
	}

	void rotate::redo()
	{
		subject_->rotate(angle_degrees_);
	}

	void rotate::undo()
	{
		subject_->rotate(-angle_degrees_);
	}
}
