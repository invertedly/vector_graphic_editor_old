#pragma once

#include <memory>
#include "figure.h"

namespace vector_graphic_editor_old
{
	class command_interface
	{
	protected:
		std::shared_ptr<figure> subject_;
	public:
		explicit command_interface(std::shared_ptr<figure> subject)
		noexcept (std::is_nothrow_move_constructible_v<figure>)
			: subject_(std::move(subject))
		{
		}

		explicit command_interface(const command_interface&)	= default;
		explicit command_interface(command_interface&&)			= default;

		command_interface& operator=(const command_interface&)	= default;
		command_interface& operator=(command_interface&&)		= default;
 
		virtual void execute() = 0;

		virtual ~command_interface() = default;
	};
}
