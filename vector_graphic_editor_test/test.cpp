#include "pch.h"

#include <numbers>
#include <unordered_set>

#include "../vector_graphic_editor/angle_converter.h"
#include "../vector_graphic_editor/coordinate.h"
#include "../vector_graphic_editor/figure_id.h"
#include "../vector_graphic_editor/figure_collection.h"
#include "../vector_graphic_editor/rectangle.h"
#include "../vector_graphic_editor/line.h"
#include "../vector_graphic_editor/ellipse.h"
#include "../vector_graphic_editor/rotate.h"
#include "../vector_graphic_editor/translate.h"
#include "../vector_graphic_editor/scale.h"
#include "../vector_graphic_editor/macro_command.h"
#include "../vector_graphic_editor/command_queue.h"

#include "../vector_graphic_editor/rectangle.cpp"
#include "../vector_graphic_editor/line.cpp"
#include "../vector_graphic_editor/ellipse.cpp"
#include "../vector_graphic_editor/coordinate.cpp"
#include "../vector_graphic_editor/figure_id.cpp"
#include "../vector_graphic_editor/figure_collection.cpp"
#include "../vector_graphic_editor/macro_command.cpp"
#include "../vector_graphic_editor/rotate.cpp"/
#include "../vector_graphic_editor/translate.cpp"
#include "../vector_graphic_editor/scale.cpp"
#include "../vector_graphic_editor/command_queue.cpp"


using namespace vector_graphic_editor;

TEST(command_queue, single_commands)
{
	command_queue queue;

	auto figure1 = std::make_shared<rectangle>(rectangle({ 1, 1 }, { 2,2 }));
	auto figure2 = std::make_shared<line>(line({ 1, 1 }, { 2,2 }));
	auto figure3 = std::make_shared<ellipse>(ellipse({ 0,0 }, 1, 1, 0));

	auto translate1 = std::make_unique<translate>(translate(figure1, 1, 1));
	auto translate2 = std::make_unique<translate>(translate(figure2, 1, 1));
	auto translate3 = std::make_unique<translate>(translate(figure3, 1, 1));

	auto translate4 = std::make_shared<translate>(translate(figure3, 1, 1));
	auto translate5 = std::make_shared<scale>(scale(figure3, 1, 1));

	EXPECT_TRUE(queue.empty());

	queue.add_command(translate4);

	EXPECT_FALSE(queue.empty());

	queue.add_command(translate5);

	EXPECT_FALSE(queue.empty());

	auto cmd1 = queue.get_next_command();
	auto cmd2 = queue.get_next_command();

	EXPECT_TRUE(queue.empty());
}

TEST(command, invalid_construct)
{
	EXPECT_THROW(rotate(std::shared_ptr<line>(), 1), invalid_command_exception);
	EXPECT_THROW(scale(std::shared_ptr<line>(), 1, 1), invalid_command_exception);
	EXPECT_THROW(translate(std::shared_ptr<line>(), 1, 1), invalid_command_exception);

	macro_command macro_cmd;

	EXPECT_THROW(macro_cmd.add(std::unique_ptr<rotate>()), invalid_command_exception);
}

TEST(macro_command, rotate_all)
{
	figure_id id1{ "same_type", "id1" };
	figure_id id2{ "same_type", "id2" };
	figure_id id3{ "different_type", "id2" };

	auto figure1 = std::make_shared<rectangle>(rectangle({ 1, 1 }, { 2,2 }));
	auto figure2 = std::make_shared<line>(line({ 1, 1 }, { 2,2 }));
	auto figure3 = std::make_shared<ellipse>(ellipse({ 0,0 }, 1, 1, 0));

	std::unique_ptr<rotate> rotate1 = std::make_unique<rotate>(rotate(figure1, 90));
	std::unique_ptr<rotate> rotate2 = std::make_unique<rotate>(rotate(figure2, 90));
	std::unique_ptr<rotate> rotate3 = std::make_unique<rotate>(rotate(figure3, 90));

	macro_command macro_cmd;

	macro_cmd.add(std::move(rotate1));
	macro_cmd.add(std::move(rotate2));
	macro_cmd.add(std::move(rotate3));

	macro_cmd.redo();

	EXPECT_EQ(figure1.get()->get_first().get_x(), 2);
	EXPECT_EQ(figure1.get()->get_first().get_y(), 1);
	EXPECT_EQ(figure1.get()->get_second().get_x(), 1);
	EXPECT_EQ(figure1.get()->get_second().get_y(), 2);

	EXPECT_EQ(figure2.get()->get_first().get_x(), 2);
	EXPECT_EQ(figure2.get()->get_first().get_y(), 1);
	EXPECT_EQ(figure2.get()->get_second().get_x(), 1);
	EXPECT_EQ(figure2.get()->get_second().get_y(), 2);

	EXPECT_EQ(figure3.get()->get_angle_degrees(), 90);

	macro_cmd.undo();

	EXPECT_EQ(figure1.get()->get_first().get_x(), 1);
	EXPECT_EQ(figure1.get()->get_first().get_y(), 1);
	EXPECT_EQ(figure1.get()->get_second().get_x(), 2);
	EXPECT_EQ(figure1.get()->get_second().get_y(), 2);

	EXPECT_EQ(figure2.get()->get_first().get_x(), 1);
	EXPECT_EQ(figure2.get()->get_first().get_y(), 1);
	EXPECT_EQ(figure2.get()->get_second().get_x(), 2);
	EXPECT_EQ(figure2.get()->get_second().get_y(), 2);

	EXPECT_EQ(figure3.get()->get_angle_degrees(), 0);
}

