#ifndef PRESENTERFRAMELIST_H
#define PRESENTERFRAMELIST_H

#include <QObject>
#include <QVector>
#include "timeslotlist.h"
#include "anlogger.h"


struct PresenterFrame{
    int frameNo;
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

    int mDuration;
    int mFrameDuration;
    int mFrameNo;


    QVector<PresenterFrame> frameList;

    PresenterFrame setFramePerGroup(const timeSlotItem &timeSlot,  PresenterFrame aFrame) const;
    PresenterFrame createEmptyFramePerGroup(const int &group) const;
public:
    int mGroup;
    explicit PresenterFrameList(QObject *parent = nullptr);

    void clearList();

    int getFrameDuration() const;
    int getDuration() const;
    int getFrameNo() const;
    PresenterFrame getFrame(const int &frameNo);
    int findFrameFromMs(const int &timePoint);



signals:
    void notifyFrameChanged(const PresenterFrame &frame);

public slots:
    void timeSlotChanged(const timeSlotItem &timeSlot);
    void timeSlotRemoved(const timeSlotItem &timeSlot);
    void playFrame(const int &frameNo);
    void regenerateFrameList(const int &Duration, const int &FrameDuration);


};

#endif // PRESENTERFRAMELIST_H
