/*
** EPITECH PROJECT, 2024
** main.cpp
** File description:
** main.cpp
*/

#include <iostream>
#include <ios>
#include <string>
#include <fstream>

bool MyCat(int ac, char **av)
{
    std::string line;
    std::ifstream file;
    bool status = true;

    if (ac == 1) {
        std::cerr << "MyCat: Usage: ./MyCat file [...]" << std::endl;
        status = false;
    }
    for (int i = 1; i < ac; i++) {
        file.open(av[i]);
        if (!file.is_open()) {
            std::cerr << "MyCat: " << av[i] << ": No such file or directory" << std::endl;
            status = false;
        }
        while (getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.close();
    }
    return status;
}

int main(int ac, char **av)
{
    if (!MyCat(ac, av))
        return 84;
    return 0;
}
