#include "musicpresentermodel.h"

MusicPresenterModel::MusicPresenterModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

int MusicPresenterModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid())
        return 0;

    // FIXME: Implement me!
}

QVariant MusicPresenterModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}


QHash<int, QByteArray> MusicPresenterModel::roleNames() const
{
    QHash<int, QByteArray> names;

    names[IDRole] = "theId";
    names[ValveOnOffRole] = "ValveOnOff";
    names[LedOnOffRole] ="LedOnOff";
    names[InverterRole] = "Inverter";
    names[InverterLevelRole] = "InverterLevel";
    names[LEDChannelsRole] = "LEDChannels";
    names[ValveChannelsRole] = "ValveChannels";
    names[LedColorRole] = "LEDColor";
    names[GroupRole] = "Group";


    return names;

}

