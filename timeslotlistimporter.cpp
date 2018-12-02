#include "timeslotlistimporter.h"

TimeSlotListImporter::TimeSlotListImporter(QObject *parent) : QObject(parent)
{

}


bool TimeSlotListImporter::importFile(const QString &filePath)
{

    QFile file(filePath);

    if(file.open(QIODevice::ReadOnly))
    {
        QByteArray data = file.readAll();


        QJsonDocument theDocument;

        theDocument.fromBinaryData(data);

        if(!theDocument.isNull())
        {

           QJsonArray groupsArray = theDocument.array();

           for(int i = 0; i < groupsArray.count(); i++)
           {

               QJsonObject theGroup = groupsArray.at(i).toObject();

                if(theGroup.value("group").toInt() == 0)
                {
                    QJsonArray timeSlotsArray = theGroup.value("data").toArray();



                    for(int ii = 0; ii < timeSlotsArray.count(); ii++)
                    {
                        QJsonObject theJsonObject = timeSlotsArray.at(ii).toObject();


                        timeSlotItem theItem;

                        theItem.id = theJsonObject.value("id").toInt(0);
                        theItem.ValveOnOff = theJsonObject.value("ValveOnOff").toBool(false);
                        theItem.Inverter = theJsonObject.value("Inverter").toBool(false);
                        theItem.fromMs = theJsonObject.value("FromMs").toInt(0);
                        theItem.toMs = theJsonObject.value("ToMs").toInt(0);
                        theItem.LedMode = static_cast<quint8>(theJsonObject.value("LedMode").toInt(0));
                        theItem.InverterLevel = static_cast<quint8>(theJsonObject.value("InverterLevel").toInt(0)) ;
                        theItem.fileBinPath = mRootPath+"/"
                    }

                }


           }

            return true;
        }


    }

    return false;

}

void TimeSlotListImporter::setRoothPath(const QString &rootPath)
{
    mRootPath = rootPath;
}
