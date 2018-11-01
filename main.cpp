#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "timeslotlist.h"
#include "timeslotmodel.h"
#include "musicpresenterlist.h"
#include "musicpresentermodel.h"
#include "presenterframelist.h"
#include "theinterfacegod.h"

#include <QThread>
#include <QVector>



int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    qmlRegisterType<timeSlotModel>("TimeLine", 1, 0, "TimeSlotModel");
    qmlRegisterUncreatableType<timeSlotList>("TimeLine", 1, 0, "TimeSlotList",
                                             QStringLiteral("ToDoList should not be created in QML"));

    qmlRegisterType<MusicPresenterModel>("MusicPresenter", 1, 0, "MusicPresenterModel");
    qmlRegisterUncreatableType<MusicPresenterList>("MusicPresenter", 1, 0, "MusicPresenterList",
                                                   QStringLiteral("ToDoList should not be created in QML"));


    timeSlotList dataList[9];
    MusicPresenterList presenterList[9];
    PresenterFrameList presenterFrameLists[9];
    theInterfaceGod theGod;

    QThread backendThread;


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


    backendThread.start();



    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
