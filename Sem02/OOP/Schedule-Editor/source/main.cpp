#include <QApplication>
#include "WMain.h"

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);

    Scheduler scheduler;

    WMain wMain(scheduler);
    wMain.openFile();
    wMain.show();

    return QApplication::exec();
}
