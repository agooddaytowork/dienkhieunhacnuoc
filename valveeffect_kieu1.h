#ifndef VALVEEFFECT_KIEU1_H
#define VALVEEFFECT_KIEU1_H

#include <QFile>
#include <QVector>
class ValveEffect_Kieu1 // INVERTER - Kieu 1, 4
{
    bool mEffectValid;
    QString mFilePath;
    QByteArray mEffectBytes;
    QByteArray mEffectBytesWithSpeed;
    int mSpeed;
public:
    ValveEffect_Kieu1();
    bool setNewPath( QString filePath);
    bool isEffectValid();
    bool setSpeed(const int &speed);
    quint8 getData(const int &index);

};

#endif // VALVEEFFECT_KIEU1_H