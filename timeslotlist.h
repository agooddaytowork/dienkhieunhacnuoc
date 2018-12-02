#ifndef TIMESLOTLIST_H
#define TIMESLOTLIST_H

#include <QObject>
#include <QVector>
#include <QModelIndex>

struct timeSlotItem{
    //        Q_GADGET
    int id;
    int fromMs;
    int toMs;
    quint8 group;
    bool ValveOnOff;
    bool LedOnOff;
    bool Inverter;
    quint8 LedMode;
    quint8 InverterLevel;
    QString fileBinPath;
    QString LedValuesList;
    quint8 LedChannels;
    quint8 ValveChannels;
    quint8 ValveMode;
    QString ValveModeName;
    QString LedModeName;
    int ValveSpeed;
    int LedSpeed;
    QModelIndex modelIndex;
};


class timeSlotList : public QObject
{
    Q_OBJECT

    QVector<timeSlotItem> mItems;
    int mCurrentIndex;
    bool mCollisionSide;

    timeSlotItem getTimeSlotItem(const int &id);

public:
    int mGroup;
    explicit timeSlotList(QObject *parent = nullptr);
    QVector<timeSlotItem> items() const;
    bool setItemAt(int index, const timeSlotItem &item);
    Q_INVOKABLE int timeSlotCollisionCheck(const int &id);
    Q_INVOKABLE bool getCollisionSide();
    Q_INVOKABLE int count();
    Q_INVOKABLE int lastIndex() const;

    void getTimeSlotList();


    ~timeSlotList();

signals:
    void preItemAppended();
    void postItemAppended();

    void preItemRemoved(int index);
    void postItemRemoved();
    void timeSlotItemChanged(const timeSlotItem &item);
    void timeSlotItemRemoved(const timeSlotItem &item);
    void gui_timeSLotItemChanged();

    void SIG_returnTimeSlotList(const int &group, const QVector<timeSlotItem> &list );

    void SIG_NotifyListChanged();

public slots:

    void appendItem(const quint8 &group,const int &fromMs, const int &toMs);
    void removeItems(const int &id);
    void timeSlotListImportedHandler(const int &group, const QVector<timeSlotItem> &list);
    void clearTimeSlotList();

};


#endif // TIMESLOTLIST_H
