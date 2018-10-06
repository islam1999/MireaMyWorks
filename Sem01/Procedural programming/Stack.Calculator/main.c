#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Stack.h"

int main(int argc, char *argv[]) {

    stack *st = create_stack(sizeof(double));
    char str[128];
    printf("Enter a string to calculate: \n");
    gets(str);

    int i=0;
    double tmp;
    char *ptr = NULL;
    while(str[i] != '\0') {
        if (isdigit(str[i])) {
            tmp = strtod(str + i, &ptr);
            if (str + i - 1 == (char *) '-')
                tmp *= -1.0;
            push(st, &tmp);
            i += (int) (ptr - (str + i));
        } else {
            double a, b;
            if (str[i] == '+') {
                pop(st, &b);
                pop(st, &a);
                a += b;
                push(st, &a);
            } else if (str[i] == '-' && !isdigit(str[i + 1])) {
                pop(st, &b);
                pop(st, &a);
                a -= b;
                push(st, &a);
            } else if (str[i] == '*') {
                pop(st, &b);
                pop(st, &a);
                a *= b;
                push(st, &a);
            } else if (str[i] == '/') {
                pop(st, &b);
                pop(st, &a);
                a /= b;
                push(st, &a);
            }
        }
        i++;
    }
    double res;
    pop(st, &res);
    printf("%lf",res);

    free_stack(st);

    return 0;
}