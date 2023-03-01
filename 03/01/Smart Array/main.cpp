#include <iostream>
#include "SmartArray.h"

int main()
{
	setlocale(LC_ALL, "Russian");

	try {
		SmartArray arr(5);
		arr.addElement(1);
		arr.addElement(4);
		arr.addElement(155);
		arr.addElement(14);
		arr.addElement(15);

		for (auto i = 0; i < arr.getLength(); ++i)
		{
			std::cout << "arr[" << i << "]: " << arr.getElement(i) << std::endl;
		}

		// Не скомпилируется: конструктор копирования удален
		// SmartArray arr1 = arr;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
}