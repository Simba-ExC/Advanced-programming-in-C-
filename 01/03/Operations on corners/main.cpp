#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

int main()
{
    // Константа Пи с интересующей нас точностью
    static const double Pi = 3.1415926;
    setlocale(LC_ALL, "Russian");

    // 1. Объявляем массив углов в градусах
    std::vector anglesGrad{ 30.0, 60.0, 90.0 };
    std::cout << "[Входные данные]: ";

    // 2. Выводим на экран в градусах специальном виде
    bool firstItem;
    std::for_each(
        anglesGrad.begin(), 
        anglesGrad.end(), 
        [firstItem = true](const auto x)mutable
        {
            if (!firstItem)
            {
                std::cout << ", ";
            }

            firstItem = false;
            std::cout << x << " * " << Pi << " / 180";
        });

    std::cout << std::endl;

    // 3. Преобразуем в радианы
    std::vector<double> anglesRad;
    std::for_each(anglesGrad.begin(), anglesGrad.end(), [&anglesRad](auto x) { anglesRad.push_back(x * Pi / 180.0); });

    // 4. Объявляем массив функций
    std::vector<std::function<void(double)>> functions
    {
        [](double x) { std::cout << "sin: " << std::sin(x) << " "; },
        [](double x) { std::cout << "cos: " << std::cos(x) << " "; }
    };

    // 5. Применяем функции
    std::cout << "[Выходные данные]: ";
    for (const auto& angle : anglesRad) {
        std::cout << angle << ": ";
        for (const auto& function : functions)
        {
            function(angle);
        }

        std::cout << std::endl;
    }

    return 0;
}
