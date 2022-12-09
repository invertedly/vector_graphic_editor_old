#pragma once
#include <type_traits>
#include <memory>

#include "command_interface.h"
#include "translate_strategy_interface.h"
#include "translate_strategy_line.h"
#include "translate_strategy_rectangle.h"
#include "translate_strategy_ellipse.h"

namespace vector_graphic_editor
{
	template<typename T>
	requires std::is_convertible_v<T, figure>
	class translate final : public command_interface
	{
		double translate_x_;
		double translate_y_;
		std::unique_ptr<translate_strategy_interface> execute_strategy_;

	public:
		explicit translate(
			std::shared_ptr<T> subject, 
			const double translate_x, 
			const double translate_y
		)
		noexcept (std::is_nothrow_constructible_v<translate_strategy<T>>)
			: command_interface(std::move(subject)),
			  translate_x_(translate_x),
			  translate_y_(translate_y),
			  execute_strategy_(
				  std::make_unique<translate_strategy<T>>(translate_strategy<T>())
			  )
		{
		}

		void execute() override
		{
			execute_strategy_->execute(
				std::shared_ptr(subject_), 
				translate_x_, 
				translate_y_
			);
		}
	};
}
