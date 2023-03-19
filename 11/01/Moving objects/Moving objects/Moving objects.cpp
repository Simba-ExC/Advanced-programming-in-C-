#include <vector>
#include <iostream>

using namespace std;

template <class Vtype>
void move_vectors(std::vector<Vtype>& where, std::vector<Vtype>& from)
{
	std::cout << "\nmove_vectors\n\n";
	where = std::move(from);
}

template <class Vtype>
void print(const std::vector<Vtype>& vec, const std::string& str);

int main(int argc, char** argv)
{

	std::vector <std::string> one = { "test_string1", "test_string2" };
	std::vector <std::string> two;

	print<std::string>(one, "one");
	print<std::string>(two, "two");

	move_vectors<std::string>(two, one);

	print<std::string>(one, "one");
	print<std::string>(two, "two");

	return 0;
}


template <class Vtype>
inline void print(const std::vector<Vtype>& vec, const std::string& str)
{
	if (!vec.empty())
	{
		std::cout << "vector " << str << ":\n";
		for (const auto& elem : vec) std::cout << elem << "\n";
	}
}