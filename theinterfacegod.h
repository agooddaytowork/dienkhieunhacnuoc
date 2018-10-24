#ifndef THEINTERFACEGOD_H
#define THEINTERFACEGOD_H

#include <QObject>

class theInterfaceGod : public QObject
{
    Q_OBJECT
public:
    explicit theInterfaceGod(QObject *parent = nullptr);

    Q_INVOKABLE void regenerateFrameList(const quint32 &duration, const quint32 &frameDuration);

signals:
    void SIG_regenerateFrameList(const quint32 &duration, const quint32 &frameDuration);

public slots:
};

#endif // THEINTERFACEGOD_H
