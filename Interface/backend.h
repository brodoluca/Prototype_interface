/*
 * This class will modify and interact with the interface. This is why it is called Backend.
 * This class will use the class server to obtain and send information from /to the raspberry pi.
 * The class thread will initialize an object from this class
 */


#ifndef BACKEND_H
#define BACKEND_H

#include <QDebug>
#include <QObject>
#include <QString>
#include <QImage>
#include <QtGui>
#include <QLabel>
#include <QGuiApplication>
#include <QQuickImageProvider>


#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <math.h>
#include "localserver.h"
//if not needed, comment it out this line and all the functions containing it. Not necessary for the interface.
//#include <opencv2/opencv.hpp>
//using namespace cv;

class backend: public QObject{
    Q_OBJECT
    Q_PROPERTY(int position_x  READ position_x  WRITE setPositionX NOTIFY position_changed_x)
    Q_PROPERTY(int position_y  READ position_y  WRITE setPositionY NOTIFY position_changed_y)
    Q_PROPERTY(int counter READ counter WRITE setCounter NOTIFY counterChanged)
    Q_PROPERTY(int center_object READ center_object WRITE get_object_write NOTIFY changed_center)
    Q_PROPERTY(int left_object READ left_object WRITE get_object_write_left NOTIFY changed_left)
    Q_PROPERTY(int right_object READ right_object WRITE get_object_write_right NOTIFY changed_right)

public:


int center = 0;

    backend();

    //String testNameWindow = "TEST";
    struct sockaddr_in sa;
    int SocketFD = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

    int luca = 0;
    int counter() const;
    void setCounter(int value);

    int position_x() const;
    int position_y() const;

    void setPositionY(int y);
    void setPositionX(int x);


    void get_object_write(int value);
    void get_object_write_left(int value);
    void get_object_write_right(int value);

    int center_object();
    int left_object();
    int right_object();


    localserver *server;
public slots:

    void button_event_forward();
    void button_event_stop();
    void camera_on();
    void camera_off();
    void automatic_mode();
    void manual_mode();
    void direction_right();
    void direction_diagonal_right();
    void direction_diagonal_left();
    void direction_left();
    void direction_diagonal_left_backward();
    void direction_diagonal_right_backward();
    void car_stop();

    double center_is(){
        return luca;
    }
    void stream_camera();


    //int get_left();
    //int get_right();
    //int get_center();
    //int get_car();
signals:
    void changed_center();
    void changed_left();
    void changed_right();
    void position_changed_x();
    void position_changed_y();
    void counterChanged();

private:



int center_object_m;
    //Mat img;
    int m_counter;
    int position_axis_x;
    int position_axis_y;
//String testNameWindow = "WORK IN PROGRESS";
int left_object_l;
int right_object_r;

};




#endif // BACKEND_H
