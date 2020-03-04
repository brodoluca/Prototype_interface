#ifndef LOCALSERVER_H
#define LOCALSERVER_H

#include <QObject>
#include <QTcpSocket>
#include <QTcpServer>

#include <QString>
#include <QUdpSocket>
#include <QDataStream>
#include <QTimer>

//class QTcpServer;
//Used for getting and receiving information from the raspberry PI

class localserver : public QTcpServer{


    Q_OBJECT

public slots:
    //Used to create new connection   *****NOT USED*****
    void newConnection();


public:


    QUdpSocket *socket;
     explicit localserver(QObject *parent=nullptr);

   // localserver();
    QTcpServer *server;

    /*
     * Instead of this awful lot of useless functions, only one can be used. Maybe two for a better control with the joystick
     */
    void go_forward(char forw);
    void go_backward(char back);
    void automatic_driving(char choice);
    void manual_mode(char choice);
    void direction_pad(char direction);
    void go_certain(char direction);
    void stream_camera(char camera);
    char get_center();

signals:

private:

    int number_x;

    QHostAddress host;
    quint16 port;



    //these will be sent to the raspberry
    QByteArray Data;
    QByteArray direction;

};

#endif // LOCALSERVER_H
