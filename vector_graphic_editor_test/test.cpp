#include "pch.h"

#include <numbers>

#include "../vector_graphic_editor/angle_converter.h"
#include "../vector_graphic_editor/coordinate.h"
#include "../vector_graphic_editor/coordinate.cpp"
#include "../vector_graphic_editor/figure_id.h"


using namespace vector_graphic_editor;

TEST(angle_converter, degrees_to_radians)
{
	EXPECT_EQ(angle_converter::degrees_to_radians(0), 0);
	EXPECT_EQ(angle_converter::degrees_to_radians(180), std::numbers::pi);
	EXPECT_EQ(angle_converter::degrees_to_radians(-180), - std::numbers::pi);
	EXPECT_EQ(angle_converter::degrees_to_radians(90), std::numbers::pi / 2);
	EXPECT_EQ(angle_converter::degrees_to_radians(45), std::numbers::pi / 4);
	EXPECT_EQ(angle_converter::degrees_to_radians(360), std::numbers::pi * 2);
	EXPECT_EQ(angle_converter::degrees_to_radians(450), std::numbers::pi * 2.5);
	EXPECT_EQ(angle_converter::degrees_to_radians(-450), - std::numbers::pi * 2.5);
}

TEST(coordinate, translate_positive)
{
	coordinate initial{ 1, 1 };
	initial.translate(2, 2);
	EXPECT_EQ(initial.get_x(), 3);
	EXPECT_EQ(initial.get_y(), 3);
}

TEST(coordiante, translate_negative)
{
	coordinate initial{ 3, 3 };
	initial.translate(-5, -5);
	EXPECT_EQ(initial.get_x(), -2);
	EXPECT_EQ(initial.get_y(), -2);
}

TEST(coordinate, translate_neutral)
{
	coordinate initial{ 3, 3 };
	initial.translate(0, 0);
	EXPECT_EQ(initial.get_x(), 3);
	EXPECT_EQ(initial.get_y(), 3);
}

TEST(coordinate, scale_positive_invariant_less)
{
	
	coordinate initial{ 2, 2 };
	const coordinate invariant{ 1, 1 };
	initial.scale(invariant, 2, 2);
	EXPECT_EQ(initial.get_x(), 3);
	EXPECT_EQ(initial.get_y(), 3);
	
}

TEST(coordinate, scale_positive_invariant_more)
{
	
	coordinate initial{ 0, 0 };
	const coordinate invariant{ 1, 1 };
	initial.scale(invariant, 2, 2);
	EXPECT_EQ(initial.get_x(), -1);
	EXPECT_EQ(initial.get_y(), -1);
	
}

TEST(coordinate, scale_negative_invariant_less)
{
	
	coordinate initial{ 2, 2 };
	const coordinate invariant{ 1, 1 };
	initial.scale(invariant, -2, -2);
	EXPECT_EQ(initial.get_x(), -1);
	EXPECT_EQ(initial.get_y(), -1);
	
}

TEST(coordinate, scale_negative_invariant_more)
{
	
	coordinate initial{ 0, 0 };
	const coordinate invariant{ 1, 1 };
	initial.scale(invariant, -2, -2);
	EXPECT_EQ(initial.get_y(), 3);
	EXPECT_EQ(initial.get_x(), 3);
	
}

TEST(coordinate, scale_zero_invariant_less)
{
	
	coordinate initial{ 2, 2 };
	const coordinate invariant{ 1, 1 };
	initial.scale(invariant, 0, 0);
	EXPECT_EQ(initial.get_x(), 1);
	EXPECT_EQ(initial.get_y(), 1);
	
}

TEST(coordinate, scale_zero_invariant_more)
{
	
	coordinate initial{ 0, 0 };
	const coordinate invariant{ 1, 1 };
	initial.scale(invariant, 0, 0);
	EXPECT_EQ(initial.get_y(), 1);
	EXPECT_EQ(initial.get_x(), 1);
	
}

TEST(coordinate, scale_neutral_invariant_less)
{
	
	coordinate initial{ 2, 2 };
	const coordinate invariant{ 1, 1 };
	initial.scale(invariant, 1,1);
	EXPECT_EQ(initial.get_x(), 2);
	EXPECT_EQ(initial.get_y(), 2);
	
}

TEST(coordinate, scale_neutral_invariant_more)
{
	
	coordinate initial{ 0, 0 };
	const coordinate invariant{ 1, 1 };
	initial.scale(invariant, 1,1);
	EXPECT_EQ(initial.get_x(), 0);
	EXPECT_EQ(initial.get_y(), 0);
	
}

//TEST(coordinate, rotate_clockwise_one_circle)
//{
//	coordinate initial{0,0};
//	const coordinate invariant{ 1, 1 };
//	initial.rotate(invariant, -360);
//	EXPECT_DOUBLE_EQ(initial.get_y(), 0);
//	EXPECT_DOUBLE_EQ(initial.get_x(), 0);
//}

//TEST(coordinate, rotate_counter_clockwise_one_circle)
//{
//	coordinate initial{0, 0};
//	const coordinate invariant{ 1, 1};
//	initial.rotate(invariant, 360);
//	EXPECT_DOUBLE_EQ(initial.get_y(), 0);
//	EXPECT_DOUBLE_EQ(initial.get_x(), 0);
//}


TEST(coordinate, rotate_counter_clockwise_540)
{
	coordinate initial{ 0,0 };
	const coordinate invariant{ 1, 1 };
	initial.rotate(invariant, 540);
	EXPECT_DOUBLE_EQ(initial.get_x(), 2);
	EXPECT_DOUBLE_EQ(initial.get_y(), 2);
}

TEST(coordinate, rotate_counter_clockwise_90)
{
	coordinate initial{ 0, 0 };
	const coordinate invariant{ 1, 1 };
	initial.rotate(invariant, 90);
	EXPECT_DOUBLE_EQ(initial.get_x(), 2);
	EXPECT_DOUBLE_EQ(initial.get_y(), 0);
}

TEST(coordinate, rotate_clockwise_180)
{
	coordinate initial{0, 0};
	const coordinate invariant{ 1, 1};
	initial.rotate(invariant, 180);
	EXPECT_DOUBLE_EQ(initial.get_y(), 2);
	EXPECT_DOUBLE_EQ(initial.get_x(), 2);
}

TEST(coordinate, rotate_clockwise_90)
{
	coordinate initial{0, 0};
	const coordinate invariant{ 1, 1};
	initial.rotate(invariant, -90);
	EXPECT_DOUBLE_EQ(initial.get_x(), 0);
	EXPECT_DOUBLE_EQ(initial.get_y(), 2);
}

TEST(coordinate, rotate_clockwise_540)
{
	coordinate initial{ 0,0 };
	const coordinate invariant{ 1, 1 };
	initial.rotate(invariant, -540);
	EXPECT_DOUBLE_EQ(initial.get_y(), 2);
	EXPECT_DOUBLE_EQ(initial.get_x(), 2);
}

TEST(figure_id, construct)
{
	EXPECT_NO_THROW(figure_id(std::string("")));
	EXPECT_NO_THROW(figure_id(std::string("valid")));
	EXPECT_THROW(figure_id("invalid]"), figure_id_exception);
	EXPECT_THROW(figure_id("invalid]aswell"), figure_id_exception);
}