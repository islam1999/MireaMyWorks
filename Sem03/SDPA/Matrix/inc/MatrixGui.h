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

    explicit MatrixGui(QWidget *parent = nullptr) : QWidget(parent) {
        createUI();
    }


    explicit MatrixGui(const Matrix<double> &mtx, QWidget *parent = nullptr) : QWidget(parent), _matrix(mtx) {
        createUI();
    }

    ~MatrixGui() override {
        delete _validator;
        delete _layout;
        for (auto &qVec : _cells)
            qDeleteAll(qVec);
    }

    const Matrix<double> &matrix() const {
        return _matrix;
    }

    int rows() const {
        return _cells.size();
    }

    int columns() const {
        return _cells[0].size();
    }

    void setMatrix(const Matrix<double> &mtx) {
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

public slots:

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

    void increaseRow() {
        updateFromGui();
        if (rows() > _maxSize)
            return;
        _matrix.resize(rows() + 1, columns());
        updateGui();
    }

    void increaseColumn() {
        updateFromGui();
        if (columns() > _maxSize)
            return;
        _matrix.resize(rows(), columns() + 1);
        updateGui();
    }

    void decreaseRow() {
        updateFromGui();
        if (rows() == 1)
            return;
        _matrix.resize(rows() - 1, columns());
        updateGui();
    }

    void decreaseColumn() {
        updateFromGui();
        if (columns() == 1)
            return;
        _matrix.resize(rows(), columns() - 1);
        updateGui();
    }

private:
    void createUI() {
        cellsLayout = new QGridLayout;
        _layout = new QVBoxLayout();
        _buttonsLayout = new QGridLayout();

        _increaseRow = new QPushButton("Row +");
        _increaseColumn = new QPushButton("Column +");
        _decreaseRow = new QPushButton("Row -");
        _decreaseColumn = new QPushButton("Column -");

        connect(_increaseRow, SIGNAL(clicked()), this, SLOT(increaseRow()));
        connect(_increaseColumn, SIGNAL(clicked()), this, SLOT(increaseColumn()));
        connect(_decreaseRow, SIGNAL(clicked()), this, SLOT(decreaseRow()));
        connect(_decreaseColumn, SIGNAL(clicked()), this, SLOT(decreaseColumn()));

        _validator = new QDoubleValidator;
        _cells.resize(_matrix.rows());
        for (int i = 0; i < _cells.size(); ++i) {
            _cells[i].resize(_matrix.columns());
            for (int j = 0; j < _cells[i].size(); ++j) {
                auto *lineEdit = new QLineEdit(QString::number(_matrix.value(i, j)));
                lineEdit->setValidator(_validator);

                _cells[i][j] = lineEdit;
                cellsLayout->addWidget(_cells.at(i).at(j), i, j);
            }
        }
        _buttonsLayout->addWidget(_increaseRow, 0, 0);
        _buttonsLayout->addWidget(_increaseColumn, 0, 1);
        _buttonsLayout->addWidget(_decreaseRow, 1, 0);
        _buttonsLayout->addWidget(_decreaseColumn, 1, 1);

        _layout->addLayout(cellsLayout);
        _layout->addLayout(_buttonsLayout);
        setLayout(_layout);
    }

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
