/*
 *LUCA BRODO, 3rd semester, Electronic Engineering, HSHL.
 *
 *
 * GUI able to commends a small rc car and that obtains information from it.
 * The ideal setup will be a raspberry pi connected to an Arduino via usb and connected to this PC using TCP standards under the same wifi.
 *
 *
 */


#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QImage>
#include <QtGui>
#include <QLabel>
#include <QQuickImageProvider>

#include "backend.h"
#include "localserver.h"
#include "thread.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

//This program needs opencv to be installed. In case it's not, please comment this line out and just use it normally. The only problem which
//will be encountered is with the switch "CAMERA". It cant be used and the whole app will crash.
//#include <opencv2/opencv.hpp>







int main(int argc, char *argv[])
{

    QGuiApplication a(argc, argv);
    QQmlApplicationEngine engine;

    qmlRegisterType<backend>("com.company.backendfirst", 1, 0, "BackEnd");
    //creation of object from the QT class thread
    thread mythread;
    //setting up the engine that is behind the main interface in two steps. First, setting the context property.
    //Usually, instead of "mythread.back", one can find the object from the class backend.
    //In this specific case, mythread (so the object from the class thread) is used. This allows the thread to be created and
    //possible to use. Plus, the whole interface can be modified.
    engine.rootContext()->setContextProperty("backend",mythread.back);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    //start the thread
    mythread.start();

    return a.exec();
}
