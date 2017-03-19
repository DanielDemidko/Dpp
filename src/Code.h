#pragma once
#include <string>
#include <vector>


namespace Code
{
    // Функция считывает код из файла
    std::vector<std::string> ReadFile(const std::string&);

    // Функция считывает код из строки
    std::vector<std::string> ReadString(const std::string&);
}
