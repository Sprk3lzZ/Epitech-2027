/*
** EPITECH PROJECT, 2024
** my_convert_temp.c
** File description:
** my_convert_temp.c
*/

#include <iostream>
#include <ios>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>

void StupidUnitConverter(void)
{
    std::string line;

    while(true) {
        std::getline(std::cin, line);
        std::istringstream iss(line);
        float temp;
        std::string type;
        std::cout << std::fixed << std::setw(16) << std::setprecision(3);
        if (!(iss >> temp)) {
            continue;
        }
        if (!(iss >> type)) {
            continue;
        }
        if (type == "Celsius") {
            std::cout << std::setw(16) << std::right << temp / (5.0 / 9.0) + 32.0 << "      Fahrenheit" << std::endl;
        } else if (type == "Fahrenheit") {
            std::cout << std::setw(16) << std::right << (5.0 / 9.0) * (temp - 32) << "         Celsius" << std::endl;
        }
    }
}

int main(void)
{
    StupidUnitConverter();
    return 0;
}
