#include <iostream> // консоль - cout
#include <vector>
#include <algorithm>    // std::for_each

void print(const std::vector<int>& v, const std::string& str)
{
    std::cout << str << " данные: ";
    for (const auto& val : v) std::cout << val << " ";
    std::cout << std::endl;
}

int main(int argc, char** argv)
{
   setlocale(LC_ALL, "Russian");  
    system("chcp 1251");            
    std::system("cls");


    std::vector<int> vect{ 4, 7, 9, 14, 12 };

    print(vect, "Входные");

    std::for_each(std::begin(vect), std::end(vect),
        [](int& value) { if (value % 2) value *= 3; });

    print(vect, "Выходные");

    return 0;
}