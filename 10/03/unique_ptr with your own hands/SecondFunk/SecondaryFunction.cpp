#include "SecondaryFunction.h"

// подсчет длины UTF-8
// подсмотрел тута: 
// https://translated.turbopages.org/proxy_u/en-ru.ru.8469f9a8-63bd626e-6376c26f-74722d776562/https/stackoverflow.com/questions/4063146/getting-the-actual-length-of-a-utf-8-encoded-stdstring).
size_t utf8_strlen(const std::string& str)
{
	size_t c, i, ix, q;
	for (q = 0, i = 0, ix = str.length(); i < ix; i++, q++)
	{
		c = (unsigned char)str[i];
		if (c >= 0 && c <= 127) i += 0;
		else if ((c & 0xE0) == 0xC0) i += 1;
		else if ((c & 0xF0) == 0xE0) i += 2;
		else if ((c & 0xF8) == 0xF0) i += 3;
		//else if (($c & 0xFC) == 0xF8) i+=4; // 111110bb //byte 5, unnecessary in 4 byte UTF-8
		//else if (($c & 0xFE) == 0xFC) i+=5; // 1111110b //byte 6, unnecessary in 4 byte UTF-8
		else return 0;//invalid utf8
	}
	return q;
}

// заголовок
void printHeader(const std::string& str)
{
	using namespace std;
	setlocale(LC_ALL, "ru_RU.UTF-8");	// задаем русский текст
	//system("chcp UTF-8");				// настраиваем кодировку консоли
	//system("chcp ANSI");				// настраиваем кодировку консоли
	//system("chcp 1251");				// настраиваем кодировку консоли
	//SetConsoleOutputCP(CP_UTF8);
	
	//SetConsoleTitleA("Заголовок");
	system("cls");
	consoleCol(11);
	std::cout << str << "\n";
	for (auto i = 0; i < utf8_strlen(str); ++i)
		cout << "-";
	cout << "\n\n";
	consoleCol();
}

void consoleCol(WORD color) // по умолчанию белый на черном фоне
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
