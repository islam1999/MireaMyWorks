/*
 * Создать базовый абстрактных класс «Человек», имеющий
 * нереализованную виртуальную функцию вывода информации на
 * экран. Затем создать классы «Ученик» и «Босс», уна- следованные от
 * него.
 */

#include "Student.h"
#include "Boss.h"


int main() {
    Student student("SURNAME", "NAME", "MIDNAME", 20, true);
    student.print();
    Boss boss("SURNAME", "NAME", "MIDNAME", 55, 241);
    boss.print();
    return 0;
}