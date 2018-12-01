#ifndef THEINTERFACEGOD_H
#define THEINTERFACEGOD_H

#include <QObject>
#include <QtSerialPort/QSerialPortInfo>
#include <QMessageBox>


class theInterfaceGod : public QObject
{
    Q_OBJECT

    QList<QSerialPortInfo> mSerialPortInfoList;
    int mSerialPortCount;
public:
    explicit theInterfaceGod(QObject *parent = nullptr);

    Q_INVOKABLE void regenerateFrameList(const int &duration, const int &frameDuration);
    Q_INVOKABLE void playFrame(const int &frameNo);
    Q_INVOKABLE QString getSerialPortNames(const int &index);
    Q_INVOKABLE int getSerialPortCount();
    Q_INVOKABLE void refreshSerialPorts();
    Q_INVOKABLE void connectSerialPort(const QString &portName);
    Q_INVOKABLE void disconnectSerialPort();
    Q_INVOKABLE void closeThreads();
    Q_INVOKABLE void enableSerialOutput(const bool &enable);

    void closeApplication();
    void reportError(const QString &title, const QString &content);
    void reportInformation(const QString &title, const QString &content);
    void serialPortConnectionStatus(const bool &status);


signals:
    void SIG_regenerateFrameList(const int &duration, const int &frameDuration);
    void SIG_playFrame(const int &frameNo);
    void gui_timeSLotChanged();
    void SIG_connectSerialPort(const QString &portName);
    void SIG_disconnectSerialPort();
    void SIG_CloseThreads();
    void gui_CloseApplication();
    void gui_SerialPortConnection(const bool &isConnected);
    void SIG_enableSerialOutput(const bool &enable);


public slots:
     void invokeTimeSlotChanged();
};

#endif // THEINTERFACEGOD_H
