#include "MatrixGui.h"

MatrixGui::MatrixGui(QWidget *parent) : QWidget(parent) {
    cells.resize(defCellsRes);
    validator = new QDoubleValidator();

    for (int i = 0; i < defCellsRes; ++i) {
        for (int j = 0; j < defCellsRes; ++j) {
            auto *lineEdit = new QLineEdit();
            lineEdit->setValidator(validator);


            cells[i].push_back(lineEdit);
            cellsLayout.addWidget(cells.at(i).at(j), i, j);
        }
    }


    setLayout(&cellsLayout);
}

MatrixGui::~MatrixGui() {
    delete validator;

    for (auto &qVec : cells)
        qDeleteAll(qVec);
}