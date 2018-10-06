#include <iostream>

using namespace std;

void process(int *array, size_t size) {
    for (size_t i = 0; i < size/2; i++) {
        int tmp = array[i*2];
        array[i*2] = array[i*2+1];
        array[i*2] = tmp;
    }
}

void fill_array(int *array, size_t size) {
    for (size_t i = 0; i < size; i++) {
        cin >> array[i];
    }
}

void print_array(int *array, size_t size) {
    for (size_t i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
}

int main() {
    int *array = new int[12];

    cout << "Fill array for 12 elements: ";
    fill_array(array, 12);
    cout << "Array: ";
    process(array, 12);
    cout << "Array: ";
    print_array(array, 12);

    delete[] array;

    return 0;
}
