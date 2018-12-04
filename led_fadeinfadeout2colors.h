#ifndef LED_FADEINFADEOUT2COLORS_H
#define LED_FADEINFADEOUT2COLORS_H

#include <QByteArray>
#include <QColor>
#include <QVector>
#include <QList>

class LED_FadeInFadeOut2Colors
{
    int mSpeed;
    QColor mColorHead, mColorTail;
    QList<QColor> data;
    QList<QColor> dataWithSpeed;

public:
    LED_FadeInFadeOut2Colors();
    bool setSpeed(const int &speed);
    bool setEffects(const QColor &Headcolor, const QColor &TailColor);

    QColor getData(const int &index) ;
};

#endif // LED_FADEINFADEOUT2COLORS_H
