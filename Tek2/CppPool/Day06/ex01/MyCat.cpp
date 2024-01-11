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

int MyCat(int ac, char **av)
{
    std::string line;
    std::ifstream file;

    if (ac == 1) {
        std::cout << "MyCat: Usage: ./MyCat file [...]" << std::endl;
        return 84;
    }
    for (int i = 1; i < ac; i++) {
        file.open(av[i]);
        if (!file.is_open()) {
            std::cout << "MyCat: " << av[i] << ": No such file or directory" << std::endl;
            return 84;
        }
        while (getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.close();
    }
    return 0;
}

int main(int ac, char **av)
{
    return (MyCat(ac, av));
}
