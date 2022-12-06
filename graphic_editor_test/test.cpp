#include "pch.h"

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

	auto l1 = std::make_shared<line>(id1);
	auto l2 = std::make_shared<line>(id2);

	auto r1 = std::make_shared<rectangle>(id1);
	auto r2 = std::make_shared<rectangle>(id2);

	auto e1 = std::make_shared<ellipse>(id1);
	auto e2 = std::make_shared<ellipse>(id2);

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