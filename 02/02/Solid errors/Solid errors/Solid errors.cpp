﻿
#include <iostream>

int main()
{
    //Синтаксическая ошибка 

    int a = 5; 
    std::cout << a - b; // Если не инициализировать (объявить) переменную до операций с ней, компилятор сообщит, что данная переменная не инициализирована. надо обьявить перед cout
    int b = 2;

    /*int a = 5;
    int b = 2;                  должно быть вот так 
    std::cout << a - b;*/


    //Семантические ошибки



    int count{ 1 };
    while (count <= 10) // это условие никогда не будет ложным
    {
        std::cout << count << ' '; // поэтому эта строка выполняется многократно
    }

    return 0; // эта строка никогда не будет выполнена

    // В этом случае мы забыли увеличить count, поэтому условие цикла никогда не будет ложным, и цикл продолжит печатать: 1 1 1 1 1 1 1 1 1 1


    /*int count{ 1 };
    while (count <= 10) 
    {
        std::cout << count << ' ';    должно быть вот так 
        count++;
    }
    return 0; */
  

    //Семантические ошибки

    // мы хотим подключить класс summ.h
    #include <../summ.h>

    // но мы забыли его дабваить в каталог программы или ошиблись в имени класса  

}

