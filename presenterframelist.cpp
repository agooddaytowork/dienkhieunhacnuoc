#include "presenterframelist.h"
#include <QDebug>
#include <QString>
PresenterFrameList::PresenterFrameList(QObject *parent) : QObject(parent),  mDuration(0), mFrameDuration(0),mFrameNo(0),mGroup(0)
{

}


void PresenterFrameList::clearList()
{
    frameList.clear();

    for(int i = 0; i < mFrameNo; i++)
    {
        frameList.append(createEmptyFramePerGroup(mGroup));
    }
}

void PresenterFrameList::regenerateFrameList(const int &Duration, const int &FrameDuration)
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
        mFrameNo = static_cast<int>(Duration/FrameDuration);

        if(Duration%FrameDuration != 0)
        {
            mFrameNo ++;
        }
    }
    clearList();

//    qDebug() << "Frame List ---------";
//    qDebug() << "total Frame: " + QString::number(mFrameNo);
//    qDebug() << "frame list count: " + QString::number(frameList.count());


}

int  PresenterFrameList::getFrameDuration() const
{
    return mFrameDuration;
}

int PresenterFrameList::getDuration() const
{

    return mDuration;
}

int PresenterFrameList::getFrameNo() const
{
    return mFrameNo;
}


void PresenterFrameList::playFrame(const int &frameNo)
{
    if(frameNo <= this->mFrameNo)
    {
        emit notifyFrameChanged(getFrame(frameNo));
    }

}


PresenterFrame PresenterFrameList::getFrame(const int &frameNo)
{
    return frameList.at(frameNo);
}

void PresenterFrameList::timeSlotChanged(const timeSlotItem &timeSlot)
{


//    qDebug() << "Time SLot Changed";
    int fromFrame = findFrameFromMs(timeSlot.fromMs);
    int toFrame = findFrameFromMs(timeSlot.toMs);

    int previousFrameIndex = timeSlotExistInList(timeSlot.id);
    if(previousFrameIndex >= 0)
    {
//         qDebug() << "previous Frame Found";
        PreviousFrame thePreviousFrame = timeSlotShortVerList[previousFrameIndex];


        thePreviousFrame.FromFrame = fromFrame;
        thePreviousFrame.ToFrame = toFrame;
        timeSlotShortVerList[previousFrameIndex] = thePreviousFrame;

    }
    else
    {
        PreviousFrame aTimeSlotShort;

        aTimeSlotShort.FromFrame = fromFrame;
        aTimeSlotShort.ToFrame = toFrame;
        aTimeSlotShort.id = timeSlot.id;

        timeSlotShortVerList.append(aTimeSlotShort);
    }

    while(fromFrame <= toFrame)
    {
        frameList[fromFrame] = setFramePerGroup(timeSlot, frameList.at(fromFrame));
        fromFrame++;
    }

    emptyFrameCleanUp();



}

int PresenterFrameList::findFrameFromMs(const int &timePoint)
{
//    qDebug() << "timePoint: " + QString::number(timePoint);
    if(timePoint<0)
    {
        return  0;
    }
    else if(timePoint > mDuration)
    {
        return mDuration/mFrameDuration;
    }
    return static_cast<int>(timePoint/mFrameDuration);
}

PresenterFrame PresenterFrameList::setFramePerGroup( const timeSlotItem &timeSlot, PresenterFrame aFrame) const
{
    aFrame.LedOnOff.clear();
    aFrame.ValveOnOff.clear();

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

PresenterFrame PresenterFrameList::createEmptyFramePerGroup(const int &group) const
{
   PresenterFrame item;

   item.InverterLevel = 0;


   switch(group)
   {
   case 0:
       item.Inverter = true;
       item.LedChannels = 1;
       item.ValveChannels = 1;
       item.ValveOnOff.insert(1,false);
       item.LedOnOff.insert(1,false);

       break;
   case 1:
       item.LedChannels = 1;
       item.ValveChannels = 8;
       item.ValveOnOff.insert(8,false);
       item.LedOnOff.insert(1,false);
       break;
   case 2:
       item.LedChannels = 1;
       item.ValveChannels = 16;
       item.ValveOnOff.insert(16,false);
       item.LedOnOff.insert(1,false);
       break;
   case 3:
       item.LedChannels = 2;
       item.Inverter = true;
       item.ValveChannels = 1;
       item.ValveOnOff.insert(1,false);
       item.LedOnOff.insert(2,false);
       break;
   case 4:
       item.LedChannels = 3;
       item.ValveChannels = 1;
       item.ValveOnOff.insert(1,false);
       item.LedOnOff.insert(3,false);
       break;
   case 5:
       item.LedChannels = 12;
       item.Inverter = true;
       item.ValveChannels = 2;
       item.ValveOnOff.insert(2,false);
       item.LedOnOff.insert(12,false);
       break;
   case 6:
       item.LedChannels = 6;
       item.ValveChannels = 2;
       item.ValveOnOff.insert(2,false);
       item.LedOnOff.insert(6,false);
       break;
   case 7:
       item.LedChannels = 8;
       item.ValveChannels = 8;
       item.ValveOnOff.insert(8,false);
       item.LedOnOff.insert(8,false);
       break;
   case 8:
       item.LedChannels = 2;
       item.ValveChannels = 2;
       item.ValveOnOff.insert(2,false);
       item.LedOnOff.insert(2,false);
       break;

   }

   return item;

}



 bool operator<(const PreviousFrame& a, const PreviousFrame& b) { return a.FromFrame < b.FromFrame; }

void PresenterFrameList::emptyFrameCleanUp()
{
    int frameCnt = 0;


    std::sort(timeSlotShortVerList.begin(),timeSlotShortVerList.end());

    for(int i =0; i < timeSlotShortVerList.count(); i++)
    {
//        qDebug() << "fromFrame: " + QString::number(timeSlotShortVerList[i].FromFrame) << "frameCnt: " + QString::number(frameCnt);
        while(frameCnt < timeSlotShortVerList[i].FromFrame)
        {
         frameList[frameCnt]= createEmptyFramePerGroup(mGroup);
            frameCnt++;
        }
        frameCnt = timeSlotShortVerList[i].ToFrame + 1;
//          qDebug() << "frameCnt after: " + QString::number(frameCnt);
    }

    while(frameCnt < mFrameNo)
    {
        frameList[frameCnt]= createEmptyFramePerGroup(mGroup);
        frameCnt++;
    }


}

void PresenterFrameList::timeSlotRemoved(const timeSlotItem &timeSlot)
{



    int index = timeSlotExistInList(timeSlot.id);

    if(index >= 0)
    {
        timeSlotShortVerList.remove(index);
    }

    emptyFrameCleanUp();
//    while(fromFrame <= toFrame)
//    {
//        frameList[fromFrame] = createEmptyFramePerGroup(mGroup);
//        fromFrame++;
//    }

//    for(int i = 0; i < timeSlotShortVerList.count(); i++)
//    {
//        if(timeSlotShortVerList[i].id == timeSlot.id)
//        {
//            timeSlotShortVerList.remove(timeSlotShortVerList[i].FromFrame);
//            return;
//        }
//    }
}


int PresenterFrameList::timeSlotExistInList(const int &id)
{
    if(timeSlotShortVerList.count() > 0)
    {
        for(int i = 0; i < timeSlotShortVerList.count(); i++)
        {
            if(timeSlotShortVerList[i].id == id)
            {
                return i;
            }
        }
    }
    return -1;
}
