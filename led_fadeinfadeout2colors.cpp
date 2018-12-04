#include "led_fadeinfadeout2colors.h"
#include "QDebug"

LED_FadeInFadeOut2Colors::LED_FadeInFadeOut2Colors(): mSpeed(-1)
{

}


bool LED_FadeInFadeOut2Colors::setSpeed(const int &speed)
{
    if(mSpeed != speed)
    {
        mSpeed = speed;

        dataWithSpeed.clear();


        for(int i = 0; i < data.count();i++)
        {
            if(mSpeed >= 0)
            {
                for( int ii = 50; ii >= mSpeed; ii--)
                {
                    dataWithSpeed.append(data.at(i));
                }
            }
            else
            {

                for(int ii = 0; ii < 50 - mSpeed; ii++)
                {
                    dataWithSpeed.append(data.at(i));
                }
            }
        }

        qDebug() << "LED SIZE: " + QString::number(dataWithSpeed.count())
                 << "Raw Led size: " + QString::number(data.count());
        return true;
    }

    return false;
}

bool LED_FadeInFadeOut2Colors::setEffects(const QColor &Headcolor, const QColor &TailColor)
{


//    theColor.toHsl();

    int hueHead,  saturationHead, lightnessHead;
    int hueTail, saturationTail, lightnessTail;


    Headcolor.getHsl(&hueHead, &saturationHead,&lightnessHead);
    TailColor.getHsl(&hueTail,&saturationTail,&lightnessTail);

    int hueStep = (hueHead - hueTail) / 256;
    int lightstep = (lightnessHead - lightnessTail) /256;
    int saturationStep = (saturationHead - saturationTail) /256;

    if(Headcolor != mColorHead || TailColor != mColorTail )
    {
        mColorHead = Headcolor;
        mColorTail = TailColor;

        data.clear();

//        qDebug() << "hue ah hihi: " + QString::number(hue);

        QColor dmColor = Headcolor;
         for(int i = 0; i < 256; i++)
         {

             dmColor.setHsl(static_cast<quint8>(hueHead + (hueStep * i)),static_cast<quint8>(saturationHead +(saturationStep * i)), static_cast<quint8>(lightnessHead + (lightstep*i)));

             data.append(dmColor);
//             qDebug() << "Color at i: " + theColor.name();
         }

         setSpeed(5);
        return true;
    }


    return false;
}


QColor LED_FadeInFadeOut2Colors::getData(const int &index)
{

//     mEffectBytesWithSpeed.at(index %(mEffectBytesWithSpeed.count() -1))

    return  data[index %(data.count()-1)];
}
