#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "timeslotlist.h"
#include "timeslotmodel.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    qmlRegisterType<timeSlotModel>("TimeLine", 1, 0, "TimeSlotModel");
    qmlRegisterUncreatableType<timeSlotList>("TimeLine", 1, 0, "TimeSlotList",
        QStringLiteral("ToDoList should not be created in QML"));

    timeSlotList testList;



    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

     engine.rootContext()->setContextProperty(QStringLiteral("testList"),&testList);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
