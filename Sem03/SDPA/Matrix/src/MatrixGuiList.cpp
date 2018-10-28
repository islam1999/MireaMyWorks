
#include <MatrixGuiList.h>

MatrixGuiList::MatrixGuiList(QWidget *parent) : QWidget(parent) {
    _matrices.resize(3);
    std::ifstream file(fileName);
    try {
        std::cout << "File reading start" << std::endl;
        for (int i = 0; i < 2; ++i) {
            Matrix<double> mtx;
            file >> mtx;
            if (!mtx.rows() || !mtx.columns()) {
                throw std::runtime_error("No integer!");
            }
            auto *matrixGui = new MatrixGui(mtx);
            _matrices[i] = matrixGui;
        }
        std::cout << "File reading end" << std::endl;
    } catch (...) {
        std::cout << "File reading error!" << std::endl;
        QMessageBox::warning(this, "Error", "Uncorrected data in file!", QMessageBox::Ok);

        for (int i = 0; i < 2; ++i) {
            _matrices[i] = new MatrixGui;
        }
    }
    file.close();
    _matrices[2] = new MatrixGui;
    createUI();
}

MatrixGuiList::~MatrixGuiList() {
    std::ofstream file(fileName);
    file << _matrices[0]->matrix() << _matrices[1]->matrix();
    file.close();
    delete boxLayout;
}

void MatrixGuiList::createUI() {
    boxLayout = new QHBoxLayout();
    QStringList operations = {"+", "-", "*", "=="};
    comboBox = new QComboBox();
    comboBox->addItems(operations);
    for (int i = 0; i < _matrices.size() - 1; ++i) {
        boxLayout->addWidget(_matrices[i]);
        if (i == 0)
            boxLayout->addWidget(comboBox);
    }
    auto *result_button = new QPushButton("=");
    connect(result_button, SIGNAL(clicked()), this, SLOT(calculateResult()));
    boxLayout->addWidget(result_button);
    boxLayout->addWidget(_matrices.last());
    setLayout(boxLayout);
}

void MatrixGuiList::calculateResult() {
    _matrices[0]->updateFromGui();
    _matrices[1]->updateFromGui();

    QString choice = comboBox->currentText();
    Matrix<double> mtx;
    try {
        if (choice == "+") {
            mtx = _matrices[0]->matrix() + _matrices[1]->matrix();
        } else if (choice == "-") {
            mtx = _matrices[0]->matrix() - _matrices[1]->matrix();
        } else if (choice == "*") {
            if (_matrices[1]->columns() == 1 && _matrices[1]->rows() == 1) {
                mtx = _matrices[0]->matrix() * _matrices[1]->matrix().value(0, 0);
            } else mtx = _matrices[0]->matrix() * _matrices[1]->matrix();
        } else if (choice == "==") {
            bool equal = _matrices[0]->matrix() == _matrices[1]->matrix();
            mtx = equal ? Matrix<double>(1, 1, 1) : Matrix<double>(1, 1, 0);
        }
    } catch (...) {
        QMessageBox::warning(this, "Error", "Invalid operation with this matrices!", QMessageBox::Ok);
        return;
    }
    _matrices[2]->setMatrix(mtx);
    _matrices[2]->updateGui();
}
