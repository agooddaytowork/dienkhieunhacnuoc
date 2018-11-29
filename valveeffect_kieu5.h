#ifndef VALVEEFFECT_KIEU5_H
#define VALVEEFFECT_KIEU5_H


#include <QFile>
#include <QVector>
class ValveEffect_Kieu5 // INVERTER - Kieu 6
{
    bool mEffectValid;
    QString mFilePath;
    QByteArray mEffectBytes;
    QByteArray mEffectBytesWithSpeed;
    int mSpeed;
public:
    ValveEffect_Kieu5();
    bool setNewPath( QString filePath);
    bool isEffectValid();
    bool setSpeed(const int &speed);
    quint8 getData(const int &index, const bool &odd);

};

#endif // VALVEEFFECT_KIEU5_H
