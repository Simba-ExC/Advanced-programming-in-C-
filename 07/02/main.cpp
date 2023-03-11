#include <iostream>
#include <set>
#ifdef _WIN32
#include "windows.h"
#endif


int main()
{
	setlocale(LC_ALL, "Russian");
#ifdef _WIN32
	SetConsoleCP(1251);
#endif

	size_t count = 0;
	std::cout << "[IN]: " << std::endl;
	std::cin >> count;
	std::set<int, std::greater<int>> valueSet;
	for (size_t i = 0; i < count; ++i)
	{
		int v;
		std::cin >> v;
		valueSet.insert(v);
	}

	std::cout << "[OUT]:" << std::endl;
	for (const auto& v : valueSet)
	{
		std::cout << v << std::endl;
	}
}