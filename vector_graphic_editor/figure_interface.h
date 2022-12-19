#pragma once

namespace vector_graphic_editor
{
	class figure_interface
	{
	protected:
		explicit figure_interface() = default;
	public:
		figure_interface(const figure_interface&)	= default;
		figure_interface(figure_interface&&)		= default;

		figure_interface& operator=(const figure_interface&)	= default;
		figure_interface& operator=(figure_interface&&)			= default;

		virtual void translate(double translate_x, double translate_y)	= 0;
		virtual void scale(double scale_x, double scale_y)				= 0;
		virtual void rotate(double angle_degrees)						= 0;
			
		virtual ~figure_interface() = default;
	};
}