#ifndef MATRIX_MATRIXGUILIST_H
#define MATRIX_MATRIXGUILIST_H

#include <QHBoxLayout>
#include <QPushButton>
#include <QComboBox>
#include <QLabel>
#include <fstream>
#include "MatrixGui.h"

class MatrixGuiList : public QWidget {
Q_OBJECT

public:
    explicit MatrixGuiList(QWidget *parent = nullptr);

    ~MatrixGuiList() override;

    QVector<MatrixGui<double> *> matrices;

public slots:

    void calculateResult();

private:
    void createUI();

    QHBoxLayout *boxLayout;
    QComboBox *comboBox;
    std::fstream file;
};


#endif //MATRIX_MATRIXGUILIST_H
