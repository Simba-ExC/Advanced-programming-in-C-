#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
#ifdef _WIN32
#include "windows.h"
#endif


int main()
{
	setlocale(LC_ALL, "Russian");
#ifdef _WIN32
	SetConsoleCP(1251);
#endif

	std::string input;
	std::cout << "[IN]: ";
	std::getline(std::cin, input);

	// На лекции было предложено решить задачу, воспользоваашись свойствами контейнеров
	// Считаем количества
	std::unordered_map<char, unsigned int> charMap;
	for (const auto& c : input)
	{
		auto it = charMap.find(c);

		if (it == charMap.end())
		{
			charMap.insert({ c, 1 });
		}
		else
		{
			++((*it).second);
		}
	}

	// Переупорядочиваем
	std::multimap<unsigned int, char, std::greater<char>> charOrderMap;
	for (const auto& [c, count] : charMap)
	{
		charOrderMap.insert({ count, c });
	}

	// Выводим на экран
	std::cout << "[OUT]:" << std::endl;
	for (const auto& [count, c] : charOrderMap)
	{
		std::cout << c << ": " << count << std::endl;
	}
}