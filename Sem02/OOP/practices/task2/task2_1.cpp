#include <stdio.h>
#include <cmath>

using namespace std;

int main() {
    double a = 4.8, b = -7.9, n, m;

    if (a >= b) {
        n = pow(a-b, 1./3);
    } else {
        n = a*a + (a-b)/sin(a*b);
    }

    if (n < b) {
        m = (n+a)/-b + sqrt(pow(sin(a), 2) - cos(n));
    } else if (n == b) {
        m = b*b + tan(n*a);
    } else {
        m = pow(b, 3) + n*a*a;
    }

    printf("a: %lg\nb: %lg\nn: %lg\nm: %lg\n", a, b, n, m);

    return 0;
}
