#include <iostream>
#include <fstream>
#include <string>
#include "TextScan.h"

using namespace std;

void TextScaner()
{
    fstream file; // создаем поток ввода
    file.open("Text.txt"); // открытие файла

    if (!file.is_open()) // если файл не открылся
    {
        cout << "Ошибка открытия файла!" << endl;
        exit(0);
    }

    else
    {
        string line; // строка, в которую будут считываться значения из файла
        unsigned int flag_one = 0; // "" флаг на двойные кавычки
        unsigned int flag_two = 0; // '' флаг на одинарные кавычки 

        while (!file.eof()) // пока не конец файла
        {
            getline(file, line); // считываем строку 

            for (int id = 0; id < line.size(); id++) // перебираем символы в строке
            {
                if (flag_one) // если двойные кавычки встретились раньше
                { 
                    if (line[id] == '"') // если символ закрывающие двойные кавычки
                    {
                        flag_one = 0; // меняем флаг 
                        cout << "\n";
                        continue; // переходим на следующую итерацию
                    } 

                    cout << line[id]; // выводим символы
                }

                else if (flag_two) // если одинарные кавычки (аналогично с двойными)
                {
                    if (line[id] == '\'')
                    { 
                        cout << "\n";
                        continue;
                    }
                     
                    cout << line[id];
                }

                if (line[id] == '"' && flag_two == 0) flag_one = 1; // если встретились двойные кавычки и не было одинарных, меняем флаг
                if (line[id] == '\'' && flag_one == 0) flag_two = 1; // так же, как и с двойными, только с одинарными
            }
        }
    }
     
    file.close(); // закрываем файл
}
 