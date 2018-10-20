/*
 * Постановка задачи. Разработать программу, выполняющую операции над
 * целочисленным динамическим массивом из n элементов (n<=100):
 * ввод массива;
 * вывод массива на экран;
 * дополнительные операции.
 * Алгоритмы выполнения операций оформить в виде функций. В алгоритмах
 * выполнения операций добавления и удаления элементов предусмотреть проверку
 * возможности выполнения операций. Программа должна выводить текстовое меню для
 * тестирования операций. 11 Поиск номера первого максимального элемента
 * Добавление перед каждым нулевым числом числа х
 */

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int input_array(istream &stream, vector<long> &array) {
    ulong size = 0;
    stream >> size;
    if (size > 100)
        return 1;
    array.clear();
    array.resize(size);
    for (ulong i = 0; i < size; ++i) {
        stream >> array[i];
    }
    return 0;
}

void print_array(ostream &stream, vector<long> &array) {
    for (long i : array) {
        stream << i << " ";
    }
}

long search_max(vector<long> &array) {
    if (array.empty())
        return -1;

    auto max = max_element(array.begin(), array.end());
    return distance(array.begin(), max);
}

void add_x(vector<long> &array, long x) {
    for (ulong i = 1; i < array.size(); ++i) {
        if (array.at(i) == 0)
            array[i - 1] = x;
    }
}

int main() {
    vector<long> array;
    long x = 0;
    char input = '0';

    while (input != 'e') {
        cout << "\nChoice:\n"
                "input array - 'i'\n"
                "print array - 'p'\n"
                "search max  - 's'\n"
                "add x per 0 - 'x'\n";
        cin >> input;
        input = static_cast<char>(tolower(input));
        switch (input) {
        case 'i':
            cout << "Input size, elements..." << endl;
            if (input_array(cin, array))
                cout << "Size must be <=100!" << endl;
            break;
        case 'p':
            print_array(cout, array);
            break;
        case 's':
            cout << "Max element index: " << search_max(array) << endl;
            break;
        case 'x':
            cout << "Input X: ";
            cin >> x;
            add_x(array, x);
            break;
        default:
            cout << "Something went wrong, call fixies!" << endl;
            break;
        }
    }
    return 0;
}