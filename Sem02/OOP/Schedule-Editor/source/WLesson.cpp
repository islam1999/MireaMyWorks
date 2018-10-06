#include "WLesson.h"


WLesson::WLesson(int lessonNumber, QStringList &time, QWidget *parent)
        : QWidget(parent){
    createWidgets(lessonNumber, time);


}

void WLesson::createWidgets(int lessonNumber, QStringList &time) {
    labelsLayout = new QGridLayout;
    textLayout = new QGridLayout;

    labels[0] = new QLabel(QString::number(lessonNumber), this);
    labels[0]->setFixedSize(lesSize[0]);

    unsigned int i = 0;
    for (i = 1; i < 3; ++i) {
        labels[i] = new QLabel(time[i - 1], this);
        labels[i]->setFixedSize(lesSize[1]);
    }

    labels[3] = new QLabel(" I", this);
    labels[4] = new QLabel("II", this);

    labels[3]->setFixedSize(lesSize[2]);
    labels[4]->setFixedSize(lesSize[2]);

    QFont font = labels[0]->font();
    font.setPointSize(10);
    for (i = 0; i < labels.size(); ++i) {
        labels[i]->setStyleSheet("background-color: orange");
        labels[i]->setAlignment(Qt::AlignCenter);
        labels[i]->setFont(font);
    }
    for (i = 0; i < 3; ++i) {
        labelsLayout->addWidget(labels[i], 0, i, 2, 1);
    }
    labelsLayout->addWidget(labels[3], 0, i);
    labelsLayout->addWidget(labels[4], 1, i);


    for (i = 0; i < 8; ++i) {
        textEdits[i] = new QTextEdit(this);
        textEdits[i]->setLineWrapMode(QTextEdit::NoWrap);
        textEdits[i]->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEdits[i]->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEdits[i]->setFontPointSize(8);
    }

    unsigned int k = 0;
    for (i = 0; i < 8; i += 2) {
        textLayout->addWidget(textEdits[i], 0, k++);
    }

    k = 0;
    for (i = 1; i < 8; i += 2) {
        textLayout->addWidget(textEdits[i], 1, k++);
    }

    k = 3;
    for (i = 0; i < 8; i += 2, ++k) {
        textEdits[i]->setFixedSize(lesSize[k]);
        textEdits[i + 1]->setFixedSize(lesSize[k]);
    }

    auto hboxl = new QHBoxLayout(this);

    labelsLayout->setSpacing(1);
    textLayout->setSpacing(1);
    hboxl->setSpacing(1);

    hboxl->addLayout(labelsLayout);
    hboxl->addLayout(textLayout);
}

void WLesson::setSubject(int parity, QString name) {
    textEdits[parity]->setText(name);
}

void WLesson::setType(int parity, QString name) {
    textEdits[2 + parity]->setText(name);

}

void WLesson::setProfessor(int parity, QString name) {
    textEdits[4 + parity]->setText(name);

}

void WLesson::setRoom(int parity, QString name) {
    textEdits[6 + parity]->setText(name);
}

QString WLesson::getSubject(int parity) {
    return textEdits[parity]->toPlainText();

}

QString WLesson::getType(int parity) {
    return textEdits[2+ parity]->toPlainText();
}

QString WLesson::getProfessor(int parity) {
    return textEdits[4 + parity]->toPlainText();
}

QString WLesson::getRoom(int parity) {
    return textEdits[6 + parity]->toPlainText();
}



