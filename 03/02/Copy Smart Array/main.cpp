#include <iostream>
#include "SmartArray.h"

int main()
{
	setlocale(LC_ALL, "Russian");

	SmartArray arr(5);
	arr.addElement(1);
	arr.addElement(4);
	arr.addElement(155);

	SmartArray newArray(2);
	newArray.addElement(44);
	newArray.addElement(34);

	arr = newArray;
	newArray = newArray;
}