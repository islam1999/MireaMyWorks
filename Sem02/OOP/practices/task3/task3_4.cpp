#include <iostream>

class Vector {
public:
    int a, b, c;
    Vector(int a, int b, int c): a{a}, b{b}. c{c} {}
    Vector operator+(const Vector& a, const Vector& b) {
        return Vector(a.a + b.a, a.b + b.b, a.c + b.c);
    }
    Vector operator-(const Vector& a, const Vector& b) {
        return Vector(a.a - b.a, a.b - b.a, a.c - b.c);
    }
};
