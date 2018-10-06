#include "Student.h"

Student::Student(
        string surname, string name, string midname, int age, bool on_lesson)
        :Human(surname, name, midname, age) {
    this->on_lesson = on_lesson;
}

void Student::print() {
    cout << "\nSurname: " << surname << "\nName: " << name
         << "\nMidname: " << midname << "\nAge: " << age
         << "\nOn lesson: " << on_lesson;
}