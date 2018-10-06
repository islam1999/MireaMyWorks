#ifndef WSCHEDULE_H
#define WSCHEDULE_H

#include "WGroup.h"

class WSchedule : public QWidget {
Q_OBJECT
private:
    vector<WGroup *> wgroups;

    vector<GroupSchedule> &groupsVector;
private:
    void createWidgets();

public:
    explicit WSchedule(vector<GroupSchedule> &groupsVector_, QWidget *parent);

    void saveSchedule();

    void insertScheduleToDb();

signals:

public slots:
};

#endif // WSCHEDULE_H
