#include <stdio.h>
#include <cmath>

using namespace std;

int main() {
    double a = 3.5, x = -0.7, y, t;

    if (a <= x) {
        y = a + log2(x+a);
    } else {
        y = sqrt(sin(a*x));
    }

    if (a > y) {
        t = y/(a-x);
    } else if (a == y) {
        t = y/(a-x) + (a+x)/(y*y);
    } else {
        t = tan(a*x) + cos(2*a*y);
    }

    printf("a: %lg\nx: %lg\ny: %lg\nt: %lg\n", a, x, y, t);

    return 0;
}
