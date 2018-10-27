
#include <MatrixGuiList.h>

MatrixGuiList::MatrixGuiList(QWidget *parent) : QWidget(parent) {
    file.open("data.csv");

    for (int i = 0; i < 2; ++i) {
        Matrix<double> mtx;
        file >> mtx;
        auto *matrixGui = new MatrixGui<double>(mtx);
        matrices.push_back(matrixGui);
    }
    matrices.push_back(new MatrixGui<double>);
    file.close();
    createUI();
}

MatrixGuiList::~MatrixGuiList() {
    file.open("data.csv");
    file << matrices[0]->matrix() << matrices[1]->matrix();
    file.close();
    delete boxLayout;
}

void MatrixGuiList::createUI() {
    boxLayout = new QHBoxLayout();
    QStringList operations = {"+", "-", "*", "=="};
    comboBox = new QComboBox();
    comboBox->addItems(operations);
    for (int i = 0; i < matrices.size() - 1; ++i) {
        boxLayout->addWidget(matrices[i]);
        if (i == 0)
            boxLayout->addWidget(comboBox);
    }
    auto *result_button = new QPushButton("=");
    connect(result_button, SIGNAL(clicked()), this, SLOT(calculateResult()));
    boxLayout->addWidget(result_button);
    boxLayout->addWidget(matrices.last());
    setLayout(boxLayout);
}

void MatrixGuiList::calculateResult() {
    matrices[0]->updateFromGui();
    matrices[1]->updateFromGui();

    QString choice = comboBox->currentText();
    Matrix<double> mtx;
    if (choice == "+") {
        mtx = matrices[0]->matrix() + matrices[1]->matrix();
    } else if (choice == "-") {
        mtx = matrices[0]->matrix() - matrices[1]->matrix();
    } else if (choice == "*") {
        if (matrices[1]->matrix().columns() == 1 && matrices[1]->matrix().rows() == 1) {
            mtx = matrices[0]->matrix() * matrices[1]->matrix().value(0, 0);
        }
        mtx = matrices[0]->matrix() * matrices[1]->matrix();
    } else if (choice == "==") {
        bool equal = matrices[0]->matrix() == matrices[1]->matrix();
        mtx = equal ? Matrix<double>(1, 1, 1) : Matrix<double>(1, 1, 0);
    }
    matrices[2]->setMatrix(mtx);
    matrices[2]->updateGui();
}
