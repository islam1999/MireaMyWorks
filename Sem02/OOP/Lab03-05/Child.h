//
// Created by khitr on 24.02.2018.
//

#ifndef LAB3_CHILD_H
#define LAB3_CHILD_H

#pragma once
#include <iostream>
using namespace std;

class Child {
private:
    string firstName;
    string secondName;
    int age;
public:
    Child(string firstName, string secondName, int age);

    Child();

    ~Child();

    void setFirstName(string name);

    void setSecondName(string name);

    void setAge(int age);

    void getInfo();
};


#endif //LAB3_CHILD_H
