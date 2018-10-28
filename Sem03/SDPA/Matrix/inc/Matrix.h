#ifndef MATRIX_MATRIX_H
#define MATRIX_MATRIX_H

#include <QVector>
#include <QDebug>
#include <iostream>


template<typename T>
class Matrix {

public:

    Matrix<T>(QVector<QVector<T>> mtx) : _matrix{mtx} {}

    explicit Matrix<T>(int rows = 3, int columns = 3, T value = 0) {
        _matrix.resize(rows);
        for (QVector<T> &column : _matrix) {
            column.fill(value, columns);
        }
    }

    int rows() const {
        return _matrix.size();
    }

    int columns() const {
        return _matrix.at(0).size();
    }

    void resize(int rows, int columns) {
        _matrix.resize(rows);
        qDebug() << "Rows: " << _matrix.size();
        for (auto &column : _matrix) {
            column.resize(columns);
            qDebug() << "  Column " << column.size();
        }

    }

    void setValue(int row, int column, T value) {
        if (row >= rows() || column >= columns()) {
            throw std::runtime_error("Index out of matrix");
        }
        _matrix[row][column] = value;
    }

    T value(int row, int column) const {
        return _matrix.at(row).at(column);
    }

    bool is_equal_dimension(const Matrix<T> &mtx) const {
        return (rows() == mtx.rows() && columns() == mtx.columns());
    }

    template<typename D>
    Matrix<T> &operator*=(const D digit) {
        *this = *this * digit;
        return *this;
    }

    template<typename D>
    friend Matrix<T> operator*(const Matrix<T> &mtx, D digit) {
        Matrix<T> matrix(mtx.rows(), mtx.columns());
        for (int i = 0; i < mtx.rows(); ++i) {
            for (int j = 0; j < mtx.columns(); ++j) {
                matrix._matrix[i][j] = mtx._matrix[i][j] * digit;
            }
        }
        return mtx;
    }

    friend Matrix<T> operator+(const Matrix<T> &left, const Matrix<T> &right) {
        if (!left.is_equal_dimension(right)) {
            throw std::runtime_error("Dimension of the first _matrix should be equal to dimension of the second");
        }
        Matrix<T> mtx(left.rows(), left.columns());

        for (int i = 0; i < mtx.rows(); ++i) {
            for (int j = 0; j < mtx.columns(); ++j) {
                mtx._matrix[i][j] = left._matrix[i][j] + right._matrix[i][j];
            }
        }
        return mtx;
    }

    friend Matrix<T> operator-(const Matrix<T> &left, const Matrix<T> &right) {
        if (!left.is_equal_dimension(right)) {
            throw std::runtime_error("Dimension of the first _matrix should be equal to dimension of the second");
        }

        Matrix<T> mtx(left.rows(), left.columns());

        for (int i = 0; i < mtx.rows(); ++i) {
            for (int j = 0; j < mtx.columns(); ++j) {
                mtx._matrix[i][j] = left._matrix[i][j] - right._matrix[i][j];
            }
        }
        return mtx;
    }

    friend Matrix<T> operator*(const Matrix<T> &left, const Matrix<T> &right) {
        if (left.columns() != right.rows()) {
            throw std::runtime_error(
                    "The number of columns of the first _matrix should be equal to the number of rows of the second");
        }

        Matrix<T> mtx(left.rows(), right.columns());
        for (int i = 0; i < right.rows(); ++i) {
            for (int j = 0; j < right.columns(); ++j) {
                for (int m = 0; m < right.rows(); ++m) {
                    mtx._matrix[i][j] += left._matrix[i][m] * right._matrix[m][j];
                }
            }
        }
        return mtx;
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

    friend std::istream &operator>>(std::istream &is, Matrix<T> &mt) {
        int rows = 0;
        int columns = 0;

        is >> rows >> columns;

        mt._matrix.clear();
        mt._matrix.resize(rows);


        for (int i = 0; i < rows; ++i) {
            mt._matrix[i].resize(columns);
        }

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                is >> mt._matrix[i][j];
            }
        }
        is.get();
        return is;
    }

    friend std::ostream &operator<<(std::ostream &os, const Matrix<T> &mt) {
        os << mt.rows() << " " << mt.columns() << std::endl;

        for (ulong i = 0; i < mt.rows(); ++i) {
            for (ulong j = 0; j < mt.columns(); ++j) {
                os << mt._matrix[i][j] << " ";
            }
            os << std::endl;
        }
        os << std::endl;
        return os;
    }


private:
    QVector<QVector<T>> _matrix;
};


#endif //MATRIX_MATRIX_H
