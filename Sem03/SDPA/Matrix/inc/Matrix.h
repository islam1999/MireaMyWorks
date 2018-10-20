#ifndef MATRIX_MATRIX_H
#define MATRIX_MATRIX_H

#include <QVector>
#include <iostream>

using namespace std;


template<class T>
class Matrix : QObject {

public:

    Matrix<T>() {}

    Matrix<T>(const Matrix<T> &mt) : _matrix{mt._matrix} {}

    explicit Matrix<T>(const QVector<QVector<T>> &mt) {
        _matrix = mt;
    }

    Matrix<T>(int rows, int columns, T value = 0) {
        _matrix.clear();
        _matrix.resize(rows);
        for (auto &column : _matrix) {
            column.resize(columns);
            for (auto &elem : column) {
                elem = value;
            }
        }
    }

    int rows() const {
        return _matrix.size();
    }

    int columns() const {
        return _matrix.at(0).size();
    }

    bool is_equal_dimension(const Matrix<T> &mt) const {
        return (rows() == mt.rows() && columns() == mt.columns());
    }

    Matrix<T> operator+(const Matrix<T> &mt) {
        if (!is_equal_dimension(mt)) {
            throw std::runtime_error("Dimension of the first matrix should be equal to dimension of the second");

        }

        Matrix<T> new_mt{rows(), columns()};

        for (int i = 0; i < rows(); ++i) {
            for (int j = 0; j < columns(); ++j) {
                new_mt._matrix[i][j] = _matrix[i][j] + mt._matrix[i][j];
            }
        }
        return new_mt;
    }

    Matrix<T> operator-(const Matrix<T> &mt) {
        if (!is_equal_dimension(mt)) {
            throw std::runtime_error("Dimension of the first matrix should be equal to dimension of the second");
        }

        Matrix<T> new_mt{rows(), columns()};

        for (int i = 0; i < rows(); ++i) {
            for (int j = 0; j < columns(); ++j) {
                new_mt._matrix[i][j] = _matrix[i][j] - mt._matrix[i][j];
            }
        }
        return new_mt;
    }

    Matrix<T> operator*(const Matrix<T> &mt){
        if (columns() != mt.rows()) {
            throw std::runtime_error("The number of columns of the first matrix should be equal to the number of rows of the second");
        }

        Matrix<T> new_mt{rows(), mt.columns()};

        for (int i = 0; i < mt.rows(); ++i) {
            for (int j = 0; j < mt.columns(); ++j) {
                for (int m = 0; m < mt.rows(); ++m) {
                    new_mt._matrix[i][j] += _matrix[i][m] * mt._matrix[m][j];
                }
            }
        }
        return new_mt;
    }

    Matrix<T> &operator+=(const Matrix<T> &mt) {
        return *this = *this + mt;
    }

    Matrix<T> &operator-=(const Matrix<T> &mt) {
        *this = *this - mt;
    }

    Matrix<T> &operator*=(const Matrix<T> &mt) {
        return *this = *this * mt;
    }

    template<typename D>
    Matrix<T> &operator*=(const D digit) {
        for (auto &row : _matrix)
            for (auto &elem : row)
                elem *= digit;
        return *this;
    }

    bool operator==(const Matrix<T> &mt) const {
        if (!is_equal_dimension(mt)) {
            return false;
        }

        for (int i = 0; i < rows(); ++i) {
            for (int j = 0; j < columns(); ++j) {
                if (_matrix[i][j] != mt._matrix[i][j])
                    return false;
            }
        }
        return true;
    }

    Matrix &operator=(const Matrix &mt) {
        if (this == &mt) {
            return *this;
        }
        _matrix = mt._matrix;
        return *this;
    }

    friend istream &operator>>(istream &is, Matrix<T> &mt) {
        int rows = 0;
        int columns = 0;

        is >> rows >> columns;

        mt._matrix.clear();
        mt._matrix.resize(columns);

        for (int i = 0; i < columns; ++i) {
            mt._matrix[i].resize(rows);
        }

        for (ulong i = 0; i < rows; ++i) {
            for (ulong j = 0; j < columns; ++j) {
                is >> mt._matrix[i][j];
            }
        }
        is.get();
        is.get();
        return is;
    }

    friend ostream &operator<<(ostream &os, Matrix<T> &mt) {
        os << mt.rows() << " " << mt.columns() << endl;

        for (ulong i = 0; i < mt.rows(); ++i) {
            for (ulong j = 0; j < mt.columns(); ++j) {
                os << mt._matrix[i][j] << " ";
            }
            os << endl;
        }
        os << endl;
        return os;
    }


private:
    QVector<QVector<T>> _matrix;
};


#endif //MATRIX_MATRIX_H
