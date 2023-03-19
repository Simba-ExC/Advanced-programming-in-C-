#include <iostream>
#include <memory>

#include "Unique.hpp"

struct S
{
    S() : a(0), b(0) {}
    S(int _a, double _b) : a(_a), b(_b) {}
    friend std::ostream& operator<< (std::ostream& out, const S& s)
    {
        return out << "\na = " << s.a << "\nb = " << s.b << "\n\n";
    }

    int a;
    double b;
};

int main()
{
    setlocale(LC_ALL, "Russian");
    

    unique_ptr<S>unicPtr(new S(5, 16.58));
    std::cout << "addr unicPtr: " << &unicPtr << " -> obj: " << unicPtr << "\n";

    std::cout << "\nunicPtr: " << *unicPtr;
    *unicPtr = { 6, 18.3 };
    std::cout << "unicPtr: " << *unicPtr;

    S* relPtr = unicPtr.release();
    std::cout << "addr  relPtr: " << &relPtr << " -> obj: " << relPtr << "\n";
    std::cout << "Old pointer is                      -> " << unicPtr << "\n";

    delete relPtr;

    try
    {
        std::cout << "unicPtr: " << *unicPtr;
    }
    catch (const std::exception& err)
    {
        std::cout << "\nОшибка типа: " << typeid(err).name() << "\n";
        std::cout << err.what() << "\n";
    }
    catch (const ExeptNotPtr)
    {
        std::cout << "\nОшибка: Пустой указатель (nullptr)!" << "\n";
    }

    return 0;
}