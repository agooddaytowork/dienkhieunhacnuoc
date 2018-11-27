#ifndef VALVEEFFECT_KIEU1_H
#define VALVEEFFECT_KIEU1_H

#include <QFile>
#include <QVector>
class ValveEffect_Kieu1
{
    bool mEffectValid;
    QString mFilePath;
    QByteArray mEffectBytes;
public:
    ValveEffect_Kieu1(QString const &filePath);
    bool isEffectValid();
    quint8 getData(const int &index);

};

#endif // VALVEEFFECT_KIEU1_H
