#ifndef MATRIX_MATRIXGUI_H
#define MATRIX_MATRIXGUI_H

#include <QDoubleValidator>
#include <QtAlgorithms>
#include <QGridLayout>
#include <QLineEdit>
#include <QWidget>
#include "Matrix.h"

class MatrixGui : public QWidget {
Q_OBJECT

public:
    explicit MatrixGui(QWidget *parent = 0);

    MatrixGui(Matrix<double> *mtx, QWidget *parent = 0) : QWidget(parent), matrix(mtx) {}

    ~MatrixGui();

    MatrixGui *operator+(MatrixGui &gui);

    MatrixGui *operator-(MatrixGui &gui);

    MatrixGui *operator*(MatrixGui &gui);

    friend istream &operator>>(istream &is, MatrixGui &gui);

    friend ostream &operator<<(ostream &os, const MatrixGui &gui);

private:
    QVector<QVector<QLineEdit *>> cells;
    QGridLayout *cellsLayout;
    QDoubleValidator *validator;
    Matrix<double> *matrix;
    u_int defCellsRes = 3;
};


#endif //MATRIX_MATRIXGUI_H
