#pragma once

#include <Windows.h>	// for color change of text and background, заголовок консоли
#include <iostream>
#include <string>

size_t utf8_strlen(const std::string& str);		// ох уж эти кодировки Русского и могучего!

void printHeader(const std::string& str);		// заголовок

/*
	00 - черный
	01 - синий
	02 - зеленый
	03 - голубой
	04 - красный
	05 - фиолетовый
	06 - желтый
	07 - белый
	----
	08 - серый
	09 - ярк. синий
	10 - ярк. зеленый
	11 - ярк. голубой
	12 - ярк. красный
	13 - ярк. фиолетовый
	14 - ярк. желтый
	15 - ярк. белый
*/
void consoleCol(WORD color = 7); // по умолчанию белый на черном фоне
