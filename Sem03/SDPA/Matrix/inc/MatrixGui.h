#ifndef MATRIX_MATRIXGUI_H
#define MATRIX_MATRIXGUI_H

#include <QDoubleValidator>
#include <QGridLayout>
#include <QLineEdit>
#include <QWidget>
#include "Matrix.h"

template<typename T>
class MatrixGui : public QWidget {

public:

    explicit MatrixGui() {
        createUI();
    }


    MatrixGui(const Matrix<T> &mtx, QWidget *parent = nullptr) : QWidget(parent), _matrix(mtx) {
        createUI();
    }

    ~MatrixGui() override {
        delete validator;
        delete cellsLayout;
        for (auto &qVec : _cells)
            qDeleteAll(qVec);
    }

    const Matrix<T> &matrix() {
        return _matrix;
    }

    int rows() const {
        return _cells.size();
    }

    int columns() const {
        return _cells[0].size();
    }

    void setMatrix(const Matrix<T> &mtx) {
        _matrix = mtx;
    }

    void updateFromGui() {
        _matrix.resize(rows(), columns());
        for (int i = 0; i < rows(); ++i) {
            for (int j = 0; j < columns(); ++j) {
                double value = _cells[i][j]->text().toDouble();
                _matrix.setValue(i, j, value);
            }
        }
    }

    void updateGui() {
        while (QLayoutItem *item = cellsLayout->takeAt(0)) {
            delete item->widget();
            delete item;
        }

        _cells.resize(_matrix.rows());
        for (int i = 0; i < rows(); ++i) {
            _cells[i].resize(_matrix.columns());
            for (int j = 0; j < columns(); ++j) {
                _cells[i][j] = new QLineEdit(QString::number(_matrix.value(i, j)));
                cellsLayout->addWidget(_cells[i][j], i, j);
            }
        }
    }

    Matrix<T> &operator+=(const Matrix<T> &mt) {
        return *this = matrix() + mt;
    }

    MatrixGui<T> &operator-=(const MatrixGui<T> &mtx) {
        *this = matrix() - mtx;
    }

    MatrixGui<T> &operator*=(const MatrixGui<T> &mtx) {
        return *this = matrix() * mtx;
    }

    friend MatrixGui<T> operator+(const MatrixGui<T> &left, const MatrixGui<T> &right) {
        return MatrixGui<T>(left.matrix() + right.matrix());
    }

    friend MatrixGui<T> operator-(const MatrixGui<T> &left, const MatrixGui<T> &right) {
        return MatrixGui<T>(left.matrix() - right.matrix());
    }

    friend MatrixGui<T> operator*(const MatrixGui<T> &left, const MatrixGui<T> &right) {
        return MatrixGui<T>(left.matrix() * right.matrix());
    }

    friend std::istream &operator>>(std::istream &is, MatrixGui<T> &mtx) {
        is >> mtx.matrix();
        return is;
    }

    friend std::ostream &operator<<(std::ostream &os, const MatrixGui<T> &mtx) {
        os << mtx.matrix();
        return os;
    }

private:
    void createUI() {
        cellsLayout = new QGridLayout;
        validator = new QDoubleValidator;
        _cells.resize(_matrix.rows());
        for (int i = 0; i < _cells.size(); ++i) {
            _cells[i].resize(_matrix.columns());
            for (int j = 0; j < _cells[i].size(); ++j) {
                auto *lineEdit = new QLineEdit(QString::number(_matrix.value(i, j)));
                lineEdit->setValidator(validator);

                _cells[i][j] = lineEdit;
                cellsLayout->addWidget(_cells.at(i).at(j), i, j);
            }
        }
        setLayout(cellsLayout);
    }

    Matrix<T> _matrix;
    QGridLayout *cellsLayout;
    QVector<QVector<QLineEdit *>> _cells;
    QDoubleValidator *validator;
};


#endif //MATRIX_MATRIXGUI_H
