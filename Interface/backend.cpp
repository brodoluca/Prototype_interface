#include "backend.h"
#define PI 3.14159265
backend::backend(): m_counter(0),position_axis_x(0),position_axis_y(0){
    m_counter = 0;
    position_axis_x = 0;

    server = new localserver;

    //connect(server->server, SIGNAL(newConnection()), this, SLOT(server->send_something(10)));


}
void backend::automatic_mode(){
    char mode = '0';
    server->manual_mode(mode);

}
void backend::manual_mode(){
    char mode = '1';
    server->manual_mode(mode);
}
void backend::direction_right(){
    char b ='2';
    server->go_certain(b);
}

void backend::direction_diagonal_right(){
    char b ='3';
    server->direction_pad(b);
}
void backend :: button_event_forward(){
   // printf("You wanted to go forward\n");
    char go = '4';
    server->go_forward(go);
}

void backend::direction_diagonal_left(){
    char b = '5';
    server->direction_pad(b);
}



void backend::direction_left(){
    char b = '6';
    server->go_certain(b);
}

void backend::direction_diagonal_left_backward(){
    char b = '7';
    server->direction_pad(b);
}

void backend::button_event_stop(){
   // printf("You wanted to stop the car\n");
    char stop = '8';
    server->go_backward(stop);

}
void backend::direction_diagonal_right_backward(){
    char b='9';
    server->direction_pad(b);
}
void backend::car_stop(){
    char b ='A';
    server -> direction_pad(b);
}


void backend::stream_camera(){
    char camera = 'C';
    server->stream_camera(camera);
}
//**FUNCTIONS THAT NEED OPENCV.
//Simply comment those out
//------------------------------------------------------------------------------------//
void backend :: camera_on(){

    /*
    namedWindow(testNameWindow);
    Mat test_image = imread("/Users/brodie/Downloads/car.png");

    resize(test_image, test_image, Size(640,480));
    imshow(testNameWindow, test_image);
    */
}

void backend::camera_off(){
    //
    //destroyWindow(testNameWindow);
    //
}
//------------------------------------------------------------------------------------------//
//


int backend:: center_object(){
    return center_object_m;
}

void backend::get_object_write(int value){
    if(center_object_m  != value) {
      center_object_m = value;

      // printf("WHY ARE YOU CLICKING? The value is now: %c\n", value);
       changed_center();
       }
}


int backend:: left_object(){
    return left_object_l;
}


void backend::get_object_write_left(int value){
    if(left_object_l !=value){
        left_object_l = value;
        changed_left();
    }
}


int backend::right_object(){
    return right_object_r;
}

void backend::get_object_write_right(int value){
    if(right_object_r !=value){
        right_object_r = value;
        changed_right();
    }
}


/*X COORDINATE*/
//----------------------------------------------------------//

//function that reads the value on the x axis
int backend::position_x() const{


    return position_axis_x;
}

//once the value is read, the positon is updated

void backend::setPositionX(int x){
    if (x !=position_axis_x) {
            position_axis_x= x;


            printf("New POSITION OF X= %d \n",position_axis_x );

            //localserver::send_something(x);
            position_changed_y();
        }
}


/*Y COORDINATE*/
//----------------------------------------------------------//
//function that reads the value on the y axis
int backend::position_y() const{
    return position_axis_y;

}
//once the value is read, the positon is updated
void backend::setPositionY(int y){
    if (y !=position_axis_y) {
        position_axis_y= y;
        printf("New POSITION OF Y= %d \n",position_axis_y );

                position_changed_x();
            }
}


//----------------------------------------------------------//




/*COUNTER, CLICK THE JOYSTICK*/
//----------------------------------------------------------//
int backend::counter() const {
 return m_counter;
}

void backend::setCounter(int value) {
 if(m_counter != value) {
    m_counter = value;

    printf("WHY ARE YOU CLICKING? The value is now: %d\n", value);
    counterChanged();
    }
}

//----------------------------------------------------------//


/*
int backend::get_left(){
    return server->left;
}


int backend::get_right(){
    return server->right;
}

int backend::get_center(){
    return server->center;
}

int backend::get_car(){
    return server->car;
}*/
