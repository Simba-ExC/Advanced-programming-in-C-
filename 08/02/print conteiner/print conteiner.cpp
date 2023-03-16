#include <iostream>
#include <set>
#include <vector>
#include <list>



template <class N>
void print_container(const N& cont, const std::string& str)
{
	std::cout << str << ": ";

	for (auto it = cont.cbegin(); it != cont.cend(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

}

int main()
{
	using namespace std;
	setlocale(LC_ALL, "Russian");   

	std::set<std::string> test_set = { "one", "two", "three", "four" };


	std::list<std::string> test_list = { "one", "two", "three", "four" };
	print_container(test_list, "test_list"); // one, two, three, four

	std::vector<std::string> test_vector = { "one", "two", "three", "four" };
	print_container(test_vector, "test_vector"); // one, two, three, four


	return 0;
}

