#pragma once
#include <type_traits>

#include "command_interface.h"
#include "figure.h"
#include "scale_strategy.h"
#include "scale_strategy_line.h"
#include "scale_strategy_rectangle.h"
#include "scale_strategy_ellipse.h"

namespace vector_graphic_editor_old
{
	template<typename T>
	requires std::is_convertible_v<T, figure>
	class scale final : public command_interface
	{
		double scale_x_;
		double scale_y_;
		std::unique_ptr<scale_strategy_interface> execute_strategy_;

	public:
		explicit scale(
			std::shared_ptr<T> subject, 
			const double scale_x, 
			const double scale_y
		)
		noexcept (std::is_nothrow_constructible_v<scale_strategy<T>>)
			: command_interface(std::move(subject)),
			  scale_x_(scale_x),
			  scale_y_(scale_y),
			  execute_strategy_(std::make_unique<scale_strategy<T>>(scale_strategy<T>()))
		{
		}

		void execute() override
		{
			execute_strategy_->execute(
				std::shared_ptr(subject_), 
				scale_x_, 
				scale_y_
			);
		}
	};
}
