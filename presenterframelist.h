#ifndef PRESENTERFRAMELIST_H
#define PRESENTERFRAMELIST_H

#include <QObject>
#include <QVector>
#include "timeslotlist.h"


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

    quint32 mDuration;
    quint32 mFrameDuration;
    quint32 mFrameNo;
    QVector<PresenterFrame> frameList;

    PresenterFrame setFramePerGroup(const timeSlotItem &timeSlot,  PresenterFrame aFrame) const;
public:
    explicit PresenterFrameList(QObject *parent = nullptr);

    void clearList();

    quint32 getFrameDuration() const;
    quint32 getDuration() const;
    quint32 getFrameNo() const;
    PresenterFrame getFrame(const quint32 &frameNo);
    int findFrameFromMs(const quint32 &timePoint);



signals:
    void notifyFrameChanged(const PresenterFrame &frame);

public slots:
    void timeSlotChanged(const timeSlotItem &timeSlot);
    void timeSlotRemoved(const timeSlotItem &timeSlot);
    void playFrame(const quint32 &frameNo);
    void regenerateFrameList(const quint32 &Duration, const quint32 &FrameDuration);


};

#endif // PRESENTERFRAMELIST_H
