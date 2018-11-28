#ifndef PRESENTERFRAMELIST_H
#define PRESENTERFRAMELIST_H

#include <QObject>
#include <QVector>
#include "timeslotlist.h"

#include "valveeffect_kieu1.h"
#include "valveeffect_kieu2.h"
#include "valveeffect_kieu3.h"
#include "valveeffect_kieu4.h"
//#include "anlogger.h"
#include <QMap>


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

struct PreviousFrame{
    int id;
    int FromFrame;
    int ToFrame;
};

class PresenterFrameList : public QObject
{
    Q_OBJECT

    int mDuration;
    int mFrameDuration;
    int mFrameNo;


    ValveEffect_Kieu1 mValveEffect_1;
    ValveEffect_Kieu2 mValveEffect_2;
    ValveEffect_Kieu3 mValveEffect_3;
    ValveEffect_Kieu4 mValveEffect_4;

    QVector<PresenterFrame> frameList;
    QVector<PreviousFrame> timeSlotShortVerList;

    PresenterFrame setFramePerGroup(const int &index, const timeSlotItem &timeSlot,  PresenterFrame aFrame);
    PresenterFrame createEmptyFramePerGroup(const int &group) const;
    void emptyFrameCleanUp();



    int timeSlotExistInList(const int &id);
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
