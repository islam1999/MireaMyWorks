#ifndef LAB7_STUDENT_H
#define LAB7_STUDENT_H

#include "Human.h"

class Student: public Human {
private:
    bool on_lesson;
public:
    Student(string surname, string name, string midname, int age, bool on_lesson);

    ~Student() = default;

    void print() override;
};

#endif //LAB7_STUDENT_H
