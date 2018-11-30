#ifndef SERIALFRAMEBUFFER_H
#define SERIALFRAMEBUFFER_H

#include <QByteArray>
#include <QObject>
#include <QVector>
#include "presenterframelist.h"

struct SingleSerialFrame{
    char start = 0x02;
    char opcode = 0x03;
    char length = 68;
    char V_CH1_I = 0x00;
    char V_CH2_T = 0x00;
    char V_CH3_T_L = 0x00;
    char V_CH3_T_H = 0x00;
    char V_CH4_I = 0x00;
    char V_CH5_CH7_CH9_T = 0x00; // CH5 bit 0; CH7 bit 1&2; CH9 bit 3&4
    char V_CH6_I_0 = 0x00;
    char V_CH6_I_1 = 0x00;
    char V_CH8_T = 0x00;
    char extraByte_0 = 0x00;
    char L_CH1[3] ={0x00,  0x00,  0x00};
    char L_CH2[3] ={0x00,  0x00,  0x00};
    char L_CH3[3] ={0x00,  0x00,  0x00};
    char L_CH4[3] ={0x00,  0x00,  0x00};
    char L_CH5[3] ={0x00,  0x00,  0x00};
    char L_CH6_L[3] ={0x00,  0x00,  0x00};
    char L_CH6_H[3] ={0x00,  0x00,  0x00};
    char L_CH7_L[3] ={0x00,  0x00,  0x00};
    char L_CH7_H[3] ={0x00,  0x00,  0x00};
    char L_CH8_0[3] ={0x00,  0x00,  0x00};
    char L_CH8_1[3] ={0x00,  0x00,  0x00};
    char L_CH8_2[3] ={0x00,  0x00,  0x00};
    char L_CH8_3[3] ={0x00,  0x00,  0x00};
    char L_CH8_4[3] ={0x00,  0x00,  0x00};
    char L_CH8_5[3] ={0x00,  0x00,  0x00};
    char L_CH8_6[3] ={0x00,  0x00,  0x00};
    char L_CH8_7[3] ={0x00,  0x00,  0x00};
    char L_CH9_L[3] ={0x00,  0x00,  0x00};
    char L_CH9_H[3] ={0x00,  0x00,  0x00};
    char extraByte_1 = 0x00;
    char checkSumLowByte;
    char checkSumHighByte;
    char stop = 0x03;
};

class SerialFrameBuffer: public QObject
{

    Q_OBJECT

    QVector<SingleSerialFrame> mData;

public:
    SerialFrameBuffer(QObject * parent = nullptr);


public slots:
    void SerialFrameChangedHandler(const int &group, const PresenterFrame &theFrame);
    void regenerateFrameList(const int &numberOfFrame);
    void playSerialFrame (const int &frameNo);

};

#endif // SERIALFRAMEBUFFER_H
