#ifndef LAB1_C_COMPLEX_H
#define LAB1_C_COMPLEX_H

typedef struct complex{
    double re, im;
} Complex;

double abs_complex(Complex *comp);
Complex *plus(Complex *comp1, Complex *comp2);
Complex *minus(Complex *comp1, Complex *comp2);
Complex *multiply (Complex *comp1,Complex *comp2);
Complex *divide (Complex *comp1, Complex *comp2);
void print_complex(Complex *complex);
int read(FILE *file, Complex *complex);
int calculate(FILE *input_file);
#endif //LAB1_C_COMPLEX_H
