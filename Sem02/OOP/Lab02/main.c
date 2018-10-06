/*
 * 1. Напишите программу, которая вызывает различные виды
 * функции в зависимости от заданного условия. Можно
 * использовать примеры выше.
 * 2. Напишите программу с использованием некой универсальной
 * функции, которая в качестве возвращаемого значения
 * возвращает указатель на функцию. Эта функция в зависимости
 * от исходного массива должна соответствующим образом
 * преобразовать массив. Также в функции main() должен быть
 * объявлен указатель. В теле программы указателю на функцию
 * должно присваиваться значение.
 * Исходные данные - сгенерировать целочисленный массив из случайных чисел.
 * Запрограммировать следующие действия в виде функций:
 *      • если сумма элементов в массиве равна его первому
 * элементу, то необходимо инвертировать массив
 *      • если сумма элементов в массиве больше его первого
 * элемента, то необходимо расположить его элементы в
 * неубывающем порядке
 *      • если сумма элементов массива меньше его первого
 * элемента, то необходимо расположить его элементы в
 * невозрастающем порядке
 */

#include <stdio.h>
#include <stdlib.h>

void f1(){
   printf("Hello, World!\n");
}
void f2(){
    printf("Goodbye, World!\n");
}

void reverse(int *a, int size) {
    int temp;
    for (int i = 0; i < size/2; ++i) {
        temp = a[size - i - 1];
        a[size - i - 1] = a[i];
        a[i] = temp;
    }
}
void Sort(int *a, int size) {
    int temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
void reverseSort(int *a, int size) {
    Sort(a, size);
    reverse(a, size);
}

int size = 8;
int *array;
void (*ptr_array)(int *, int);

void (*switcher())(int* a, int size) {
    int sum = 0;
    for (int i = 1; i < size; ++i) {
        sum += array[i];
    }
    if(sum == array[0])
        return reverse;
    else if(sum > array[0])
        return Sort;
    else return reverseSort;
}

int main() {
    //#1
    void (*ptr_f)();
    if (rand() % 10+1 > 5)
        ptr_f = f1;
    else ptr_f = f2;
    ptr_f();

    //#2
    array = (int *) malloc(sizeof(int)*size);
    for (int i = 0; i < size; ++i) {
        array[i] = rand() % 100 + 1;
        printf("%d ",array[i]);
    }
   printf("\n");

    ptr_array = switcher();
    ptr_array(array, size);

    for (int i = 0; i < size; ++i) {
        printf("%d ",array[i]);
    }

    free(array);
    return 0;
}
