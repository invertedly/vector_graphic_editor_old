#include "pch.h"

#include <numbers>

#include "../graphic_editor/rotate.h"
#include "../graphic_editor/scale.h"
#include "../graphic_editor/translate.h"
#include "../graphic_editor/figure_database.h"

#include "../graphic_editor/line.h"
#include "../graphic_editor/ellipse.h"
#include "../graphic_editor/rectangle.h"

TEST(figure_database, default) {
	using namespace vector_graphic_editor;

	figure_database database;

	figure_id id1{ "1" };
	figure_id id2{ "2" };

	auto l1 = std::make_shared<line>(line(id1));
	auto l2 = std::make_shared<line>(line(id2));
	auto r1 = std::make_shared<rectangle>(rectangle(id1));
	auto r2 = std::make_shared<rectangle>(rectangle(id2));
	auto e1 = std::make_shared<ellipse>(ellipse(id1));
	auto e2 = std::make_shared<ellipse>(ellipse(id2));

	EXPECT_NO_THROW(database.add(l1));
	EXPECT_NO_THROW(database.add(r1));
	EXPECT_NO_THROW(database.add(e1));
	EXPECT_NO_THROW(database.add(l2));
	EXPECT_NO_THROW(database.add(r2));
	EXPECT_NO_THROW(database.add(e2));

	EXPECT_THROW(database.add(l1), figure_database_exception);
	EXPECT_THROW(database.add(r1), figure_database_exception);
	EXPECT_THROW(database.add(e1), figure_database_exception);
	EXPECT_THROW(database.add(l2), figure_database_exception);
	EXPECT_THROW(database.add(r2), figure_database_exception);
	EXPECT_THROW(database.add(e2), figure_database_exception);
}

TEST(translate, line)
{
	using namespace vector_graphic_editor;
	auto l = std::make_shared<line>(figure_id{ "id" });
	auto cmd = translate(l, 1.0, 2.0);
	cmd.execute();
	EXPECT_DOUBLE_EQ(l->get_first_coord().get_x(), 1.0);
	EXPECT_DOUBLE_EQ(l->get_first_coord().get_y(), 2.0);
	EXPECT_DOUBLE_EQ(l->get_second_coord().get_x(), 1.0);
	EXPECT_DOUBLE_EQ(l->get_second_coord().get_y(), 2.0);
}

TEST(translate, rectangle)
{
	using namespace vector_graphic_editor;
	auto r = std::make_shared<rectangle>(figure_id{ "id" });
	auto cmd = translate(r, -1.0, -2.0);
	cmd.execute();
	EXPECT_DOUBLE_EQ(r->get_first_coord().get_x(), -1.0);
	EXPECT_DOUBLE_EQ(r->get_first_coord().get_y(), -2.0);
	EXPECT_DOUBLE_EQ(r->get_second_coord().get_x(), -1.0);
	EXPECT_DOUBLE_EQ(r->get_second_coord().get_y(), -2.0);

}

TEST(translate, ellipse)
{
	using namespace vector_graphic_editor;
	auto e = std::make_shared <ellipse>(figure_id{ "id" });
	auto cmd = translate(e, 1.5, 2.5);
	cmd.execute();
	EXPECT_DOUBLE_EQ(e->get_center().get_x(), 1.5);
	EXPECT_DOUBLE_EQ(e->get_center().get_y(), 2.5);
}

TEST(scale, line)
{
	using namespace vector_graphic_editor;
	auto l = std::make_shared<line>(
		figure_id{ "id" }, 
		coordinate{ -1,-1 }, 
		coordinate{ 1,1 }
	);
	auto cmd = scale(l, 2, 3);
	cmd.execute();
	EXPECT_DOUBLE_EQ(l->get_first_coord().get_x(), -2);
	EXPECT_DOUBLE_EQ(l->get_first_coord().get_y(), -3);
	EXPECT_DOUBLE_EQ(l->get_second_coord().get_x(), 2);
	EXPECT_DOUBLE_EQ(l->get_second_coord().get_y(), 3);
}

