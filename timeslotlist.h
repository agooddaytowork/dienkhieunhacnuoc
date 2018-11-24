#ifndef TIMESLOTLIST_H
#define TIMESLOTLIST_H

#include <QObject>
#include <QVector>

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

//    Q_PROPERTY(int m_id MEMBER id)
//    Q_PROPERTY(int m_fromMs MEMBER fromMs)
//    Q_PROPERTY(int m_toMs MEMBER toMs)
//    Q_PROPERTY(quint8 m_group MEMBER group)
//    Q_PROPERTY(bool m_ValveOnOff MEMBER ValveOnOff)
//    Q_PROPERTY(bool m_LedOnOff MEMBER LedOnOff)
//    Q_PROPERTY(quint8 m_LedMode MEMBER LedMode)
//    Q_PROPERTY(quint8 m_InverterLevel MEMBER InverterLevel)
//    Q_PROPERTY(QString m_fileBinPath MEMBER fileBinPath)
//    Q_PROPERTY(QString m_LedValuesList MEMBER LedValuesList)
//    Q_PROPERTY(quint8 m_LedChannels MEMBER LedChannels)
//    Q_PROPERTY(quint8 m_ValveChannels MEMBER ValveChannels)
//    Q_PROPERTY(quint8 m_ValveMode MEMBER ValveMode)
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
