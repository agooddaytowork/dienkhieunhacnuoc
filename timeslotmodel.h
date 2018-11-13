#ifndef TIMESLOTMODEL_H
#define TIMESLOTMODEL_H

#include <QAbstractListModel>
#include "timeslotlist.h"

class timeSlotModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(timeSlotList *list READ list WRITE setList)

public:
    explicit timeSlotModel(QObject *parent = nullptr);

    enum {
        IDRole = Qt::UserRole,
        GroupRole,
        ValveOnOffRole,
        LedOnOffRole,
        InverterRole,
        FromMsRole,
        ToMsRole,
        LedModeRole,
        InverterLevelRole,
        FileBinPathRole,
        LEDValuesListRole,
        LEDChannelsRole,
        ValveChannelsRole,
        ValveModeRole

    };

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    virtual QHash<int, QByteArray> roleNames() const override;

    timeSlotList *list() const;
    void setList(timeSlotList *list);

private:

    timeSlotList *mList;
};

#endif // TIMESLOTMODEL_H
