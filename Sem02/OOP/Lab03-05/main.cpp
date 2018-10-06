/*
 * ЗАДАНИЕ 3
 * 1. Определить класс Child, который содержит такие поля (члены класса):
 * закрытые — имя ребенка, фамилию и возраст,
 * публичные — методы ввода данных и отображения их на экран.
 * Объявить два объекта класса, внести данные и показать их.
 * 2. Создать класс Tiles (кафель), который будет содержать поля с
 * открытым доступом: brand, size_h, size_w, price и метод класса
 * getData(). В главной функции объявить пару объектов класса и
 * внести данные в поля. Затем отобразить их, вызвав метод getData().
 * 3. Создать класс Complex, в котором реализовано комплексное
 * число. В данном классе должны присутствовать методы,
 * позволяющие рассчитать и вывеси модуль и аргументы данного
 * числа.
 * 4. Реализовать класс Vector, позволяющий хранить в себе
 * математический вектор. В классе должно присутствовать метод
 * позволяющей получить модуль вектора и методы, позволяющие
 * складывать и вычитать разные векторы.
 *
 * ЗАДАНИЕ 4
 * Из прошлой лабораторной работы дополнить всем видами
 * конструкторов и деструкторами классы:
 * 1. Complex
 * 2. Vector
 * 3. Tiles
 * 4. Child
 *
 * ЗАДАНИЕ 5
 * 1. Для класса Complex перегрузить операторы
 * присваивания, инкремента, декремента, сравнения, ввода и
 * вывода.
 * 2. Для класса Vector перегрузить операторы присваивания,
 * сравнения, ввода и вывода.
 */

#include "Child.h"
#include "Tiles.h"
#include "Complex.h"
#include "Vector.h"

int main() {
    //#1
    Child child_1("Izya", "Abramovich", 11), child_2;
    child_2.setFirstName("Kuz'ma");
    child_2.setSecondName("Domovoi");
    child_2.setAge(12);

    child_1.getInfo();
    cout << endl;
    child_2.getInfo();
    cout << endl;
    //end #1

    //#2
    Tiles tiles1("Aurora", 100, 120, 2534);
    Tiles tiles2("Aphina", 200, 250, 5760);
    cout << endl;
    tiles2.getData();
    //end #2

    //#3
    Complex a(5, 2);
    Complex b(3, -3);
    cout << "Operator < and >: " << (a < b) << " " << (a > b) << endl;
    cout << "a = " << a << ";\nb =" << b << endl;
    a += b;
    cout << "a = " << a << ";\nb =" << b << endl;
    a++, b++, --a, --b;
    cout << "a = " << a << ";\nb =" << b << endl;
    //end #3

    //#4
    double temp[] = {100, 100, 100};
    Vector vector(temp, 3);
    cout << vector.absVector() << endl;
    cin>>vector;
    Vector vector2(temp, 3);
    vector2=vector;
    cout<<vector2;
    return 0;
}