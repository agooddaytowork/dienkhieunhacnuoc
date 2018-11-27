#include "valveeffect_kieu1.h"

ValveEffect_Kieu1::ValveEffect_Kieu1(QString const &filePath): mEffectValid(false), mFilePath(filePath)
{

    QFile file(mFilePath);
    if(file.open(QIODevice::ReadOnly ))
    {
        mEffectValid = true;

        mEffectBytes = file.readAll();
    }
}


bool ValveEffect_Kieu1::isEffectValid()
{
    return mEffectValid;
}

quint8 ValveEffect_Kieu1::getData(const int &index)
{
    if(index < mEffectBytes.count()-1)
    {
        return static_cast<quint8>(mEffectBytes.at(index));
    }
       return static_cast<quint8>( mEffectBytes.at(index %(mEffectBytes.count() -1)));
}
