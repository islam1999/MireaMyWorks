#include <stdio.h>
#include <ctype.h>


/* Данная программа сделана криво и костыльно умышленно из-за своей дальнейшей бесполезности и лени ее создателя */
double CtoF(double n){
    n *= 1.8;
    n += 32;
    return n;
}

double CtoK(double n){
    n += 273.15;
    return n;
}

double FtoC(double n){
    n -= 32;
    n *= 5.0/9.0;
    return n;
}

double KtoC(double n) {
    n -= 273.15;
    return n;
}

void TempChecker(double temp, char s){
    if (  (s=='C'&& temp<=-273.15)||(s=='K' && temp<=0)||(s=='F' && temp<=-459.67)  )
        printf("WARNING: Current temperature <= absolute zero! \n");
}


int TemperatureConverter (int argc, char* argv[]) {
    double temp;
    char s = '0';

    if(argc <= 1 || argc > 3)
        return -1;

    if(sscanf(argv[1], "%lf", &temp) == 1)
        if (argc == 3)
            s = argv[2][0];

    s = (char) toupper(s);
    TempChecker(temp, s);
    switch (s) {
        case 'C': {
            double tmp = CtoF(temp);
            printf("%.2lf F\n", tmp);
            temp = CtoK(temp);
            printf("%.2lf K\n", temp);
            break;
        }
        case 'F': {
            temp = FtoC(temp);
            printf("%.2lf C\n", temp);
            temp = CtoK(temp);
            printf("%.2lf K\n", temp);
            break;
        }
        case 'K': {
            temp = KtoC(temp);
            printf("%.2lf C\n", temp);
            temp = CtoF(temp);
            printf("%.2lf F\n", temp);
            break;
        }
        default: {
            s = 'C';
            TempChecker(temp, s);
            printf("%.2lf C\n", temp);
            double tmp = CtoF(temp);
            printf("%.2lf F\n", tmp);
            temp = CtoK(temp);
            printf("%.2lf K\n", temp);

            return 0;
        }
    }
    return 0;
}
