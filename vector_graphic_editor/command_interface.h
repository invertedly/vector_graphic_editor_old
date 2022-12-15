#pragma once

#include <memory>
#include "figure_interface.h"

namespace vector_graphic_editor
{
	class command_interface 
	{
	protected:
		explicit command_interface() = default;
	public:
		command_interface(const command_interface&)	= default;
		command_interface(command_interface&&)		= default;

		command_interface& operator=(const command_interface&)	= default;
		command_interface& operator=(command_interface&&)		= default;

		virtual void undo() = 0;
		virtual void redo() = 0;

		virtual ~command_interface() = 0;
	};
}