TEST(macro_command, translate_all)
{
	figure_id id1{ "same_type", "id1" };
	figure_id id2{ "same_type", "id2" };
	figure_id id3{ "different_type", "id2" };

	auto figure1 = std::make_shared<rectangle>(rectangle({ 1, 1 }, { 2,2 }));
	auto figure2 = std::make_shared<line>(line({ 1, 1 }, { 2,2 }));
	auto figure3 = std::make_shared<ellipse>(ellipse({ 0,0 }, 1, 1, 0));

	std::unique_ptr<translate> translate1 = std::make_unique<translate>(translate(figure1, 1, 1));
	std::unique_ptr<translate> translate2 = std::make_unique<translate>(translate(figure2, 1, 1));
	std::unique_ptr<translate> translate3 = std::make_unique<translate>(translate(figure3, 1, 1));

	macro_command macro_cmd;

	macro_cmd.add(std::move(translate1));
	macro_cmd.add(std::move(translate2));
	macro_cmd.add(std::move(translate3));

	macro_cmd.redo();

	EXPECT_EQ(figure1.get()->get_first().get_x(), 2);
	EXPECT_EQ(figure1.get()->get_first().get_y(), 2);
	EXPECT_EQ(figure1.get()->get_second().get_x(), 3);
	EXPECT_EQ(figure1.get()->get_second().get_y(), 3);

	EXPECT_EQ(figure2.get()->get_first().get_x(), 2);
	EXPECT_EQ(figure2.get()->get_first().get_y(), 2);
	EXPECT_EQ(figure2.get()->get_second().get_x(), 3);
	EXPECT_EQ(figure2.get()->get_second().get_y(), 3);

	EXPECT_EQ(figure3.get()->get_center().get_x(), 1);
	EXPECT_EQ(figure3.get()->get_center().get_y(), 1);

	macro_cmd.undo();

	EXPECT_EQ(figure1.get()->get_first().get_x(), 1);
	EXPECT_EQ(figure1.get()->get_first().get_y(), 1);
	EXPECT_EQ(figure1.get()->get_second().get_x(), 2);
	EXPECT_EQ(figure1.get()->get_second().get_y(), 2);

	EXPECT_EQ(figure2.get()->get_first().get_x(), 1);
	EXPECT_EQ(figure2.get()->get_first().get_y(), 1);
	EXPECT_EQ(figure2.get()->get_second().get_x(), 2);
	EXPECT_EQ(figure2.get()->get_second().get_y(), 2);

	EXPECT_EQ(figure3.get()->get_center().get_x(), 0);
	EXPECT_EQ(figure3.get()->get_center().get_y(), 0);
}

TEST(macro_command, scale_all)
{
	figure_id id1{ "same_type", "id1" };
	figure_id id2{ "same_type", "id2" };
	figure_id id3{ "different_type", "id2" };

	auto figure1 = std::make_shared<rectangle>(rectangle({ 1, 1}, { 2,2 }));
	auto figure2 = std::make_shared<line>(line({ 1, 1 }, { 2,2 }));
	auto figure3 = std::make_shared<ellipse>(ellipse({ 0,0 }, 1, 1, 0));

	std::unique_ptr<scale> scale1 = std::make_unique<scale>(scale(figure1, 2, 3));
	std::unique_ptr<scale> scale2 = std::make_unique<scale>(scale(figure2, 2, 3));
	std::unique_ptr<scale> scale3 = std::make_unique<scale>(scale(figure3, 2, 3));

	macro_command macro_cmd;

	macro_cmd.add(std::move(scale1));
	macro_cmd.add(std::move(scale2));
	macro_cmd.add(std::move(scale3));

	macro_cmd.redo();

	EXPECT_EQ(figure1.get()->get_first().get_x(), 0.5);
	EXPECT_EQ(figure1.get()->get_first().get_y(), 0);
	EXPECT_EQ(figure1.get()->get_second().get_x(), 2.5);
	EXPECT_EQ(figure1.get()->get_second().get_y(), 3);

	EXPECT_EQ(figure2.get()->get_first().get_x(), 0.5);
	EXPECT_EQ(figure2.get()->get_first().get_y(), 0);
	EXPECT_EQ(figure2.get()->get_second().get_x(), 2.5);
	EXPECT_EQ(figure2.get()->get_second().get_y(), 3);

	EXPECT_EQ(figure3.get()->get_axis1(), 2);
	EXPECT_EQ(figure3.get()->get_axis2(), 3);

	macro_cmd.undo();

	EXPECT_EQ(figure1.get()->get_first().get_x(), 1);
	EXPECT_EQ(figure1.get()->get_first().get_y(), 1);
	EXPECT_EQ(figure1.get()->get_second().get_x(), 2);
	EXPECT_EQ(figure1.get()->get_second().get_y(), 2);

	EXPECT_EQ(figure2.get()->get_first().get_x(), 1);
	EXPECT_EQ(figure2.get()->get_first().get_y(), 1);
	EXPECT_EQ(figure2.get()->get_second().get_x(), 2);
	EXPECT_EQ(figure2.get()->get_second().get_y(), 2);

	EXPECT_EQ(figure3.get()->get_axis1(), 1);
	EXPECT_EQ(figure3.get()->get_axis2(), 1);
}

