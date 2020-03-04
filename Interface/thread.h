

/*class responsable of creating a parallel thread necessary for getting the objects from the raspberry pi and
 * show the position in the interface.
 * This class will call the class named backend to modify and interact with the interface
*/

#ifndef THREAD_H
#define THREAD_H

#include <QThread>
#include "backend.h"
#include "localserver.h"

class thread : public QThread
{

    Q_PROPERTY(int center_obj READ center_obj NOTIFY obj_centerChanged)


public:
    thread();
    void run();

    //initializing the object from the class backend that controls the animations in the interface
    backend *back;

    //Variable containing the characters which defines the position of the object ('r','c','l')
    char object;

    /*
    **TESTS MADE TO CHECK IF WORKED
    int center_obj(){
        return l;

    }

    void set_center_obj(char value){
        if(center != value) {
            if(center == 'c'){

                   l=0;
            }else{

            }
            obj_centerChanged();
        }

    }

    int l;*/

protected:



signals:
    void obj_centerChanged();
private:

};





#endif // THREAD_H
