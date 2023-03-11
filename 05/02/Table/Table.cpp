#include <iostream>
#include "Table.hpp"


using TableInt = Table<int>;

int main()
{
	using namespace std;
	setlocale(LC_ALL, "ru_RU.UTF-8");	
	std::system("cls");


	const int ROW(6), COL(10);
	auto tab = TableInt(ROW, COL);

	std::cout << "MyTable size: " << tab.getSize() << std::endl << std::endl;

	try
	{
		//tab[0][0] = 5;
		//tab[0][1] = 3;
		//tab[0][2] = 9;
		/*
		*/
		for (int i = 0; i < ROW; ++i)
		{
			for (int j = 0; j < COL; ++j)
			{
				tab[i][j] = (i + 1) * (j + 1);
				std::cout << tab[i][j] << "\t";
			}
			std::cout << std::endl;
		}
	}
	catch (std::runtime_error& err)
	{
		std::cout << "Error! " << err.what() << std::endl;
	}

	return 0;
}

