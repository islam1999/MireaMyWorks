/*
 * Постановка задачи. Создать шаблоны функций, выполняющих ввод, вывод и упорядочивание матрицы.
 * Протестировать шаблоны для матриц с элементами различных типов: int, float и char.
 * 11 Упорядочить каждый столбец по возрастанию элементов
 */

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

template<typename T>
void input_matrix(istream &s, vector<vector<T>> &mt) {
    ulong rows = 0;
    ulong columns = 0;

    s >> rows >> columns;
    mt.clear();
    mt.resize(columns);
    for (ulong i = 0; i < columns; ++i) {
        mt.at(i).resize(rows);
    }

    for (ulong i = 0; i < rows; ++i) {
        for (ulong j = 0; j < columns; ++j) {
            s >> mt[j][i];
        }
    }

}

template<typename T>
void print_matrix(ostream &s, vector<vector<T>> &mt) {
    ulong rows = mt.at(0).size();
    ulong columns = mt.size();

    for (ulong i = 0; i < rows; ++i) {
        for (ulong j = 0; j < columns; ++j) {
            s << mt[j][i] << " ";
        }
        s << endl;
    }

}

template<typename T>
void sort_matrix(vector<vector<T>> &mt) {
    ulong rows = mt.at(0).size();
    ulong columns = mt.size();

    for (ulong i = 0; i < rows; ++i) {
        for (ulong j = 0; j < columns; ++j) {
            for (ulong k = i + 1; k < columns; ++k) {
                if (mt[i][j] > mt[k][j])
                    swap(mt[i][j], mt[k][j]);
            }
        }
    }

}

int main() {
    cout << "Matrix Int:\n";
    vector<vector<int>> matrix_int = {
            {2,  4, 5},
            {1,  5, 10},
            {22, 4, 0}
    };
    sort_matrix(matrix_int);
    print_matrix(cout, matrix_int);

    cout << "\nMatrix Float:\n";
    vector<vector<float>> matrix_float = {
            {2.2,   4.5, 54.1},
            {1.44,  5.5, 101.54},
            {22.98, 4.0, 0.44}
    };
    sort_matrix(matrix_float);
    print_matrix(cout, matrix_float);

    cout << "\nMatrix Char:\n";
    vector<vector<char>> matrix_char;
    cout << "Input: rows columns\n";
    input_matrix(cin, matrix_char);
    print_matrix(cout, matrix_char);
    sort_matrix(matrix_char);
    cout << endl;
    print_matrix(cout, matrix_char);
    return 0;
}

