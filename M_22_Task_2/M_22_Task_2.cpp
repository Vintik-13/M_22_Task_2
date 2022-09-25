/*Задание 2. Регистратура

Что нужно сделать
Напишите программу «Регистратура».
На вход программе приходят строки с фамилиями или строка Next.
Пришедшие люди становятся в очередь, а по запросу Next необходимо
вызвать в регистратуру человека с фамилией, идущей первой в
лексикографическом порядке (по алфавиту), и вывести его фамилию
на экран. Фамилии пациентов могут повторяться.
Каждый запрос (на добавление и вывод) должен работать за O(logn).*/

#include <iostream>
#include <map>
#include <string>

const std::string COMAND = "Next";

void addMan(std::multimap<std::string, int>& reg, std::string name) {
    reg.emplace(name, 0);
}

bool showMan(std::multimap<std::string, int>& reg, int& pos ) {
    std::multimap<std::string, int>::iterator it = reg.begin();
    std::advance(it, pos);
    if (it != reg.end()) {
        std::cout << it->first << std::endl;
        pos++;
        return true;
    }
    else
        return false;    
}


int main()
{
    std::multimap<std::string, int> reg;
    int pos{ 0 };
    bool cycle = true;
    std::string comand;
    while (cycle) {
        std::cout << "Enter your last name or \"Next\"";
        std::getline(std::cin, comand);
        if (comand != COMAND) {
            addMan(reg, comand);
        }
        else {
            cycle = showMan(reg, pos);
        }
    }    
}
