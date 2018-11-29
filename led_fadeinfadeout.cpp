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
                    dataWithSpeed.append(data[i]);
                }
            }
            else
            {

                for(int ii = 0; ii < 10 - mSpeed; ii++)
                {
                    dataWithSpeed.append(data[i]);
                }
            }
        }

        return true;
    }

    return false;
}

bool LED_FadeInFadeOut::setEffects(const QColor &color)
{


    if(color != mColor )
    {
        mColor = color;

        data.clear();

        qDebug() << " THE FUCKING COLOR: " + QString::number(color.red()) +" " +QString::number(color.green())+" " +QString::number(color.blue());

        int theRed = color.red();
        int theGreen = color.green();
        int theBlue = color.blue();
        int red, green,blue;
         for(int i = 0; i < 256; i++)
         {

             red = theRed -i;
             green = theGreen - i;
             blue =theBlue - i;

            qDebug()<< "Red - Green - Blue::: " + QString::number(red) +"-"+ QString::number(green) +"-"+ QString::number(blue) ;

             QColor theColor(red,green,blue,250);
             data.append(theColor);
             qDebug() << "Color at i: " + theColor.name();
         }

         setSpeed(0);
        return true;
    }

    return false;
}


QColor LED_FadeInFadeOut::getData(const int &index)
{

//     mEffectBytesWithSpeed.at(index %(mEffectBytesWithSpeed.count() -1))

    return  dataWithSpeed[index %(dataWithSpeed.count()-1)];
}
