#ifndef MATRIX_MATRIXGUI_H
#define MATRIX_MATRIXGUI_H

#include <QWidget>
#include <QGridLayout>
#include <QLineEdit>
#include <QDoubleValidator>
#include <QVector>
#include <QtAlgorithms>
#include "Matrix.h"

class MatrixGui : public QWidget {
    Q_OBJECT

public:
    explicit MatrixGui(QWidget * parent = 0 );

    ~MatrixGui();

private:
    QVector <QVector<QLineEdit *>> cells;
    QGridLayout cellsLayout;
    QDoubleValidator* validator;
    int defCellsRes = 3;
};


#endif //MATRIX_MATRIXGUI_H
