#include <catch2/catch_test_macros.hpp>
#include "simple_vector.hpp"

TEST_CASE("Корректное количество элементов и емкость", "[simple_vector]") 
{
	SECTION("Размер пустого списка")
	{
		simple_vector<int> sv;
		REQUIRE(sv.size() == 0);
	}

	SECTION("Несколько элементов")
	{
		simple_vector<int> sv;
		for (auto i = 1; i <= 10; ++i)
		{
			sv.push_back(i);
			REQUIRE(sv.size() == i);
			CHECK(sv.capacity() >= sv.size());
		}
	}
}

TEST_CASE("Корректные значения элементов", "[simple_vector]")
{
	SECTION("Несколько элементов")
	{
		simple_vector<int> sv;
		for (auto i = 0; i < 10; ++i)
		{
			sv.push_back(i);
		}

		for (auto i = 0; i < 10; ++i)
		{
			const auto& v = sv.at(i);
			CHECK(v == i);
		}
	}
}

TEST_CASE("Выход за границы диапазона", "[simple_vector]")
{
	SECTION("Пустой список")
	{
		simple_vector<int> sv;

		CHECK_THROWS_AS(sv.at(0), std::out_of_range);
		CHECK_THROWS_AS(sv.at(1), std::out_of_range);
		CHECK_THROWS_AS(sv.at(5), std::out_of_range);
	}

	SECTION("Несколько элементов")
	{
		simple_vector<int> sv;
		for (auto i = 0; i < 5; ++i)
		{
			sv.push_back(i);
		}
		
		CHECK_THROWS_AS(sv.at(5), std::out_of_range);
		CHECK_THROWS_AS(sv.at(10), std::out_of_range);
	}
}

TEST_CASE("Модификация элементов", "[simple_vector]")
{
	SECTION("Несколько элементов")
	{
		simple_vector<int> sv;
		for (auto i = 0; i < 10; ++i)
		{
			sv.push_back(i);
		}

		for (auto i = 0; i < 10; ++i)
		{
			const auto newValue = i * 2;
			sv.at(i) = newValue;
			const auto& v = sv.at(i);
			CHECK(v == newValue);
		}
	}
}