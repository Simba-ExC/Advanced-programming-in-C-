#include <iostream> 
#include <vector>
#include <variant>

// функция случайным образом вырасывающая: int, string, vector
std::variant<int, std::string, std::vector<int>> get_variant()
{
	std::srand(std::time(nullptr));
	int random_variable = std::rand() % 3;

	std::variant<int, std::string, std::vector<int>> result;
	switch (random_variable)
	{
	case 0:
		result = 5;
		break;
	case 1:
		result = "string";
		break;
	case 2:
		result = std::vector<int>{ 1, 2, 3, 4, 5 };
		break;
	default:
		break;
	}
	return result;
}

// перегружаю оператор << для cout (чтобы выводить std::vector<int>)
std::ostream& operator<< (std::ostream& out, const std::vector<int>& vect)
{
	for (const auto& val : vect) out << val << " ";
	return out;
}

// перегружаю оператор << для cout (чтобы выводить std::variant<int, std::string, std::vector<int>>)
std::ostream& operator<< (std::ostream& out, const std::variant<int, std::string, std::vector<int>>& var)
{
	// visit определяет текущий индекс variant и отдает его лямбде
	visit( [&out](auto& elem) { out << elem << std::endl; }, var);
	return out;
}

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "Russian");   // задаём русский текст
    system("chcp 1251");            // настраиваем кодировку консоли
    std::system("cls");

	auto var = get_variant();		// получаю какой то variant
	// если это int -> умножаю на 2
	if (std::holds_alternative<int>(var)) std::get<int>(var) *= 2;
	std::cout << var << std::endl;	// вывожу в консоль

    return 0;
}