TEST(figure_database, add)
{
	figure_collection database;

	figure_id id1{ "same_type", "id1" };
	figure_id id2{ "same_type", "id2" };
	figure_id id3{ "different_type", "id2" };

	std::shared_ptr<rectangle> figure = std::make_shared<rectangle>(rectangle({1, 1}, {2,2}));

	EXPECT_NO_THROW(database.add(id1, figure));
	EXPECT_NO_THROW(database.add(id2, figure));
	EXPECT_NO_THROW(database.add(id3, figure));

	EXPECT_THROW(database.add(id1, figure), figure_collection_exception);
	EXPECT_THROW(database.add(id2, figure), figure_collection_exception);
	EXPECT_THROW(database.add(id3, figure), figure_collection_exception);
}

TEST(figure_database, contains)
{
	figure_collection database;

	figure_id id1{ "same_type", "id1" };
	figure_id id2{ "same_type", "id2" };
	figure_id id3{ "different_type", "id2" };
	figure_id id4{ "different_type", "id3" };

	EXPECT_FALSE(database.contains(id1));
	EXPECT_FALSE(database.contains(id2));
	EXPECT_FALSE(database.contains(id3));
	EXPECT_FALSE(database.contains(id4));

	std::shared_ptr<rectangle> figure = std::make_shared<rectangle>(rectangle({ 1, 1 }, { 2,2 }));

	EXPECT_NO_THROW(database.add(id1, figure));
	EXPECT_NO_THROW(database.add(id2, figure));
	EXPECT_NO_THROW(database.add(id3, figure));

	EXPECT_TRUE(database.contains(id1));
	EXPECT_TRUE(database.contains(id2));
	EXPECT_TRUE(database.contains(id3));
	EXPECT_FALSE(database.contains(id4));
}

TEST(figure_database, get)
{
	figure_collection database;

	figure_id id1{ "same_type", "id1" };
	figure_id id2{ "same_type", "id2" };
	figure_id id3{ "different_type", "id2" };
	figure_id id4{ "different_type", "id3" };

	EXPECT_THROW(database.get(id1), figure_collection_exception);

	std::shared_ptr<rectangle> figure = std::make_shared<rectangle>(rectangle({ 1, 1 }, { 2,2 }));

	EXPECT_NO_THROW(database.add(id1, figure));
	EXPECT_NO_THROW(database.add(id2, figure));
	EXPECT_NO_THROW(database.add(id3, figure));

	EXPECT_NO_THROW(database.get(id1));
	EXPECT_NO_THROW(database.get(id2));
	EXPECT_NO_THROW(database.get(id3));
	EXPECT_THROW(database.get(id4), figure_collection_exception);
}

TEST(figure_database, iterate)
{
	figure_collection database;

	figure_id id1{ "same_type", "id1" };
	figure_id id2{ "same_type", "id2" };
	figure_id id3{ "different_type", "id2" };
	figure_id id4{ "different_type", "id3" };

	auto figure1 = std::make_shared<rectangle>(rectangle({ 1, 1 }, { 2,2 }));
	auto figure2 = std::make_shared<line>(line({ 1, 1 }, { 2,2 }));
	auto figure3 = std::make_shared<ellipse>(ellipse({0,0}, 1, 1, 0));

	std::unordered_set<std::shared_ptr<figure_interface>> set = { figure1, figure2, figure3 };

	EXPECT_NO_THROW(database.add(id1, figure1));
	EXPECT_NO_THROW(database.add(id2, figure2));
	EXPECT_NO_THROW(database.add(id3, figure3));

	size_t figure_count = 0;

	for (auto& [id, figure] : database)
	{
		ASSERT_TRUE(set.contains(figure));
		++figure_count;
	}
	ASSERT_EQ(figure_count, set.size());
}

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

//TEST(coordinate, rotate_clockwise_360)
//{
//	coordinate initial{0,0};
//	const coordinate invariant{ 1, 1 };
//	initial.rotate(invariant, -360);
//	EXPECT_DOUBLE_EQ(initial.get_y(), 0);
//	EXPECT_DOUBLE_EQ(initial.get_x(), 0);
//}

//TEST(coordinate, rotate_counter_clockwise_360)
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
	EXPECT_NO_THROW(figure_id(std::string(""), std::string("")));
	EXPECT_NO_THROW(figure_id(std::string(""), std::string("valid")));
	EXPECT_THROW(figure_id(std::string(""), "invalid]"), figure_id_exception);
	EXPECT_THROW(figure_id(std::string(""), "invalid]aswell"), figure_id_exception);
}