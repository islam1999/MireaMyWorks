/*
 * 1) Создать класс «Староста», производный от класса «Студент».
 * Новый класс должен содержать несколько дополнительных
 * методов и полей.
 * 2) Создать класс Alive и расширить его до Bird, Fish, Animal
 * 3) Создать класс Animal, и расширить его до Dog, Cat.
 */

#include <iostream>
using namespace std;
//#1
class Student {
public:
    string name;
    string group;

    Student(string name, string group) {
        this->name = name;
        this->group = group;
    }

    string getName() {
        return name;
    }

    void changeGroup(string newGroup){
        group = newGroup;
    }
};

class Chief: public Student{
private:
    bool hasJournal;
public:
    Chief(bool hasJournal,string nameC, string groupC):Student(nameC, groupC){
        this->hasJournal = hasJournal;
    }

    bool isJournal(){
        return hasJournal;
    }
};
//end #1

//#2
class Alive{
public:
    Alive()= default;
};

class Bird:public Alive{
public:
    Bird():Alive(){};
};

class Fish:public Alive{
    Fish():Alive(){};
};

class Animal: public Alive{
public:
    Animal():Alive(){};
};
//end #2

//#3
class Dog: public Animal{
    Dog():Animal(){};
};

class Cat: public Animal{
    Cat():Animal(){};
};
//end #3
int main() {
    return 0;
}