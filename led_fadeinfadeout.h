#ifndef LED_FADEINFADEOUT_H
#define LED_FADEINFADEOUT_H

#include <QByteArray>
#include <QColor>
#include <QVector>


class LED_FadeInFadeOut
{

    int mSpeed;
    QColor mColor;
    QVector<QColor> data;
    QVector<QColor> dataWithSpeed;

public:
    LED_FadeInFadeOut();
    bool setSpeed(const int &speed);
    bool setEffects(const QColor &color);

    QColor getData(const int &index) ;
};

#endif // LED_FADEINFADEOUT_H
