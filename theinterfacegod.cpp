#include "theinterfacegod.h"

theInterfaceGod::theInterfaceGod(QObject *parent) : QObject(parent)
{

}


void theInterfaceGod::regenerateFrameList(const quint32 &duration, const quint32 &frameDuration)
{
    emit SIG_regenerateFrameList(duration, frameDuration);
}
