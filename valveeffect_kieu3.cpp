#include "valveeffect_kieu3.h"

ValveEffect_Kieu3::ValveEffect_Kieu3(): mEffectValid(false), mSpeed(0)
{

}


bool ValveEffect_Kieu3::setNewPath(QString filePath)
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

bool ValveEffect_Kieu3::setSpeed( const int &theSpeed)
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
                    mEffectBytesWithSpeed.append(mEffectBytes[(i * 2)% (mEffectBytes.count())]);
                    mEffectBytesWithSpeed.append(mEffectBytes[((i *2) + 1)%(mEffectBytes.count())]);
                }
            }
            else
            {

                for(int ii = 0; ii < 50 - mSpeed; ii++)
                {
                    mEffectBytesWithSpeed.append(mEffectBytes[(i * 2)% (mEffectBytes.count())]);
                    mEffectBytesWithSpeed.append(mEffectBytes[((i *2) + 1)%(mEffectBytes.count())]);
                }
            }
        }

        return true;
    }

    return false;
}

bool ValveEffect_Kieu3::getData(const int &index, const int &order)
{

    quint8 theValueLow = static_cast<quint8>( mEffectBytesWithSpeed.at(index*2 %(mEffectBytesWithSpeed.count())));
     quint8 theValueHigh = static_cast<quint8>( mEffectBytesWithSpeed.at((index*2 +1) %(mEffectBytesWithSpeed.count())));

     if(order <=7)
     {
         if(theValueLow & (1 << static_cast<quint8>(order)))
         {
             return true;
         }
     }
     else
     {
         if(theValueHigh & (1 << static_cast<quint8>(order - 8)))
         {
             return true;
         }
     }

        return false;

}

bool ValveEffect_Kieu3::isEffectValid()
{
    return mEffectValid;
}

