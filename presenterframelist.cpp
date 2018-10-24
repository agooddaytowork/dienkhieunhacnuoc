#include "presenterframelist.h"
#include <QDebug>
PresenterFrameList::PresenterFrameList(QObject *parent) : QObject(parent),  mDuration(0), mFrameDuration(0),mFrameNo(0)
{

}


void PresenterFrameList::clearList()
{
    frameList.clear();

    for(quint32 i = 0; i < mFrameNo; i++)
    {
        frameList.append(PresenterFrame());
    }
}

void PresenterFrameList::regenerateFrameList(const quint32 &Duration, const quint32 &FrameDuration)
{

    bool isAnyThingChanged = false;

    if(mFrameDuration != FrameDuration)
    {
        mFrameDuration = FrameDuration;
        isAnyThingChanged = true;
    }
    if(mDuration != Duration)
    {
        mDuration = Duration;
        isAnyThingChanged = true;
    }

    if(isAnyThingChanged)
    {
        mFrameNo = static_cast<quint32>(Duration/FrameDuration);

        if(Duration%FrameDuration != 0)
        {
            mFrameNo ++;
        }
    }
    clearList();


}

quint32  PresenterFrameList::getFrameDuration() const
{
    return mFrameDuration;
}

quint32 PresenterFrameList::getDuration() const
{

    return mDuration;
}

quint32 PresenterFrameList::getFrameNo() const
{
    return mFrameNo;
}


void PresenterFrameList::playFrame(const quint32 &frameNo)
{
    emit notifyFrameChanged(getFrame(frameNo));
}


PresenterFrame PresenterFrameList::getFrame(const quint32 &frameNo)
{
    return frameList.at(static_cast<int>(frameNo));
}

void PresenterFrameList::timeSlotChanged(const timeSlotItem &timeSlot)
{
    qDebug() << "Time SLot Changed";
    int fromFrame = findFrameFromMs(timeSlot.fromMs);
    int toFrame = findFrameFromMs(timeSlot.toMs);


    while(fromFrame <= toFrame)
    {
        frameList[fromFrame] = setFramePerGroup(timeSlot, frameList.at(fromFrame));
        fromFrame++;
    }

}

int PresenterFrameList::findFrameFromMs(const quint32 &timePoint)
{
    return static_cast<int>(timePoint/this->mFrameDuration);
}

PresenterFrame PresenterFrameList::setFramePerGroup( const timeSlotItem &timeSlot, PresenterFrame aFrame) const
{
    aFrame.ValveOnOff.clear();
    aFrame.LedOnOff.clear();
    aFrame.LedColors.clear();
    for(int i = 0; i < timeSlot.ValveChannels; i++)
    {
        aFrame.ValveOnOff.append(timeSlot.ValveOnOff);

    }
    for(int i = 0; i < timeSlot.LedChannels; i++)
    {
        aFrame.LedOnOff.append(timeSlot.LedOnOff);
        aFrame.LedColors.append(timeSlot.LedValuesList);
    }

    return aFrame;
}

void PresenterFrameList::timeSlotRemoved(const timeSlotItem &timeSlot)
{
    int fromFrame = findFrameFromMs(timeSlot.fromMs);
    int toFrame = findFrameFromMs(timeSlot.toMs);


    while(fromFrame <= toFrame)
    {
        frameList[fromFrame] = PresenterFrame();
        fromFrame++;
    }
}

