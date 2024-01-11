/*
** EPITECH PROJECT, 2024
** Student.hpp
** File description:
** Student.hpp
*/

#pragma once

#include <string>
#include <iostream>

class Student {
    public:
        Student(std::string name);
        ~Student();

        bool learn(std::string sentence);
        void drink(std::string potion);
    private:
        std::string name;
        int energy;
};
