#include "thread.h"





//Initalizer of the objects from the class thread. It includes also the initializer from the classe backend, so it's possible to interact with
//the interface

thread::thread()
{
    back = new backend;

}


//function that is called when the thread is called in the main function. It is the function that will be repeated in the whole thread.
//can be thought as the function "loop" in the arduino IDE.
//This is a first implementation, the code can (and must) be modified and optimized.
void thread::run()
{
    while (1) {
        //Getting the object from the server class
        object = back->server->get_center();
        //then calling the respective writing function to modify the interface
        //1--> notify the object
        //0--> stop notifying
        if(object =='c'){
            back->get_object_write(1);
        }else if(object =='l'){
            back->get_object_write_left(1);
        }else if(object == 'r'){
             back->get_object_write_right(1);
        }else{

            back->get_object_write_right(0);
            back->get_object_write(0);
            back->get_object_write_left(0);
        }
        //Print function to check whether the thread is working or not
        printf("THREAD IN ACTION  %c\n", object);
        //usleep(500);
        sleep(1);

    }
    /*
     * In this function, different functions are used where the whole work could be done with only 2.
     * This was a prototype, so it is not optimized
     */

}


