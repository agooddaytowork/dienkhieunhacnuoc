#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "timeslotlist.h"
#include "timeslotmodel.h"
#include "musicpresenterlist.h"
#include "musicpresentermodel.h"
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




    QGuiApplication app(argc, argv);



    QQmlApplicationEngine engine;

    for (int i = 0; i < 9; i++)
    {
        engine.rootContext()->setContextProperty("timeSlotList_" + QString::number(i) ,&dataList[i]);
        engine.rootContext()->setContextProperty("presenterList_" + QString::number(i) ,&presenterList[i]);
    }

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
