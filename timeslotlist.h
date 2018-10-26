#ifndef TIMESLOTLIST_H
#define TIMESLOTLIST_H

#include <QObject>
#include <QVector>

struct timeSlotItem{
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
};

class timeSlotList : public QObject
{
    Q_OBJECT

    QVector<timeSlotItem> mItems;
    int mCurrentIndex;
    bool mCollisionSide;

    timeSlotItem getTimeSlotItem(const int &id);

public:
    explicit timeSlotList(QObject *parent = nullptr);
    QVector<timeSlotItem> items() const;
    bool setItemAt(int index, const timeSlotItem &item);
    Q_INVOKABLE int timeSlotCollisionCheck(const int &id);
    Q_INVOKABLE bool getCollisionSide();

    ~timeSlotList();

signals:
    void preItemAppended();
    void postItemAppended();

    void preItemRemoved(int index);
    void postItemRemoved();
    void timeSlotItemChanged(const timeSlotItem &item);
    void timeSlotItemRemoved(const timeSlotItem &item);
public slots:

    void appendItem(const quint8 &group,const int &fromMs, const int &toMs);
    void removeItems(const int &id);

};

#endif // TIMESLOTLIST_H
