
#include <MatrixGui.h>

MatrixGui::MatrixGui(QWidget *parent) : QWidget(parent) {
    createUI();
}

MatrixGui::MatrixGui(const Matrix<double> &mtx, QWidget *parent) : QWidget(parent), _matrix(mtx) {
    createUI();
}

MatrixGui::~MatrixGui() {
    delete _validator;
    delete _layout;
    for (auto &qVec : _cells)
        qDeleteAll(qVec);
}

const Matrix<double> &MatrixGui::matrix() const {
    return _matrix;
}

int MatrixGui::rows() const {
    return _cells.size();
}

int MatrixGui::columns() const {
    return _cells[0].size();
}

void MatrixGui::setMatrix(const Matrix<double> &mtx) {
    _matrix = mtx;
}

void MatrixGui::updateFromGui() {
    _matrix.resize(rows(), columns());
    for (int i = 0; i < rows(); ++i) {
        for (int j = 0; j < columns(); ++j) {
            double value = _cells[i][j]->text().toDouble();
            _matrix.setValue(i, j, value);
        }
    }
}

void MatrixGui::updateGui() {
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

void MatrixGui::increaseRow() {
    updateFromGui();
    if (rows() > _maxSize)
        return;
    _matrix.resize(rows() + 1, columns());
    updateGui();
}

void MatrixGui::increaseColumn() {
    updateFromGui();
    if (columns() > _maxSize)
        return;
    _matrix.resize(rows(), columns() + 1);
    updateGui();
}

void MatrixGui::decreaseRow() {
    updateFromGui();
    if (rows() == 1)
        return;
    _matrix.resize(rows() - 1, columns());
    updateGui();
}

void MatrixGui::decreaseColumn() {
    updateFromGui();
    if (columns() == 1)
        return;
    _matrix.resize(rows(), columns() - 1);
    updateGui();
}

void MatrixGui::createUI() {
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
