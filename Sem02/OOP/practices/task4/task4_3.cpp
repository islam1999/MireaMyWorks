#include <random>
#include <iostream>

using namespace std;

int **create_matrix(size_t rows_num, size_t cols_num) {
    int **matrix = new int*[rows_num];
    for (size_t i = 0; i < rows_num; i++) {
        matrix[i] = new int[cols_num];
    }
    return matrix;
}

void free_matrix(int **matrix, size_t rows_num) {
    for (size_t i = 0; i < rows_num; i++) {
        delete[] matrix[i];
    }

    delete[] matrix;
}

void fill_matrix(int **matrix, size_t rows_num, size_t cols_num) {
    random_device rd;
    mt19937 gen(rd());

    for (size_t i = 0; i < rows_num; i++) {
        for (size_t j = 0; j < cols_num; j++) {
            matrix[i][j] = gen() % 1500 - 750;
        }
    }
}

void print_matrix(int **matrix, size_t rows_num, size_t cols_num) {
    for (size_t i = 0; i < rows_num; i++) {
        for (size_t j = 0; j < cols_num; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int rows, cols;
    cout << "Enter rows and cols: ";
    cin >> rows >> cols;
    int **matrix = create_matrix(rows, cols);
    fill_matrix(matrix, rows, cols);
    print_matrix(matrix, rows, cols);
    free_matrix(matrix, rows);

    return 0;
}
