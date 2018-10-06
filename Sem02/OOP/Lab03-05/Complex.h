#ifndef LAB3_COMPLEX_H
#define LAB3_COMPLEX_H

#pragma once
#include <iostream>

using namespace std;

class Complex {
private:
    double re, im;

public:
    Complex(double r, double i);

    Complex();

    ~Complex();

    double const absComplex();

    Complex &operator=(const Complex &c);

    Complex &operator+=(Complex &c);

    Complex operator+(const Complex &c);

    Complex operator-(const Complex &c);

    Complex operator*(const Complex &c);

    Complex operator/(const Complex &c);

    friend Complex operator++(Complex &c);

    friend Complex operator++(Complex &c, int);

    friend const Complex operator--(Complex &c, int);

    friend const Complex operator--(Complex &c);

    friend bool operator>(Complex& cl, Complex& cr);

    friend bool operator<(Complex& cl, Complex& cr);

    friend ostream &operator<<(ostream &, Complex &);

    friend istream &operator>>(istream &, Complex &);
};




#endif //LAB3_COMPLEX_H
