/*
** EPITECH PROJECT, 2024
** Student.cpp
** File description:
** Student.cpp
*/

#include "Student.hpp"

Student::Student(std::string name)
{
    this->name = name;
    this->energy = 100;

    std::cout << "Student " << name << " I'm ready to lean C++" << std::endl;
}

Student::~Student()
{
    std::cout << "Student " << name << " Wow, much learning today, very smart, such C++" << std::endl;
}

bool Student::learn(std::string sentence)
{
    std::string toReplace = "C++";
    std::string replaceWith = "shit";
    std::size_t found = sentence.find(toReplace);

    if (energy >= 42) {
        this->energy -= 42;
        std::cout << "Student " << name << ": " << sentence << std::endl;
        return true;
    } else {
        while (found != std::string::npos) {
            sentence.replace(found, toReplace.length(), replaceWith);
            found = sentence.find(toReplace, found + replaceWith.length());
        }
        std::cout << "Student " << name << ": " << sentence;
        return false;
    }
}

void Student::drink(std::string potion)
{
    if (potion == "Red bull") {
        std::cout << "Student " << name << ": " << potion << "gives you wings";
        energy += 32;
    } else if (potion == "Monster") {
        std::cout << "Student " << name << ": " << potion << "Unleash The Beast";
        energy += 32;
    } else {
        std::cout << "Student " << name << ": " << potion << "ah, yes... enslaved moisture";
        energy += 1;
    }

    if (energy > 100)
        energy = 100;
}
