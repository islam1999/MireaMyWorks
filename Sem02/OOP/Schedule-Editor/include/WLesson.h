#ifndef WLESSON_H
#define WLESSON_H

#include <QtWidgets>
#include "scheduler.h"

using namespace std;
using namespace scheduler;

const unsigned int h = 71;
constexpr QSize lesSize[] = {
        {30,  h}, //пара 0
        {40,  h}, //нач/кон зан 1
        {30,  h / 2}, //четность 2
        {210, h / 2}, //предмет 3
        {40,  h / 2}, //вид занятий 4
        {120, h / 2}, //фио 5
        {55,  h / 2}, //кабинет 6
};

class WLesson : public QWidget {
Q_OBJECT
private:
    array<QLabel *, 5> labels;

    QGridLayout *labelsLayout;
    QGridLayout *textLayout;

    void createWidgets(int lessonNumber, QStringList &time);

public:
    array<QTextEdit *, 8> textEdits;
    //0 2 4 6
    //1 3 5 7

    WLesson(int lessonNumber, QStringList &time, QWidget *parent = nullptr);

    ~WLesson() override = default;

    void setSubject(int parity, QString name);

    void setType(int parity, QString name);

    void setProfessor(int parity, QString name);

    void setRoom(int parity, QString name);

    QString getSubject(int parity);

    QString getType(int parity);

    QString getProfessor(int parity);

    QString getRoom(int parity);

};

#endif // WLESSON_H
