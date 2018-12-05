#include "valveeffect_kieu1.h"
#include <QDebug>
ValveEffect_Kieu1::ValveEffect_Kieu1(): mEffectValid(false), mSpeed(0), mForceRepeat(false), mRepeatTime(0), mFrameNo(0)
{


}

bool ValveEffect_Kieu1::setNewPath(QString filePath)
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

bool ValveEffect_Kieu1::isEffectValid()
{
    return mEffectValid;
}

bool ValveEffect_Kieu1::setForceRepeat(const int &repeatTime)
{

    if(!mForceRepeat || repeatTime != mRepeatTime)
    {
        mForceRepeat = true;
        mRepeatTime = repeatTime;

        mEffectBytesWithSpeed.clear();

        for(int i =0; i < repeatTime;i++)
        {
            mEffectBytesWithSpeed.append(mEffectBytes);
        }

        qDebug() << "effectByte with speed size: " + QString::number(mEffectBytesWithSpeed.size());

        return true;
    }


    return false;
}



bool ValveEffect_Kieu1::setSpeed( const int &theSpeed)
{
    if(mSpeed != theSpeed || mForceRepeat)
    {
        mSpeed = theSpeed;
        mForceRepeat = false;

        mEffectBytesWithSpeed.clear();

        for(int i = 0; i < mEffectBytes.count();i++)
        {
            if(mSpeed >= 0)
            {
                for( int ii = 50; ii >= mSpeed; ii--)
                {
                    mEffectBytesWithSpeed.append(mEffectBytes[i]);
                }
            }
            else
            {

                for(int ii = 0; ii < 50 - mSpeed; ii++)
                {
                    mEffectBytesWithSpeed.append(mEffectBytes[i]);
                }
            }
        }

        return true;

    }

    return false;
}
quint8 ValveEffect_Kieu1::getData(const int &index)
{

    return static_cast<quint8>( mEffectBytesWithSpeed.at(index %(mEffectBytesWithSpeed.count())));
}
