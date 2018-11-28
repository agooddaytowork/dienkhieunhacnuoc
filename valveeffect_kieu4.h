#ifndef VALVEEFFECT_KIEU4_H
#define VALVEEFFECT_KIEU4_H
#include <QFile>
#include <QString>
#include <QByteArray>
#include <QList>
#include <QBitArray>

class ValveEffect_Kieu4 // Kieu 3
{    bool mEffectValid;
     QString mFilePath;
     QByteArray mEffectBytes;
     QByteArray mEffectBytesWithSpeed;
     int mSpeed;
 public:
     ValveEffect_Kieu4();
     bool setNewPath( QString filePath);
     bool isEffectValid();
     bool setSpeed(const int &speed);
     bool getData(const int &index, const bool &odd);
};

#endif // VALVEEFFECT_KIEU4_H
