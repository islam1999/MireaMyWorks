#include "WMain.h"


WMain::WMain(Scheduler &scheduler_, QWidget *parent): scheduler(scheduler_){
    wschedule = new WSchedule(scheduler.get_groups_non_const_ref(), this);

    createWidgets();

}

void WMain::createWidgets() {
    auto *menuBar = new QMenuBar(this);
    QMenu *file = new QMenu("&File", this);
    file->setTearOffEnabled(true);
    file->addAction("&Open file", this, SLOT(openFile()), Qt::CTRL + Qt::Key_O);
    file->addAction("&Save", this, SLOT(saveFile()), Qt::CTRL + Qt::Key_S);
    file->addAction("&Save as", this, SLOT(saveAsFile()), Qt::CTRL + Qt::SHIFT+ Qt::Key_S);
    file->addSeparator();
    file->addAction("&Exit", qApp, SLOT(quit()));


    QMenu *db = new QMenu("&Database", this);
    db->setTearOffEnabled(true);
    db->addAction("&Check", this, SLOT(checkSchedule()), Qt::CTRL + Qt::Key_C);

    menuBar->addMenu(file);
    menuBar->addMenu(db);

    scroll = new QScrollArea(this);
    setCentralWidget(scroll);
    this->layout()->setMenuBar(menuBar);

    scroll->setWidget(wschedule);
    scroll->update();
}

void WMain::openFile() {
    QString file_path = QFileDialog::getOpenFileName(this, tr("Open File"), "." , tr("*"));

    this->scheduler.open_new_schedule(file_path.toStdString());

    wschedule = new WSchedule(scheduler.get_groups_non_const_ref(), this);

    scroll->setWidget(wschedule);
    scroll->update();
    qDebug() << "opened";


};

void WMain::saveFile() {
    wschedule->saveSchedule();
    scheduler.save_schedule();
};

void WMain::saveAsFile() {
    wschedule->saveSchedule();
    QString saveFileName = QFileDialog::getSaveFileName(this,"Save As","./new_file.xlsx",tr("files(*.xlsx )"));
    scheduler.save_schedule_as(saveFileName.toStdString());
}

void WMain::checkSchedule(){
    wschedule->insertScheduleToDb();
}
