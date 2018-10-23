#ifndef MUSICPRESENTERLIST_H
#define MUSICPRESENTERLIST_H

#include <QObject>
#include <QVector>

struct MusicPresenterItem{
    quint32 id;
    quint8 group;
    bool ValveOnOff;
    bool LedOnOff;
    bool Inverter;
    QString LedColor;
    quint8 InverterLevel;
    quint8 LedChannels;
    quint8 ValveChannels;
    int XPos;
    int YPos;
    bool odd;
};


class MusicPresenterList: public QObject
{
    Q_OBJECT

    QVector<MusicPresenterItem> mItems;
    quint32 mCurrentIndex;

public:
    explicit MusicPresenterList(QObject *parent = nullptr);
    ~MusicPresenterList();

    QVector<MusicPresenterItem> items() const;
    bool setItemAt(int index, const MusicPresenterItem &item);

signals:
    void preItemAppended();
    void postItemAppended();

    void preItemRemoved(int index);
    void postItemRemoved();

public slots:

    void appendItem(const quint8 &group, int xPos, int yPos);
    void appenItemGroup6(bool odd, int xPos, int yPos);
    void removeItems(const quint32 &id);
    void clear();
};

#endif // MUSICPRESENTERLIST_H
