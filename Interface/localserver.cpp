#include <QTcpServer>
#include <QDebug>
#include <QTextStream>
#include <QUdpSocket>
#include "localserver.h"


//Initializer for the server
localserver::localserver(QObject *parent):QTcpServer(parent){

   socket = new QUdpSocket();
    //This was our backup
    /*RASPBERRY BACKUP*/
   //host = "192.168.178.27";
  // port = 7654;

    //instead of this host, use the one from your raspberry (ifconfing on the CLI to check it)
   host = "172.31.12.84";
   //doesnt really matter which port you use, but it has to be free and has to coincide with the one on your raspberry pi
   port = 7654;

}

/*
 * functions that make possible to interact with the car.
 * this being a prototype, I decided to use different functions for different actions. THis makes it easier to trubleshoot, but it's
 * a shame. Only one function should be used. Makes the code ligther and more efficient.
 *
 */

void localserver:: go_forward(char forw){
    Data.append(forw);
    //connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
     socket->writeDatagram(Data, host , port );
     Data.clear();
}
void localserver::automatic_driving(char choice){
    Data.append(choice);
    socket->writeDatagram(Data, host, port);
    Data.clear();
}

void localserver::go_backward(char back){
    Data.append(back);
    socket->writeDatagram(Data, host, port);
    Data.clear();
}
void localserver::manual_mode(char choice){
    Data.append(choice);
    socket->writeDatagram(Data, host, port);
    Data.clear();
}

void localserver::direction_pad(char direction){
    Data.append(direction);
    socket->writeDatagram(Data, host, port);
    Data.clear();
}

//go to certain direction, char direction define which one.
void localserver::go_certain(char direction){
    Data.append(direction);
    socket->writeDatagram(Data, host, port);
    Data.clear();
}


void localserver::stream_camera(char camera){
    Data.append(camera);
    socket->writeDatagram(Data,host, port);
    Data.clear();
}


//Create new socket but i dont remember if it should be used or not.LOL
void localserver::newConnection(){
    QTcpSocket *socket = server->nextPendingConnection();
    char buf[] ={"CONNECTED"};
    socket->write(buf);

}


//GET objects from the datagram, so objects got from the raspberry pi
char localserver::get_center(){
    char buf;
    socket->readDatagram(&buf, port);
    return buf;


}



