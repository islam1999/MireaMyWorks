#include "MatrixGuiList.h"

MatrixGuiList::MatrixGuiList(QWidget *parent) : QWidget(parent) {
    boxLayout = new QHBoxLayout();
    scrollArea = new QScrollArea();

    for (int i = 0; i < 3; ++i) {
        array[i] = new MatrixGui();
        boxLayout->addWidget(array.at(i));
        if(i==0)
            boxLayout->addWidget(new QPushButton("+"));
        if(i==1)
            boxLayout->addWidget(new QPushButton("="));
    }
    scrollArea->setLayout(boxLayout);
    setLayout(boxLayout);
}

MatrixGuiList::~MatrixGuiList() {

}
