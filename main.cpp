#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "drawermodel.h"
#include "calculatermodel.h"


int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.addImportPath(":/qml");

    qmlRegisterType<DrawerModel>("DrawerModel", 1, 0, "DrawerModel");
    qmlRegisterType<CalculaterModel>("CalculaterModel", 1, 0, "CalculaterModel");

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
