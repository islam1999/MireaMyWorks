#ifndef WMAIN_H
#define WMAIN_H

#include <QMainWindow>
#include <QScrollArea>
#include "WSchedule.h"

class WMain : public QMainWindow {
Q_OBJECT
private:

    WSchedule *wschedule;
    Scheduler& scheduler;

    QScrollArea *scroll;

    void createWidgets();

public:

 WMain(Scheduler &scheduler_, QWidget *parent = nullptr);

signals:

public slots:

    void openFile();
    void saveFile();
    void saveAsFile();
    void checkSchedule();

};

#endif // WMAIN_H
