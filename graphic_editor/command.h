#pragma once

#include <memory>
#include "figure.h"

namespace vector_graphic_editor
{
	class command
	{
	protected:
		std::weak_ptr<figure> subject_;
	public:
		explicit command(const std::shared_ptr<figure>& subject) : subject_(subject) {}

		virtual ~command() = default;

		virtual void execute() = 0;
	};
}
