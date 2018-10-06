#include <iostream>
#include <algorithm>

using namespace std;

double *create_array(size_t size) {
    return new double[size];
}

void fill_array(double *array, size_t size) {
    for (size_t i = 0; i < size; i++) {
        cin >> array[i];
    }
}

void print_array(double *array, size_t size) {
    for (size_t i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
}

void free_array(double *array) {
    delete[] array;
}

int main() {
    double *array;
    size_t size;

    while (true) {
        cout << "Enter array size: ";
        cin >> size;

        array = create_array(size);
        cout << "Fill array for " << size << " elements: ";
        fill_array(array, size);
        cout << "Array:";
        print_array(array, size);
        free_array(array);


        cout << "continue?[Y/n] ";
        string next;
        cin >> next;
        transform(next.begin(), next.end(), next.begin(), ::tolower);
        if (next == "y") {
            continue;
        }

        break;
    }

    return 0;
}
