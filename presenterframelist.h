#ifndef PRESENTERFRAMELIST_H
#define PRESENTERFRAMELIST_H

#include <QObject>
#include <QList>

struct PresenterFrame{
    quint32 frameNo;
    bool Inverter;
    QList<QString> LedColors;
    QList<bool> ValveOnOff;
    QList<bool> LedOnOff;
    quint8 InverterLevel;
    quint8 LedChannels;
    quint8 ValveChannels;

};

class PresenterFrameList : public QObject
{
    Q_OBJECT
public:
    explicit PresenterFrameList(QObject *parent = nullptr);

signals:

public slots:
};

#endif // PRESENTERFRAMELIST_H
