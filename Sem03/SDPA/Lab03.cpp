/*
 * Постановка задачи. Дана целочисленная матрица из n строк и m столбцов (1<n<=100, 1<m<=50). Выполнить заданную операцию над матрицей.
 * 11 Сортировка столбцов По неубыванию последних элементов столбцов
 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    ulong rows = 0;
    ulong columns = 0;

    cout<<"Input: rows columns\n";
    cin >> rows >> columns;

    vector< vector<double> > matrix(columns);
    for (ulong i = 0; i < columns; ++i) {
        matrix.at(i).resize(rows);
    }

    for (ulong i = 0; i < rows; ++i) {
        for (ulong j = 0; j < columns; ++j) {
            cin >> matrix[j][i];
        }
    }

    for (ulong i = 0; i < rows; ++i) {
        for (ulong j = 0; j < columns; ++j) {
            cout << matrix[j][i] << " ";
        }
        cout<<endl;
    }
    cout<<"------------------------"<<endl;

    for (ulong i = 0; i < columns-1; ++i) {
        bool c =  matrix.at(i).at(rows-1) >=  matrix.at(i+1).at(rows-1);
        if(c)
            swap(matrix[i], matrix[i+1]);
    }

    for (ulong i = 0; i < rows; ++i) {
        for (ulong j = 0; j < columns; ++j) {
            cout << matrix[j][i] << " ";
        }
        cout<<endl;
    }
    return 0;
}


