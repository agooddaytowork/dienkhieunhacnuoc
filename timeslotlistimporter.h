#ifndef TIMESLOTLISTIMPORTER_H
#define TIMESLOTLISTIMPORTER_H

#include <QObject>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <timeslotlist.h>
#include <QFile>

class TimeSlotListImporter : public QObject
{
    Q_OBJECT

    QString mRootPath;
public:
    explicit TimeSlotListImporter(QObject *parent = nullptr);
    bool importFile(const QString &filePath);
    void setRootPath(const QString &rootPath);

signals:

public slots:
};

#endif // TIMESLOTLISTIMPORTER_H
