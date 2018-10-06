//
// Created by khitr on 24.02.2018.
//

#include "Child.h"

Child::Child(string firstName, string secondName, int age) {
    this->firstName = firstName;
    this->secondName = secondName;
    this->age = age;
}

Child::Child() {
    this->firstName = "";
    this->secondName = "";
    this->age = 0;
}

Child::~Child() = default;

void Child::setFirstName(string name) {
    firstName = name;
}

void Child::setSecondName(string name) {
    secondName = name;
}

void Child::setAge(int age) {
    this->age = age > 0 ? age : 0;
}

void Child::getInfo() {
    cout << "First Name: " << firstName << endl <<
         "Second Name: " << secondName << endl <<
         "Age: " << age << endl;
}
