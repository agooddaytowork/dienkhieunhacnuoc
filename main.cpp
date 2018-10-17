#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "timeslotlist.h"
#include "timeslotmodel.h"
#include <QVector>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    qmlRegisterType<timeSlotModel>("TimeLine", 1, 0, "TimeSlotModel");
    qmlRegisterUncreatableType<timeSlotList>("TimeLine", 1, 0, "TimeSlotList",
                                             QStringLiteral("ToDoList should not be created in QML"));


    timeSlotList group0_list;
    timeSlotList group1_list;
    timeSlotList group2_list;
    timeSlotList group3_list;
    timeSlotList group4_list;
    timeSlotList group5_list;
    timeSlotList group6_list;
    timeSlotList group7_list;
    timeSlotList group8_list;




    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;


    engine.rootContext()->setContextProperty("timeSlotList_0" ,&group0_list);
    engine.rootContext()->setContextProperty("timeSlotList_1" ,&group1_list);
    engine.rootContext()->setContextProperty("timeSlotList_2" ,&group2_list);
    engine.rootContext()->setContextProperty("timeSlotList_3" ,&group3_list);
    engine.rootContext()->setContextProperty("timeSlotList_4" ,&group4_list);
    engine.rootContext()->setContextProperty("timeSlotList_5" ,&group5_list);
    engine.rootContext()->setContextProperty("timeSlotList_6" ,&group6_list);
    engine.rootContext()->setContextProperty("timeSlotList_7" ,&group7_list);
    engine.rootContext()->setContextProperty("timeSlotList_8" ,&group8_list);



    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
