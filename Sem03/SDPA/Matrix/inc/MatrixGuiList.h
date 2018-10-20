#ifndef MATRIX_MATRIXGUILIST_H
#define MATRIX_MATRIXGUILIST_H

#include <QStack>
#include <QHBoxLayout>
#include <QScrollArea>
#include <QtWidgets/QPushButton>
#include <QLabel>
#include "MatrixGui.h"

class MatrixGuiList : public QWidget {
Q_OBJECT

public:
    explicit MatrixGuiList(QWidget *parent = 0);

    ~MatrixGuiList();

public slots:

private:
    std::array<MatrixGui *, 3> array;
    QHBoxLayout *boxLayout;
    QScrollArea *scrollArea;
};


#endif //MATRIX_MATRIXGUILIST_H
