#ifndef WGROUP_H
#define WGROUP_H

#include <WLesson.h>
#include <QtSql>


static const QSize hedSize[] = { //todo wgroup size
        {30,  h},
        {140, h / 2},
        {30,  h / 2},
        {40,  h / 2},
        {40,  h / 2},
        {30,  h / 2},
        {210, h / 2},
        {40,  h / 2},
        {120, h / 2},
        {55,  h / 2},

        {210, h / 2},
        {160, h / 2},
        {55,  h / 2}
};

class WGroup : public QWidget {
Q_OBJECT
private:

    QStringList headerLabels = {
            {"Неделя"},
            {"Группа"},
            {"№ пары"},
            {"Нач."},
            {"Кон."},
            {"Неделя"},
            {"Предмет"},
            {"Вид занятий"},
            {"ФИО преподавателя"},
            {"№ ауд."}
    };

    QStringList week = {
            {"Пн"},
            {"Вт"},
            {"Ср"},
            {"Чт"},
            {"Пт"},
            {"Сб"}
    };

    QVector<QStringList> lessonsTimeList = {
            {" 9-00", "10-30"},
            {"10-40", "12-10"},
            {"13-00", "14-30"},
            {"14-40", "16-10"},
            {"16-20", "17-50"},
            {"18-00", "19-30"},
    };

    QVBoxLayout *groupVerLayout;

    array<QLabel *, 10> wlabels;
    array<QLineEdit *, 3> wlineEdits;
    vector<WLesson *> wlessons;

    GroupSchedule &groupScheduleRef;

private:
    void createWidgets();

public:

    WGroup(GroupSchedule &groupSchedule_, QWidget *parent);

    void saveGroup();

    bool insertGroupToDb();

    bool insertLessonToDb(QString &day, int lesson, int parity, WLesson *wLesson);

};

#endif // WGROUP_H
