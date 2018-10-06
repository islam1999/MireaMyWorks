#include "Human.h"

Human::Human() {
    surname = "";
    name = "";
    midname = "";
    age = 0;
}

Human::Human(string surname, string name, string midname, int age) {
    this->surname = surname;
    this->name = name;
    this->midname = midname;
    this->age = age;
}