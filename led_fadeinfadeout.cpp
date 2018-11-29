#include "led_fadeinfadeout.h"
#include "QDebug"
LED_FadeInFadeOut::LED_FadeInFadeOut(): mSpeed(-1)
{

}


bool LED_FadeInFadeOut::setSpeed(const int &speed)
{
    if(mSpeed != speed)
    {
        mSpeed = speed;

        dataWithSpeed.clear();

        for(int i = 0; i < data.count();i++)
        {
            if(mSpeed >= 0)
            {
                for( int ii = 10; ii >= mSpeed; ii--)
                {
                    dataWithSpeed.append(data.at(i));
                }
            }
            else
            {

                for(int ii = 0; ii < 10 - mSpeed; ii++)
                {
                    dataWithSpeed.append(data.at(i));
                }
            }
        }

        return true;
    }

    return false;
}

bool LED_FadeInFadeOut::setEffects(const QColor &color)
{


//    theColor.toHsl();

    int hue;
    int saturation;
    int lightness;

    color.getHsl(&hue, &saturation,&lightness);

    if(color != mColor )
    {
        mColor = color;

        data.clear();

        qDebug() << " THE FUCKING COLOR: " + QString::number(color.red()) +" " +QString::number(color.green())+" " +QString::number(color.blue());

//        qDebug() << "hue ah hihi: " + QString::number(hue);

        QColor dmColor = color;
         for(int i = 0; i < 256; i++)
         {

            dmColor.setHsl(hue,saturation,i);
             data.append(dmColor);
//             qDebug() << "Color at i: " + theColor.name();
         }

         for(int i = 255; i >=0; i=i-2)
         {
           dmColor.setHsl(hue,saturation,i);
             data.append(dmColor);
//             qDebug() << "Color at i: " + theColor.name();
         }

         setSpeed(10);
        return true;
    }


    return false;
}


QColor LED_FadeInFadeOut::getData(const int &index)
{

//     mEffectBytesWithSpeed.at(index %(mEffectBytesWithSpeed.count() -1))

    return  data[index %(data.count()-1)];
}
