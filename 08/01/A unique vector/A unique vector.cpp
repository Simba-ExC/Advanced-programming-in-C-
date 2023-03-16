#include <iostream>
#include <vector>
#include <algorithm>


void delDubls(std::vector<int>& vec)
{
	std::sort(vec.begin(), vec.end());
	vec.erase((std::unique(vec.begin(), vec.end())), vec.end());
}


template <typename VType>
std::ostream& operator<< (std::ostream& out, const std::vector<VType>& vect)
{
	for (const auto& val : vect) out << val << " ";
	return out;
}

int main()
{
	using namespace std;
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");
	std::system("cls");


	std::vector<int> vec{ 1, 1, 2, 5, 6, 1, 2, 4 };
	std::cout << "[IN]: " << vec << std::endl;

	delDubls(vec);

	std::cout << "[OUT]: " << vec << std::endl;

	return 0;
}


