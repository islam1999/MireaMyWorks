#ifndef LOGGER_H
#define LOGGER_H

#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QDebug>
#include <QLoggingCategory>

Q_DECLARE_LOGGING_CATEGORY(log)

Q_DECLARE_LOGGING_CATEGORY(gui)

Q_DECLARE_LOGGING_CATEGORY(db)

Q_DECLARE_LOGGING_CATEGORY(parse)


class Logger : public QObject {
Q_OBJECT

private:
    static QScopedPointer<QFile> logFile;

    static void messageHandler(QtMsgType type,
                               const QMessageLogContext &context,
                               const QString &msg);

public:
    explicit Logger(QObject *parent = nullptr);

    void writeLog(const QString &message,
                         const QLoggingCategory &log, QtMsgType type = QtInfoMsg);

signals:

public slots:
};

#endif // LOGGER_H
