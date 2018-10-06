#include "WSchedule.h"

WSchedule::WSchedule(vector<GroupSchedule> &groupsVector_, QWidget *parent)
        : QWidget(parent), groupsVector(groupsVector_) {

    qDebug()<<"groups push start";
    for (auto &group : groupsVector) {
        wgroups.push_back(new WGroup(group, this));
    }
    qDebug()<<"groups pushed";


    createWidgets();

    QString db_path = "database";

    if (QFile::exists(db_path)) {
        qDebug() << "DB exists";
    }

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(db_path);

    if (!db.open()) {
        qDebug() << "Cannot open database: " << db.lastError();
    }

    QSqlQuery query;
    if (!query.exec(
            "CREATE TABLE IF NOT EXISTS schedule ("
            "day VARCHAR(20), "
            "lesson VARCHAR(20), "
            "parity VARCHAR(20), "
            "professor VARCHAR(20), "
            "cabinet VARCHAR(20), "
            "CONSTRAINT pk_schedule "
            "PRIMARY KEY (day, lesson, parity, professor, cabinet)"
            ");")) {
        qDebug() << query.lastError();
    }
}

void WSchedule::createWidgets() {
    auto *box = new QHBoxLayout(this);
    for (auto &wGroup : wgroups) {
        box->addWidget(wGroup);
    }
}

void WSchedule::saveSchedule() {
    for(WGroup *wgrp: wgroups){
        wgrp->saveGroup();
    }
}

void WSchedule::insertScheduleToDb() {

    for(WGroup* gr: wgroups){
        if(!gr->insertGroupToDb()){
            break;
        }
    }
    QSqlQuery query;
    if (!query.exec("SELECT * FROM schedule;")) {
        qDebug() << query.lastError();
    }
    while (query.next()) {
        qDebug() <<"вывод бд: "
                << query.value(0).toString()
                << query.value(1).toString()
                << query.value(2).toString()
                << query.value(3).toString()
                << query.value(4).toString();
    }
    if( !query.exec("DELETE FROM schedule")){
        qDebug() <<"cant delete" << query.lastError();
    }
}



