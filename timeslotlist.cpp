#include "timeslotlist.h"

timeSlotList::timeSlotList(QObject *parent) : QObject(parent), mCurrentIndex(0), mCollisionSide(false), mGroup(0)
{

}

timeSlotList::~timeSlotList()
{

}


QVector<timeSlotItem> timeSlotList::items() const
{
    return mItems;
}


bool timeSlotList::setItemAt(int index, const timeSlotItem &item)
{
    if (index < 0 || index >= mItems.size())
        return false;

    mItems[index] = item;

    emit timeSlotItemChanged(item);
    return true;
}


void timeSlotList::appendItem(const quint8 &group, const int &fromMs, const int &toMs)
{
    emit preItemAppended();
    timeSlotItem item;

    item.id = mCurrentIndex;
    item.fromMs = fromMs;
    item.toMs = toMs;
    item.ValveOnOff = true;
    item.LedOnOff = true;
    item.LedMode = 0;
    item.InverterLevel = 0;
    item.Inverter = false;
    item.ValveMode = 0;
    switch(group)
    {
    case 0:
        item.Inverter = true;
        item.LedChannels = 1;
        item.ValveChannels = 1;

        break;
    case 1:
        item.LedChannels = 1;
        item.ValveChannels = 8;
        break;
    case 2:
        item.LedChannels = 1;
        item.ValveChannels = 16;
        break;
    case 3:
        item.LedChannels = 2;
        item.Inverter = true;
        item.ValveChannels = 1;
        break;
    case 4:
        item.LedChannels = 3;
        item.ValveChannels = 1;
        break;
    case 5:
        item.LedChannels = 12;
        item.Inverter = true;
        item.ValveChannels = 2;
        break;
    case 6:
        item.LedChannels = 6;
        item.ValveChannels = 2;
        break;
    case 7:
        item.LedChannels = 8;
        item.ValveChannels = 8;
        break;
    case 8:
        item.LedChannels = 2;
        item.ValveChannels = 2;
        break;

    }
    mItems.append(item);
    mCurrentIndex++;


    emit postItemAppended();
//    emit timeSlotItemChanged(item);
}

void timeSlotList::removeItems(const int &id)
{
    for (int i = 0; i < mItems.size(); ) {
        if (mItems.at(i).id == id) {
            emit preItemRemoved(i);
            emit timeSlotItemRemoved(mItems.at(i));
            mItems.removeAt(i);

            emit postItemRemoved();


            return;
        } else {
            ++i;
        }
    }
}

timeSlotItem timeSlotList::getTimeSlotItem(const int &id)
{
    for (int i = 0; i < mItems.size(); i++)
    {
        if(mItems.at(i).id == id)
        {
            return mItems.at(i);
        }
    }

    return timeSlotItem();
}

bool timeSlotList::getCollisionSide()
{
    return mCollisionSide;
}

int timeSlotList::count()
{
    return mItems.size();
}

int timeSlotList::timeSlotCollisionCheck(const int &id)
{

    timeSlotItem theTimeSlot = getTimeSlotItem(id);

    for(int i = 0; i < mItems.count(); i++ )
    {
        if(mItems.at(i).id != theTimeSlot.id)
        {
            if(theTimeSlot.fromMs >= mItems.at(i).fromMs && theTimeSlot.fromMs <= mItems.at(i).toMs)
            {
                mCollisionSide = false;
                return mItems.at(i).toMs;
            }
            else if(theTimeSlot.toMs >= mItems.at(i).fromMs && theTimeSlot.toMs <= mItems.at(i).toMs)
            {
                mCollisionSide = true;
                return mItems.at(i).fromMs - (theTimeSlot.toMs - theTimeSlot.fromMs);
            }

        }

    }
    return 0;
//    return false;
}
