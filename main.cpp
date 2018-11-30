#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "timeslotlist.h"
#include "timeslotmodel.h"
#include "musicpresenterlist.h"
#include "musicpresentermodel.h"
#include "presenterframelist.h"
#include "theinterfacegod.h"

#include "serialframebuffer.h"

#include <QThread>
#include <QVector>
#include <QDebug>



int main(int argc, char *argv[])
{
#if defined(Q_OS_WIN) || defined(Q_OS_ANDROID)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    qmlRegisterType<timeSlotModel>("TimeLine", 1, 0, "TimeSlotModel");
    qmlRegisterUncreatableType<timeSlotList>("TimeLine", 1, 0, "TimeSlotList",
                                             QStringLiteral("ToDoList should not be created in QML"));

    qmlRegisterType<MusicPresenterModel>("MusicPresenter", 1, 0, "MusicPresenterModel");
    qmlRegisterUncreatableType<MusicPresenterList>("MusicPresenter", 1, 0, "MusicPresenterList",
                                                   QStringLiteral("ToDoList should not be created in QML"));
    qRegisterMetaType<PresenterFrame>("PresenterFrame");


    SerialFrameBuffer theSerialFrameBuffer;


    timeSlotList dataList[9];
    MusicPresenterList presenterList[9];
    PresenterFrameList presenterFrameLists[9];
    theInterfaceGod theGod;

    QThread backendThread;
    QThread serialFrameThread;

    theSerialFrameBuffer.moveToThread(&serialFrameThread);


    QObject::connect(&presenterFrameLists[0], &PresenterFrameList::SIG_SerialFrameBuffer_regenerateFrameList, &theSerialFrameBuffer,&SerialFrameBuffer::regenerateFrameList);
    QObject::connect(&theGod, &theInterfaceGod::SIG_playFrame,&theSerialFrameBuffer, &SerialFrameBuffer::playSerialFrame);


    for(int i = 0; i < 9; i++)
    {
        dataList[i].mGroup = i;
        presenterFrameLists[i].mGroup = i;
        presenterList[i].mGroup = static_cast<quint8>(i);

        QObject::connect(&dataList[i],&timeSlotList::timeSlotItemChanged,&presenterFrameLists[i],&PresenterFrameList::timeSlotChanged);
        QObject::connect(&dataList[i],&timeSlotList::timeSlotItemRemoved,&presenterFrameLists[i],&PresenterFrameList::timeSlotRemoved);
        QObject::connect(&theGod,&theInterfaceGod::SIG_regenerateFrameList,&presenterFrameLists[i],&PresenterFrameList::regenerateFrameList);
        QObject::connect(&theGod,&theInterfaceGod::SIG_playFrame, &presenterFrameLists[i],&PresenterFrameList::playFrame);
        QObject::connect(&presenterFrameLists[i],&PresenterFrameList::notifyFrameChanged,&presenterList[i],&MusicPresenterList::frameChangedHandler);

        QObject::connect(&dataList[i],&timeSlotList::gui_timeSLotItemChanged,&theGod,&theInterfaceGod::invokeTimeSlotChanged);

        QObject::connect(&presenterFrameLists[i],&PresenterFrameList::SIG_SerialFrameBuffer_notifyFrameChanged,&theSerialFrameBuffer,&SerialFrameBuffer::SerialFrameChangedHandler);


        dataList[i].moveToThread(&backendThread);

    }




    QGuiApplication app(argc, argv);



    QQmlApplicationEngine engine;

    for (int i = 0; i < 9; i++)
    {
        engine.rootContext()->setContextProperty("timeSlotList_" + QString::number(i) ,&dataList[i]);
        engine.rootContext()->setContextProperty("presenterList_" + QString::number(i) ,&presenterList[i]);
    }
    engine.rootContext()->setContextProperty("theInterfaceGod", &theGod);

    engine.rootContext()->setContextProperty("appFilePath",QCoreApplication::applicationDirPath());
    qDebug() << "AppfilePath: " + QCoreApplication::applicationDirPath();



    serialFrameThread.start(); // serialFrameThread must start before backendThread
    backendThread.start();



    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
