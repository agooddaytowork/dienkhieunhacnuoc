#ifndef MUSICPRESENTERMODEL_H
#define MUSICPRESENTERMODEL_H

#include <QAbstractListModel>

class MusicPresenterModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit MusicPresenterModel(QObject *parent = nullptr);

    enum{
        IDRole = Qt::UserRole,
        GroupRole,
        ValveOnOffRole,
        LedOnOffRole,
        InverterRole,
        LedColorRole,
        InverterLevelRole,
        LEDChannelsRole,
        ValveChannelsRole

    };

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    virtual QHash<int, QByteArray> roleNames() const override;
private:

};

#endif // MUSICPRESENTERMODEL_H
