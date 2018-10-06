#include "Vector.h"
#include <cmath>

Vector::Vector(const double *values, int size) {
    this->size = size;
    this->values = new double[size];

    for (int i = 0; i < this->size; ++i)
        this->values[i] = values[i];
}

Vector::Vector(){
    size = 0;
    values = nullptr;
}

Vector::~Vector() {
    delete[] values;
}

Vector &Vector::operator=(const Vector &v){
    for (int i = 0; i < size; ++i) {
        values[i] = v.values[i];
    }
    return *this;
}

Vector Vector::operator+(const Vector &vector) {
    Vector temp;
    temp.size = size;
    temp.values = new double[size];

    for (int i = 0; i < size; ++i) {
        temp.values[i] = values[i] + vector.values[i];
    }
    return temp;
}

Vector Vector::operator-(const Vector &vector) {
    Vector temp;
    temp.size = size;
    temp.values = new double[size];

    for (int i = 0; i < size; ++i) {
        temp.values[i] = values[i] - vector.values[i];
    }
    return temp;
}

double Vector::absVector(){
    double sum=0;
    for (int i = 0; i < size; ++i) {
        sum+= pow(values[i], 2);
    }
    return sqrt(sum);
}

bool operator>(Vector& vl, Vector& vr){
    return vl.absVector() > vr.absVector();
}

bool operator<(Vector& vl, Vector& vr){
    return vl.absVector() < vr.absVector();
}

ostream &operator<<(ostream &out, Vector &v) {
    for (int i = 0; i < v.size; ++i) {
        cout<< v.values[i]<<" ";
    }
    cout<<endl;
    return out;
}

istream &operator>>(istream &in, Vector &v) {
    for (int i = 0; i < v.size; ++i) {
        in >> v.values[i];
    }
    return in;
}