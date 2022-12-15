#pragma once
#include <type_traits>
#include <memory>

#include "figure.h"
#include "command_interface.h"
#include "rotate_strategy_interface.h"
#include "rotate_strategy_line.h"
#include "rotate_strategy_rectangle.h"
#include "rotate_strategy_ellipse.h"

namespace vector_graphic_editor_old
{
	template<typename T>
	requires std::is_convertible_v<T, figure>
	class rotate final : public command_interface
	{
		double angle_radians_;
		std::unique_ptr<rotate_strategy_interface> execute_strategy_;

	public:
		explicit rotate(
			std::shared_ptr<T> subject, 
			const double angle_radians
		)
		noexcept (std::is_nothrow_constructible_v<rotate_strategy<T>>)
			: command_interface(std::move(subject)),
			  angle_radians_(angle_radians),
			  execute_strategy_(std::make_unique<rotate_strategy<T>>(rotate_strategy<T>()))
		{
		}

		void execute() override
		{
			execute_strategy_->execute(
				std::shared_ptr(subject_), 
				angle_radians_
			);
		}
	};
}