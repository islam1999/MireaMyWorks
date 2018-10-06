#include "WGroup.h"

WGroup::WGroup(GroupSchedule &groupSchedule_, QWidget *parent)
        : QWidget(parent), groupScheduleRef(groupSchedule_) {

    for (int day = 0; day < 6; ++day) {
        for (int lesNum = 0; lesNum < 6; ++lesNum) {
            WLesson *wLesson = new WLesson(lesNum + 1, lessonsTimeList[lesNum]);
            wlessons.push_back(wLesson);

            for (int parity = 0; parity < 2; ++parity) {
                const Lesson &lesson = groupScheduleRef.get_lesson(parity + 1, day + 1, lesNum + 1);
                wLesson->setSubject(parity,
                                    QString::fromStdString(lesson.get_subject_name()));
                wLesson->setType(parity,
                                 QString::fromStdString(lesson.get_lesson_type()));
                wLesson->setProfessor(parity,
                                      QString::fromStdString(lesson.get_professor()));
                wLesson->setRoom(parity,
                                 QString::fromStdString(lesson.get_room()));
            }
        }
    }
    createWidgets();

    wlineEdits[0]->setText(
            QString::fromStdString(groupScheduleRef.get_group_name())
    );
    wlineEdits[1]->setText(
            QString::fromStdString(groupScheduleRef.get_group_faculty())
    );
    wlineEdits[2]->setText(QString::fromStdString(groupScheduleRef.get_group_magic_number())
    );

}

void WGroup::createWidgets() {
    //header
    auto headerLayout = new QGridLayout();
    headerLayout->setSpacing(1);

    unsigned int i;
    for (i = 0; i < wlabels.size(); ++i) {
        wlabels[i] = new QLabel(headerLabels[i], this);
        wlabels[i]->setFixedSize(hedSize[i]);
        wlabels[i]->setStyleSheet("background-color: gray");
    }
    for (i = 0; i < wlineEdits.size(); ++i) {
        wlineEdits[i] = new QLineEdit(this);
        wlineEdits[i]->setFixedSize(hedSize[i + 10]);
    }

    unsigned int r = 0, c = 0;
    headerLayout->addWidget(wlabels[0], r, c, 2, 1);
    headerLayout->addWidget(wlabels[1], r++, ++c, 1, 4);
    for (i = 2; i < 6; ++i) {
        headerLayout->addWidget(wlabels[i], r, c++);
    }
    for (i = 6; i < wlabels.size(); ++i) {
        headerLayout->addWidget(wlabels[i], r, c++);
    }

    r = 0, c = 5;
    headerLayout->addWidget(wlineEdits[0], r, c++);
    headerLayout->addWidget(wlineEdits[1], r, c, 1, 2);
    c += 2;
    headerLayout->addWidget(wlineEdits[2], r, c);
    //end header

    groupVerLayout = new QVBoxLayout(this);
    groupVerLayout->setSpacing(1);
    groupVerLayout->addLayout(headerLayout);

    for (int lesNum = 0, day = 0; day < 6; ++day) {
        auto lessonsVerLayout = new QVBoxLayout();
        auto dayHorLayout = new QHBoxLayout();

        lessonsVerLayout->setSpacing(1);
        dayHorLayout->setSpacing(1);

        auto dayLabel = new QLabel(week[day]);
        dayLabel->setFixedSize(lesSize[0].width(), lesSize[0].height() * 8);
        dayLabel->setStyleSheet("background-color: gray");
        dayLabel->setAlignment(Qt::AlignCenter);

        dayHorLayout->addWidget(dayLabel);

        for (i = 0; i < 6; ++i) {
            lessonsVerLayout->addWidget(wlessons[lesNum++]);
        }
        dayHorLayout->addLayout(lessonsVerLayout);
        groupVerLayout->addLayout(dayHorLayout);
    }
}

void WGroup::saveGroup() {
    string str = wlineEdits[0]->text().toStdString();
    groupScheduleRef.set_group_name(str);

    str = wlineEdits[1]->text().toStdString();
    groupScheduleRef.set_group_faculty(str);

    str = wlineEdits[2]->text().toStdString();
    groupScheduleRef.set_group_magic_number(str);

    int k=0;
    for (int day = 1; day < 7; ++day) {
        for (int lesNum = 1; lesNum < 7; ++lesNum, ++k) {
            for (int parity = 0; parity < 2; ++parity) {

                auto &lesson = groupScheduleRef.get_lesson_non_const_ref(parity+1, day, lesNum);

                lesson.set_subject_name(
                        wlessons[k]->getSubject(parity).toStdString()
                );

                lesson.set_lesson_type(
                        wlessons[k]->getType(parity).toStdString()
                );

                lesson.set_professor(
                        wlessons[k]->getProfessor(parity).toStdString()
                );

                lesson.set_room(
                        wlessons[k]->getRoom(parity).toStdString()
                );

                groupScheduleRef.set_lesson(parity+1, day, lesNum, lesson);
            }
        }
    }
}


bool WGroup::insertGroupToDb(){
    int k=0;
    for (int day = 0; day < 6; ++day) {
        for (int lesNum = 1; lesNum < 7; ++lesNum, ++k) {
            for (int p = 0; p < 2; ++p) {

                bool empty = false;
                for(int c=0; c < 4; ++c){  //ouch...
                    //empty = wlessons[k]->textEdits[c]->placeholderText().isEmpty();
                    empty = wlessons[k]->textEdits[c]->toPlainText().isEmpty();
                    if(empty) {
                        qDebug("empty");
                        break;
                    }
                    qDebug("NOT empty");

                }
                if(empty){
                    continue;
                }

                if(!insertLessonToDb(week[day], lesNum, p, wlessons[k])) {
                    QString type = wlessons[k]->textEdits[2 + p]->toPlainText();
                    if (type == "лк" || type == "лаб") {
                        wlessons[k]->textEdits[4 + p]->setStyleSheet("background-color: white");
                        wlessons[k]->textEdits[6 + p]->setStyleSheet("background-color: white");
                        continue;
                    }
                    wlessons[k]->textEdits[4 + p]->setStyleSheet("background-color: red");
                    wlessons[k]->textEdits[6 + p]->setStyleSheet("background-color: red");

                    qDebug() << "ALARM";
                    qDebug() << wlessons[k]->textEdits[4 + p]->toPlainText();
                    qDebug() <<  wlessons[k]->textEdits[6 + p]->toPlainText();
                    return false;
                }
                wlessons[k]->textEdits[4 + p]->setStyleSheet("background-color: white");
                wlessons[k]->textEdits[6 + p]->setStyleSheet("background-color: white");
            }
        }
    }
    return true;
}

bool WGroup::insertLessonToDb(QString &day, int lesson, int parity, WLesson *wLesson) {

    QSqlQuery query;

    query.prepare("INSERT INTO schedule  (day, lesson, parity, professor, cabinet) "
                  "VALUES (:day, :lesson, :parity, :professor, :cabinet);");

    query.bindValue(":day", day);
    query.bindValue(":lesson", QString(lesson));
    query.bindValue(":parity", QString(parity));
    query.bindValue(":professor", wLesson->getProfessor(parity));
    query.bindValue(":cabinet", wLesson->getRoom(parity));

    return query.exec();

}