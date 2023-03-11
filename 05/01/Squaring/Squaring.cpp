#include <iostream>
#include <vector>

using namespace std;


template <class T>
void squaring(T& var)
{
	var *= var;
}

// не знаю насколько это правильно, но мне хотелось, чтоб
// vector мог принимать разные типы, первый вариант был...
// 
// template <>
// void squaring(std::vector<int>& vect)
template <typename VType>
void squaring(std::vector<VType>& vect)
{
	for (auto& data : vect) data *= data;
}

// перегружаю оператор << для cout (чтобы выводить std::vector<VType>)
template <typename VType>
std::ostream& operator<< (std::ostream& out, const std::vector<VType>& vect)
{
	for (const auto& val : vect) out << val << " ";
	return out;
}

template <typename dType>
void prinToConsole(const std::string& str, const dType& data)
{
	std::cout << "[" << str << "]: " << data << std::endl;
	if (str == "OUT") std::cout << std::endl;
}

int main()
{

	setlocale(LC_ALL, "Russian");              

	int intData(4);
	prinToConsole("IN", intData);
	squaring(intData);
	prinToConsole("OUT", intData);

	double doubleData(4.3);
	prinToConsole("IN", doubleData);
	squaring(doubleData);
	prinToConsole("OUT", doubleData);

	std::vector<int> vectorIntData{ -1, 4, 8 };
	prinToConsole("IN", vectorIntData);
	squaring(vectorIntData);
	prinToConsole("OUT", vectorIntData);

	std::vector<double> vectorDoubData{ -1, 4.2, 8.5 };
	prinToConsole("IN", vectorDoubData);
	squaring(vectorDoubData);
	prinToConsole("OUT", vectorDoubData);

	return 0;
}

 