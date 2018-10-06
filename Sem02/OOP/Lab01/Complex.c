#include <stdio.h>
#include <math.h>
#include "Complex.h"

double abs_complex(Complex *comp) {
    return sqrt(comp->re * comp->re + comp->im * comp->im);
}

Complex *plus(Complex *comp1, Complex *comp2) {
    comp1->re += comp2->re;
    comp1->im += comp2->im;
    return comp1;
}

Complex *minus(Complex *comp1, Complex *comp2) {
    comp1->re -= comp2->re;
    comp1->im -= comp2->im;
    return comp1;
}

Complex *multiply (Complex *comp1,Complex *comp2) {
    comp1->re = comp1->re*comp2->re - comp1->im*comp2->im;
    comp1->im = comp1->re*comp2->im + comp1->im*comp2->re;
    return comp1;
}

Complex *divide (Complex *comp1, Complex *comp2) {
    double r = comp2->re * comp2->re + comp2->im * comp2->im;
    comp1->re = (comp1->re * comp2->re + comp1->im * comp2->im) / r;
    comp1->im = (comp1->im * comp2->re - comp1->re * comp2->im) / r;
    return comp1;
}

void print_complex(Complex *complex){
    printf("[%.2lf%+.2lf.i]\n", complex->re, complex->im);
}

int read(FILE *file, Complex *complex) {
    char op;
    int res;
    if ((res = fscanf(file, "(%lf %c %lfi)", &complex->re, &op, &complex->im)) != EOF && res == 3) {
        complex->im *= op == '-' ? -1 : 1;
        return 1;
    }
    return -1;
}

int calculate(FILE *input_file){
    Complex complex1;
    Complex complex2;
    char operator;
    char op1, op2;
    if ( fscanf(input_file, "(%lf %c %lfi) %c (%lf %c %lfi)", &complex1.re, &op1, &complex1.im, &operator, &complex2.re, &op2, &complex2.im) < 7)
        operator = 'e';
    complex1.im *= op1 == '-' ? -1 : 1;
    complex2.im *= op2 == '-' ? -1 : 1;
    switch (operator) {
        case '+':
            plus(&complex1, &complex2);
            break;
        case '-':
            minus(&complex1, &complex2);
            break;
        case '*':
            multiply(&complex1, &complex2);
            break;
        case '/':
            divide(&complex1, &complex2);
            break;
        default:
            printf("=>>Input error.\n");
            return -1;
    }
    print_complex(&complex1);
    fclose(input_file);
}