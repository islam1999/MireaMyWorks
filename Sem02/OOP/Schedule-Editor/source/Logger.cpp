#include "Logger.h"

Q_LOGGING_CATEGORY(log, "LOG")

Q_LOGGING_CATEGORY(gui, "GUI")

Q_LOGGING_CATEGORY(db, "DB")

Q_LOGGING_CATEGORY(parse, "PARSE")

QScopedPointer<QFile>  Logger::logFile;

Logger::Logger(QObject *parent) : QObject(parent) {
    qInstallMessageHandler(messageHandler);
    if (!QFile::exists("resources/log.txt")) {
        logFile.reset(new QFile("resources/log.txt"));
    }
    logFile.data()->open(QFile::Append | QFile::Text);
    writeLog("Start logging", log(), QtInfoMsg);
}

void Logger::writeLog(const QString &message,
                      const QLoggingCategory &log, QtMsgType type/*=QtInfoMsg*/) {
    switch (type) {
        case QtInfoMsg:
            qInfo(log) << message;
            break;
        case QtDebugMsg:
            qDebug(log) << message;
            break;
        case QtWarningMsg:
            qWarning(log) << message;
            break;
        case QtCriticalMsg:
            qCritical(log) << message;
            break;
        case QtFatalMsg:
            QLoggingCategory lg("fatal", QtFatalMsg);
            qFatal(" ___Ну все, приехали. Зовите фиксиков___");
    }
}

void Logger::messageHandler(QtMsgType type,
                            const QMessageLogContext &context,
                            const QString &message) {
    QTextStream out(logFile.data());
    out << QDateTime::currentDateTime().toString("[yyyy-MM-dd hh:mm:ss.zzz]");
    out << "[";
    if (type == QtFatalMsg)
        out << "FATAL";
    else out << context.category;
    out << "] " << message << endl;

#ifdef QT_DEBUG
    out << "\t\t" <<
        context.file << ":" <<
        context.function << ":" <<
        context.line << ":" << endl;
#endif
    out.flush();
}
