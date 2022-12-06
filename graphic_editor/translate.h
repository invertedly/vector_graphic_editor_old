#pragma once
#include <type_traits>
#include <memory>

#include "command.h"
#include "line.h"
#include "rectangle.h"

namespace vector_graphic_editor
{
	class translate_base : public command
	{
	protected:
		double dx_;
		double dy_;

	public:
		explicit translate_base(const std::shared_ptr<figure>& subject, const double dx, const double dy)
			: command(subject), dx_(dx), dy_(dy)
		{
		}

		void execute() override = 0;

		~translate_base() override = default;
	};

	template<typename T>
	requires std::is_same_v<T, line>
	class translate final : translate_base
	{
		coordinate get_new_coord(const coordinate old_coord) const noexcept
		{
			return coordinate{ old_coord.get_x() + dx_, old_coord.get_y() + dy_ };
		}
	public:
		translate(const std::shared_ptr<T>& subject, const double dx, const double dy)
			: translate_base(subject, dx, dy)
		{
		}

		void execute() override
		{
			const std::shared_ptr<line> line_ptr = std::dynamic_pointer_cast<line>(std::shared_ptr(subject_));

			line_ptr->set_first_coord(get_new_coord(line_ptr->get_first_coord()));

			line_ptr->set_second_coord(get_new_coord(line_ptr->get_second_coord()));
		}
	};

	template<typename T>
	requires std::is_same_v<T, rectangle>
	class translate final : translate_base
	{
	public:
		translate(const std::shared_ptr<T>& subject, const double dx, const double dy)
			: translate_base(subject, dx, dy)
		{
		}

		void execute() override
		{
		}
	};
}
