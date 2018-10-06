#include <stdio.h>
#include <cmath>

using namespace std;

int main() {
    double a = 4.6, b = 1.5, y, t;

    if (a <= b) {
        y = ((a-b)/(a+b))*((a+b)/(a*a-a*b+b*2));
    } else {
        y = a + log2(b*b);
    }

    if (y == b) {
        t = (2*y + sqrt(y*y - a));
    } else if (y < b) {
        t = pow(sin(y), 2) + 1/tan(a-b);
    } else {
        t = pow(y*sin(a), 1./3) + 1/(sqrt(y*cos(b)));
    }

    printf("a: %lg\nb: %lg\ny: %lg\nt: %lg\n", a, b, y, t);

    return 0;
}
