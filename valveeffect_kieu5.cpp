#include "valveeffect_kieu5.h"
#include <QtDebug>

ValveEffect_Kieu5::ValveEffect_Kieu5(): mEffectValid(false), mSpeed(0)
{


}

bool ValveEffect_Kieu5::setNewPath(QString filePath)
{
    if(mFilePath != filePath)
    {
        mFilePath = filePath;
        QFile file(mFilePath);
        if(file.open(QIODevice::ReadOnly ))
        {
            mEffectValid = true;

            mEffectBytes = file.readAll();

            setSpeed(50);

            return true;
        }
        else
        {
            mEffectValid = false;
        }
    }
    return false;
}

bool ValveEffect_Kieu5::isEffectValid()
{
    return mEffectValid;
}

bool ValveEffect_Kieu5::setSpeed( const int &theSpeed)
{
    if(mSpeed != theSpeed)
    {
        mSpeed = theSpeed;

        mEffectBytesWithSpeed.clear();

        for(int i = 0; i < mEffectBytes.count();i++)
        {
            if(mSpeed >= 0)
            {
                for( int ii = 50; ii >= mSpeed; ii--)
                {
                    mEffectBytesWithSpeed.append(mEffectBytes[(i*2 %(mEffectBytes.count()))]);
                    mEffectBytesWithSpeed.append(mEffectBytes[((i*2 +1) %(mEffectBytes.count()))]);
                }
            }
            else
            {

                for(int ii = 0; ii < 50 - mSpeed; ii++)
                {
                    mEffectBytesWithSpeed.append(mEffectBytes[(i*2 %(mEffectBytes.count()))]);
                    mEffectBytesWithSpeed.append(mEffectBytes[((i*2 +1) %(mEffectBytes.count()))]);
                }
            }
        }

        return true;

    }

    return false;
}
quint8 ValveEffect_Kieu5::getData(const int &index, const bool &odd)
{

//    qDebug() << "index: " + QString::number(index) + " odd: " + QString::number(odd);

    if(odd)
    {
        return  static_cast<quint8>( mEffectBytesWithSpeed.at(index*2 %(mEffectBytesWithSpeed.count())));
    }

    return static_cast<quint8>( mEffectBytesWithSpeed.at((index*2 +1) %(mEffectBytesWithSpeed.count())));

}
