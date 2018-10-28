#ifndef MATRIX_MATRIXGUI_H
#define MATRIX_MATRIXGUI_H

#include <QDoubleValidator>
#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>
#include "Matrix.h"

class MatrixGui : public QWidget {
Q_OBJECT
public:

    explicit MatrixGui(QWidget *parent = nullptr);

    explicit MatrixGui(const Matrix<double> &mtx, QWidget *parent = nullptr);

    ~MatrixGui() override;

    int rows() const;

    int columns() const;

    void setMatrix(const Matrix<double> &mtx);

    const Matrix<double> &matrix() const;

    void updateGui();

    void updateFromGui();

public slots:

    void increaseRow();

    void increaseColumn();

    void decreaseRow();

    void decreaseColumn();

private:
    void createUI();

    QGridLayout *cellsLayout;
    QVBoxLayout *_layout;
    QGridLayout *_buttonsLayout;
    QDoubleValidator *_validator;
    QPushButton *_increaseRow;
    QPushButton *_decreaseRow;
    QPushButton *_decreaseColumn;
    QPushButton *_increaseColumn;
    QVector<QVector<QLineEdit *>> _cells;
    Matrix<double> _matrix;
    static constexpr int _maxSize = 9;
};


#endif //MATRIX_MATRIXGUI_H
