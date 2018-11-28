#include "valveeffect_kieu2.h"

ValveEffect_Kieu2::ValveEffect_Kieu2(): mEffectValid(false), mSpeed(0)
{

}


bool ValveEffect_Kieu2::setNewPath(QString filePath)
{
    if(mFilePath != filePath)
    {
        mFilePath = filePath;
        QFile file(mFilePath);
        if(file.open(QIODevice::ReadOnly ))
        {
            mEffectValid = true;

            mEffectBytes = file.readAll();
            for(int i = 0; i < mEffectBytes.count();i++)
            {

                for( int ii = 10; ii >= 0; ii--)
                {
                    mEffectBytesWithSpeed.append(mEffectBytes[i]);
                }
            }

            return true;
        }
        else
        {
            mEffectValid = false;
        }
    }
    return false;
}

bool ValveEffect_Kieu2::setSpeed( const int &theSpeed)
{
    if(mSpeed != theSpeed)
    {
        mSpeed = theSpeed;

        mEffectBytesWithSpeed.clear();

        for(int i = 0; i < mEffectBytes.count();i++)
        {
            if(mSpeed >= 0)
            {
                for( int ii = 10; ii >= mSpeed; ii--)
                {
                    mEffectBytesWithSpeed.append(mEffectBytes[i]);
                }
            }
            else
            {

                for(int ii = 0; ii < 10 - mSpeed; ii++)
                {
                    mEffectBytesWithSpeed.append(mEffectBytes[i]);
                }
            }
        }

        return true;

    }

    return false;
}

bool ValveEffect_Kieu2::getData(const int &index, const int &order)
{

    quint8 theValue = static_cast<quint8>( mEffectBytesWithSpeed.at(index %(mEffectBytesWithSpeed.count() -1)));

    if(theValue & (1 << static_cast<quint8>(order)))
    {
        return true;
    }
        return false;

}

bool ValveEffect_Kieu2::isEffectValid()
{
    return mEffectValid;
}

