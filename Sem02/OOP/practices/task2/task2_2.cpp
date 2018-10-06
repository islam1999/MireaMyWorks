#include <stdio.h>
#include <cmath>

using namespace std;

int main() {
    double a = -0.6, b = 5.3, z, t;

    if (a < b) {
        z = sqrt(a*a - b*b);
    } else {
        z = 1 - 2*cos(a)*sin(b);
    }

    if (z < b) {
        t = pow(z  +a*a*b, 1./3);
    } else if (z == b) {
        t = 1 - log10(z) + cos(a*a*b);
    } else {
        t = 1/(cos(z*a));
    }

    printf("a: %lg\nb: %lg\nz: %lg\nt: %lg\n", a, b, z, t);

    return 0;
}
