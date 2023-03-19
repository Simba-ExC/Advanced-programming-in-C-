#include <iostream>
#include <string>

class Big_integer
{
private:
	std::string num;

public:
	Big_integer(std::string value) : num(value) {}

	Big_integer(Big_integer&& other) noexcept : num(std::exchange(num, other.num)) {}

	Big_integer& operator=(Big_integer&& other) noexcept
	{
		std::swap(num, other.num);
		return *this;
	}

	int operator+(Big_integer& other)
	{
		int number1 = std::stoi(num);
		int number2 = std::stoi(other.num);
		int result = number1 + number2;

		return result;
	}

	long long operator*(Big_integer& other)
	{
		int number1 = std::stoi(num);
		int number2 = std::stoi(other.num);
		int result = number1 * number2;

		return result;
	}
};

int main()
{
	auto number1 = Big_integer("114575");
	auto number2 = Big_integer("78524");
	auto result = number1 * number2;
	std::cout << result;
}