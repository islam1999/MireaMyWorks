#include "MatrixGui.h"

MatrixGui::MatrixGui(QWidget *parent) : QWidget(parent) {
    validator = new QDoubleValidator();
    cellsLayout = new QGridLayout();
    matrix = new Matrix<double>();

    cells.resize(defCellsRes);

    for (int i = 0; i < defCellsRes; ++i) {
        for (int j = 0; j < defCellsRes; ++j) {
            auto *lineEdit = new QLineEdit();
            lineEdit->setValidator(validator);


            cells[i].push_back(lineEdit);
            cellsLayout->addWidget(cells.at(i).at(j), i, j);
        }
    }

    this->setLayout(cellsLayout);
}

MatrixGui::~MatrixGui() {
    delete validator;
    delete cellsLayout;
    delete matrix;
    for (auto &qVec : cells)
        qDeleteAll(qVec);
}

MatrixGui *MatrixGui::operator+(MatrixGui &gui) {
    auto *mtx = new Matrix<double>();
    *mtx = *(this->matrix) + *(gui.matrix);
    return new MatrixGui(mtx);
}

MatrixGui *MatrixGui::operator-(MatrixGui &gui) {
    auto *mtx = new Matrix<double>();
    *mtx = *(this->matrix) - *(gui.matrix);
    return new MatrixGui(mtx);
}

MatrixGui *MatrixGui::operator*(MatrixGui &gui) {
    auto *mtx = new Matrix<double>();
    *mtx = *(this->matrix) * *(gui.matrix);
    return new MatrixGui(mtx);
}

istream &operator>>(istream &is, MatrixGui &gui) {
    is >> *(gui.matrix);
    return is;
}

ostream &operator<<(ostream &os, const MatrixGui &gui) {
    os << *(gui.matrix);
    return os;
}

