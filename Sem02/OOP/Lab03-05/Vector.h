#ifndef LAB3_VECTOR_H
#define LAB3_VECTOR_H

#include <iostream>
using namespace std;

class Vector {
public:
    double *values;
    int size;

    Vector(const double *values, int size);

    Vector();

    ~Vector();

    Vector &operator=(const Vector &v);

    Vector operator+(const Vector &vector);

    Vector operator-(const Vector &vector);

    double absVector();

    friend bool operator>(Vector& vl, Vector& vr);

    friend bool operator<(Vector& vl, Vector& vr);

    friend ostream &operator<<(ostream &out, Vector &v);

    friend istream &operator>>(istream &in, Vector &v);
};


#endif //LAB3_VECTOR_H
