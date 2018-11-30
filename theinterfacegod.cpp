#include "theinterfacegod.h"

theInterfaceGod::theInterfaceGod(QObject *parent) : QObject(parent)
{

}


void theInterfaceGod::regenerateFrameList(const int &duration, const int &frameDuration)
{

    emit SIG_regenerateFrameList(duration, frameDuration);
}

void theInterfaceGod::playFrame(const int &frameNo)
{
    static int previousFrame = 0;

    if(previousFrame != frameNo)
    {
        previousFrame = frameNo;
    emit SIG_playFrame(frameNo);
    }

}

void theInterfaceGod::invokeTimeSlotChanged(){
    emit gui_timeSLotChanged();
}
