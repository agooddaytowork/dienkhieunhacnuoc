#include "musicpresenterlist.h"

MusicPresenterList::MusicPresenterList(QObject *parent): QObject(parent), mCurrentIndex(0), mGroup(0)
{

}

MusicPresenterList::~MusicPresenterList()
{

}



QVector<MusicPresenterItem> MusicPresenterList::items() const
{
    return mItems;
}


bool MusicPresenterList::setItemAt(int index, const MusicPresenterItem &item)
{
    if (index < 0 || index >= mItems.size())
        return false;

    mItems[index] = item;
    return true;
}

void MusicPresenterList::appenItemGroup6(bool odd, int xPos, int yPos)
{
    emit preItemAppended();

    MusicPresenterItem item;

    item.id = mCurrentIndex;
    item.group = 5;
    item.ValveOnOff = false;
    item.LedOnOff = false;
    item.LedColor = "grey";
    item.InverterLevel = 0;
    item.XPos = xPos;
    item.YPos = yPos;
    item.LedChannels = 12;
    item.Inverter = true;
    item.ValveChannels = 2;
    item.odd = odd;


    mItems.append(item);
    mCurrentIndex++;

    emit postItemAppended();
}

void MusicPresenterList::clear()
{
    for (int i = 0; i < mItems.size(); ) {
        emit preItemRemoved(i);

        mItems.removeAt(i);

        emit postItemRemoved();


    }
}

void MusicPresenterList::appendItem(const quint8 &group, int xPos, int yPos)
{
    emit preItemAppended();

    if(mGroup != group)
    {
        mGroup = group;
    }

    MusicPresenterItem item;

    item.id = mCurrentIndex;
    item.group = group;
    item.ValveOnOff = false;
    item.LedOnOff = false;
    item.LedColor = "grey";
    item.InverterLevel = 0;
    item.XPos = xPos;
    item.YPos = yPos;
    item.odd = false;
    item.Inverter = false;


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
        if(mCurrentIndex%2 == 0)
        {
            item.odd = false;
        }
        else
        {
            item.odd = true;
        }
        break;
    case 7:
        item.LedChannels = 8;
        item.ValveChannels = 8;
        break;
    case 8:
        item.LedChannels = 2;
        item.ValveChannels = 2;
        if(mCurrentIndex <=7)
        {
            item.odd = false;
        }
        else
        {
            item.odd = true;
        }
        break;
    }
    mItems.append(item);
    mCurrentIndex++;

    emit postItemAppended();
}


void MusicPresenterList::removeItems(const int &id)
{

    for (int i = 0; i < mItems.size(); ) {
        if (mItems.at(i).id == id) {
            emit preItemRemoved(i);

            mItems.removeAt(i);

            emit postItemRemoved();

            return;
        } else {
            ++i;
        }
    }
}


void MusicPresenterList::frameChangedHandler(const PresenterFrame &frame)
{

    for(int ii = 0; ii < mItems.count();ii++)
    {
        MusicPresenterItem theItem = mItems.at(ii);

        theItem.LedOnOff = frame.LedOnOff.at(0);
        theItem.InverterLevel = frame.InverterLevel;
        if(theItem.group == 1 || theItem.group ==7 || theItem.group == 2)
        {
            theItem.ValveOnOff = frame.ValveOnOff.at(ii);
        }
        else if(theItem.group == 6 || theItem.group == 8)
        {
            if(theItem.odd)
            {
                theItem.ValveOnOff = frame.ValveOnOff.at(0);
            }
            else
            {
                theItem.ValveOnOff = frame.ValveOnOff.at(1);
            }
        }
        else if(theItem.group == 4)
        {
            theItem.ValveOnOff = frame.ValveOnOff.at(0);
        }
        else if(theItem.group ==5)
        {
            if(theItem.odd == true)
            {
                theItem.InverterLevel = frame.InverterLevel;
            }
            else if(theItem.odd == false)
            {
                theItem.InverterLevel = frame.InverterLevel1;
            }
        }
        else
        {
            theItem.ValveOnOff = frame.ValveOnOff.at(0);
        }

        theItem.LedColor = frame.LedColors.at(0);

        mItems[ii] = theItem;

    }

    emit itemChangedFromBackend();




}
