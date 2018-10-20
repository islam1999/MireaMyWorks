/*
 * Постановка задачи. Дана целочисленная матрица из n строк и m столбцов
 * (1<n<=100, 1<m<=50). Выполнить заданную операцию над матрицей. 11 Сортировка
 * столбцов По неубыванию последних элементов столбцов
 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int rows = 0;
    int columns = 0;

    cout << "Input: rows columns\n";
    cin >> rows >> columns;

    if (!(rows > 1 && rows <= 100 && columns > 1 && columns <= 50)) {
        cout << "Uncorrect input! Correct: 1 < rows <= 100, 1 < columns <= 50" << endl;
        return 2;
    }

    vector<vector<double>> matrix(columns);
    for (int i = 0; i < columns; ++i) {
        matrix.at(i).resize(rows);
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            cin >> matrix[j][i];
        }
    }
    cout << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            cout << matrix[j][i] << " ";
        }
        cout << endl;
    }
    cout << "Result:" << endl;

    for (int i = columns - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            if (matrix.at(j).at(rows - 1) >= matrix.at(j + 1).at(rows - 1))
                swap(matrix[j], matrix[j + 1]);
        }
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            cout << matrix[j][i] << " ";
        }
        cout << endl;
    }
    return 0;
}
