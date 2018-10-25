#ifndef THEINTERFACEGOD_H
#define THEINTERFACEGOD_H

#include <QObject>

class theInterfaceGod : public QObject
{
    Q_OBJECT
public:
    explicit theInterfaceGod(QObject *parent = nullptr);

    Q_INVOKABLE void regenerateFrameList(const int &duration, const int &frameDuration);
    Q_INVOKABLE void playFrame(const int &frameNo);

signals:
    void SIG_regenerateFrameList(const int &duration, const int &frameDuration);
    void SIG_playFrame(const int &frameNo);

public slots:
};

#endif // THEINTERFACEGOD_H
