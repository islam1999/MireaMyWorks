/*
 * 1. Напишите программу–калькулятор комплексных чисел.
 * Для реализации необходимо разработать абстрактный тип данных– комплексное число.
 * Программа должна реализовывать арифметические операции над комплексными числами.
 * Программа должна быть представлена в виде многофайлового проекта, все прототипы функций, объявления структур должны быть вынесены в заголовочный файл с соответствующим названием.
 * Всего должно быть три файла: файл с объявлениями, файл реализации и файл с функцией main(), демонстрирующий работу с новым типом данных.
 * Файл с объявлениями должен называться Complex.h, файл с реализацией функций должен называться Complex.с, файл с функцией main() может называться main.с
 * Программа должна обеспечивать удобный интерфейс пользователя для работы с ней
 *
 * 2. На основе разработанного в предыдущем задании типа данных комплексное число написать программу,
 * которая считывает информацию из файла complex.txt — количество комплексных чисел в переменную n, а сами комплексные числа в массив p.
 * Затем происходит поиск комплексного числа с максимальным модулем в массиве p.
 */

#include <stdio.h>
#include <malloc.h>
#include "Complex.h"

int main(int argc, const char *argv[]) {
    FILE *input_file = stdin;
    if (argc == 1) {
        printf("=>Input your complexes. Example: (2+3i)/(-1-25i) or (2 - 2i) + (2 - 2i)\n");
        return calculate((FILE *) &input_file);
    }

    if ((input_file = fopen(argv[1], "r")) == NULL) {
        printf("=>>[ERROR] Cant open file %s\n", argv[1]);
        return -1;
    }

    printf("=>>[SUCCESS] File %s is opened!\n", argv[1]);
    printf("=>Count start:\n");

    int size = 10;
    Complex *array = (Complex *) malloc(sizeof(Complex) * size);
    int n = 0;

    while (read(input_file, array + n) != -1) {
        if (n - 1 >= size)
            array = realloc(array, sizeof(Complex) * size * 2);

        printf("%d: ", n);
        print_complex(array + n);
        n++;
        fscanf(input_file, " ");
    }
    printf("=>Count finished: %d\n", n);

    double max = abs_complex(&array[0]);
    Complex max_comp = array[0];
    for (int i = 1; i < n; ++i) {
        if(max < abs_complex(&array[i])){
            max = abs_complex(&array[i]);
            max_comp = array[i];
        }
    }
    printf("Max: |%lf|\n", max);
    print_complex(&max_comp);

    free(array);
    fclose(input_file);
    return 0;
}