TEST(scale, rectangle)
{
	using namespace vector_graphic_editor;
	auto r = std::make_shared<rectangle>(
		figure_id{ "id" }, 
		coordinate{ -1,-1 }, 
		coordinate{ 1,1 }
	);
	auto cmd = scale(r, -2, -3);
	cmd.execute();
	EXPECT_DOUBLE_EQ(r->get_first_coord().get_x(), 2);
	EXPECT_DOUBLE_EQ(r->get_first_coord().get_y(), 3);
	EXPECT_DOUBLE_EQ(r->get_second_coord().get_x(), -2);
	EXPECT_DOUBLE_EQ(r->get_second_coord().get_y(), -3);
}

TEST(scale, ellipse)
{
	using namespace vector_graphic_editor;
	auto e1 = std::make_shared <ellipse>(
		figure_id{ "id" }, 
		coordinate{ 0,0 }, 
		10, 5, 0
		);
	auto e2 = std::make_shared <ellipse>(
		figure_id{ "id" }, 
		coordinate{ 0,0 }, 
		10, 5, std::numbers::pi / 2
		);
	auto cmd1 = scale(e1, 2, 3);
	auto cmd2 = scale(e2, 2, 3);
	cmd1.execute();
	cmd2.execute();
	EXPECT_DOUBLE_EQ(e1->get_axis1_len(), 20);
	EXPECT_DOUBLE_EQ(e1->get_axis2_len(), 15);
	EXPECT_DOUBLE_EQ(e2->get_axis1_len(), 30);
	EXPECT_DOUBLE_EQ(e2->get_axis2_len(), 10);
}

TEST(rotate, line)
{
	using namespace vector_graphic_editor;
	auto l = std::make_shared<line>(
		figure_id{ "id" },
		coordinate{ -1,-1 },
		coordinate{ 1,1 }
	);
	auto cmd = rotate(l, std::numbers::pi/2);
	cmd.execute();
	EXPECT_DOUBLE_EQ(l->get_first_coord().get_x(), 1);
	EXPECT_DOUBLE_EQ(l->get_first_coord().get_y(), -1);
	EXPECT_DOUBLE_EQ(l->get_second_coord().get_x(), -1);
	EXPECT_DOUBLE_EQ(l->get_second_coord().get_y(), 1);
}

TEST(rotate, rectangle)
{
	using namespace vector_graphic_editor;
	auto r = std::make_shared<rectangle>(
		figure_id{ "id" },
		coordinate{ -1,-1 },
		coordinate{ 1,1 }
	);
	auto cmd = rotate(r, std::numbers::pi / 2);
	cmd.execute();
	EXPECT_DOUBLE_EQ(r->get_first_coord().get_x(), 1);
	EXPECT_DOUBLE_EQ(r->get_first_coord().get_y(), -1);
	EXPECT_DOUBLE_EQ(r->get_second_coord().get_x(), -1);
	EXPECT_DOUBLE_EQ(r->get_second_coord().get_y(), 1);
}

TEST(rotate, ellipse)
{
	using namespace vector_graphic_editor;
	auto e = std::make_shared <ellipse>(
		figure_id{ "id" },
		coordinate{ 0,0 },
		10, 5, 0
		);
	auto cmd = rotate(e, std::numbers::pi / 2);
	cmd.execute();
	EXPECT_DOUBLE_EQ(e->get_rotation(), std::numbers::pi / 2);
}

TEST(type_index, virtual_base_cast)
{
	class v_base
	{
	protected:
		v_base() {}
	public:
		virtual ~v_base() = default;
		virtual void foo() = 0;
	};

	class derived1 final : public v_base
	{
	public:
		derived1() = default;
		void foo() override {}
	};

	class derived2 final : public v_base
	{
	public:
		derived2() = default;
		void foo() override {}
	};

	std::shared_ptr<derived1> der1 = std::make_shared<derived1>(derived1{});
	std::shared_ptr<derived2> der2 = std::make_shared<derived2>(derived2{});

	std::shared_ptr<v_base> base_casted1 = der1;
	std::shared_ptr<v_base> base_casted2 = der2;

	EXPECT_EQ(typeid(*der1), typeid(*base_casted1));
	EXPECT_EQ(typeid(*der2), typeid(*base_casted2));

	EXPECT_NE(typeid(*der1), typeid(*der2));
	EXPECT_NE(typeid(*base_casted1), typeid(*base_casted2));

	EXPECT_NE(typeid(der1), typeid(base_casted1));
	EXPECT_NE(typeid(der2), typeid(base_casted2));
	EXPECT_NE(typeid(der1), typeid(der2));

	EXPECT_EQ(typeid(base_casted1), typeid(base_casted2));
}