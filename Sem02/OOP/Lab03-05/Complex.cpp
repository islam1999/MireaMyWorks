#include <cmath>
#include "Complex.h"

Complex::Complex(double r, double i) {
    re = r;
    im = i;
}

Complex::Complex(){
    re = 0;
    im = 0;
}

Complex::~Complex() = default;

double const Complex::absComplex() {
    return sqrt(re * re + im * im);
}

Complex &Complex::operator=(const Complex &c) {
    re = c.re;
    im = c.im;
    return *this;
}

Complex &Complex::operator+=(Complex &c) {
    re += c.re;
    im += c.im;
    return *this;
}

Complex Complex::operator+(const Complex &c) {
    return Complex(re + c.re, im + c.im);
}

Complex Complex::operator-(const Complex &c) {
    return Complex(re - c.re, im - c.im);
}

Complex Complex::operator*(const Complex &c) {
    return Complex(re * c.re - im * c.im, re * c.im + im * c.re);
}

Complex Complex::operator/(const Complex &c) {
    Complex temp;

    double r = c.re * c.re + c.im * c.im;
    temp.re = (re * c.re + im * c.im) / r;
    temp.im = (im * c.re - re * c.im) / r;

    return temp;
}

Complex operator++(Complex& c) {
    c.re++;
    return c;
}

Complex operator++(Complex& c, int) {
    Complex old = c;
    c.re++;
    return old;
}

const Complex operator--(Complex& c, int){
    Complex old = c;
    c.re--;
    return old;
}

const Complex operator--(Complex& c){
    c.re--;
    return c;
}

bool operator>(Complex& cl, Complex& cr){
    return cl.absComplex() > cr.absComplex();
}

bool operator<(Complex& cl, Complex& cr){
    return cl.absComplex() < cr.absComplex();
}

ostream &operator<<(ostream &out, Complex &c) {
    out << "[" << c.re << ", " << c.im << "]" << endl << "abs: " << c.absComplex();
    return out;
}

istream &operator>>(istream &in, Complex &c) {
    in >> c.re >> c.im;
    return in;
}