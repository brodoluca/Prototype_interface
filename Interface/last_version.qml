import QtQuick 2.12

import QtQuick.Controls 2.3
import com.company.backendfirst 1.0
import com.company.local 1.0
ApplicationWindow{
    id: page
    width: 1280
    height: 720
    opacity: 1
    visible: true

    Rectangle {
        id: rectangle1
        x: 0
        y: 0
        width: 1280
        height: 720
        color: "#171717"


        Rectangle {
            id: rectangle5
            x: 802
            y: 318
            width: 5
            height: 250
            color: "#24c0ff"
            rotation: -21.1
        }

        Rectangle {
            id: rectangle3
            x: 657
            y: 318
            width: 5
            height: 250
            color: "#24c0ff"
            rotation: 21.1
        }

        Item {

            x: 1079
            y: 685
        }



        ProgressBar {
            id: progressBar
            x: 632
            y: 604
            rotation: 180
            value: 0.4
        }

        Switch {
            id: element
            x: 65
            y: 69
            width: 130
            height: 78
            checked: false
            onToggled:{
                if(element.checked == true){
                    backend.camera_on()
                }else{
                    backend.camera_off()
                }


            }
        }

        Switch {
            id: element1
            x: 239
            y: 68
            width: 130

            height: 78
            checked: false
            onToggled:{
                if(element1.checked == true){
                    backend.automatic_mode()
                }else{
                    backend.manual_mode()
                }
            }
        }

        ToolSeparator {
            id: toolSeparator
            x: 190
            y: 91
        }


        Image {
            id: image1
            x: 604
            y: 623
            width: 72
            height: 62
            fillMode: Image.PreserveAspectFit
            source: "qrc:/images/iconfinder_app_type_gas_stations_512px_GREY_287492.png"
        }



        Text {
            id: element4
            x: 242
            y: 47
            width: 116
            height: 37
            color: "#ffffff"
            text: qsTr("AUTO")
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 30
        }

        MouseArea {
            id: mouseArea1
            x: 1031
            y: 358
            width: 196
            height: 372
            rotation: 90
            Rectangle {
                id: rectangle4
                x: 0
                y: 101
                width: 196
                height: 200
                color: "#171717"
                radius: 100
                opacity: 1

                Image {
                    id: arrow_right
                    x: 0
                    y: 0
                    source: "qrc:/images/11247-large-blue-circle copia.png"
                    width: 196
                    height: 200
                    rotation: 180
                    opacity: 1

                }

            }
            onPressed: {
                rectangle4.opacity = 0.5
                rectangle4.color = "#ffffff"
                element2.text = "STOP"
                image4.opacity=0
                image6.opacity = 1

            }
            onReleased: {
                rectangle4.color = "#171717"
                rectangle4.opacity = 1
            }
            onClicked: {
                backend.button_event_stop()
                //backend.direction('2');
            }
        }


        Text {
            id: element3
            x: 81
            y: 47
            width: 116
            height: 37
            color: "#ffffff"
            text: qsTr("CAMERA")
            font.pixelSize: 30
        }


        ToolSeparator {
            id: toolSeparator1
            x: 1109
            y: 264
            width: 13
            height: 200
            rotation: 90
        }


        Image {
            id: container
            x: 25
            y: 272
            width: 374
            height: 363
            source: "qrc:/images/white-circle-icon-23.png"
            opacity: 0.7
        }
        Image {
            id: controller
            x: 92
            y: 344
            width: 240
            height: 219
            //color: "red"
            //opacity: (600.0 - rect.x) / 600
            source: "qrc:/images/11247-large-blue-circle.png"
            onXChanged: {
                image4.opacity=1
                image6.opacity = 0
                if(controller.y == 344 && controller.x == 92){

                }else{

                    if(controller.y>410){
                        if(controller.x>160){
                            backend.direction_diagonal_right_backward();
                        }else if(controller.x<30){
                            backend.direction_diagonal_left_backward();
                        }else{
                            backend.button_event_stop();
                        }

                    }else if (controller.y<270){
                        if(controller.x>160){
                            backend.direction_diagonal_right();
                        }else if(controller.x<30){
                            backend.direction_diagonal_left();
                        }else{
                            backend.button_event_forward();
                        }
                    }else{
                        if(controller.x>160){
                            backend.direction_right();
                        }else if(controller.x<30){
                            backend.direction_left();
                        }
                    }

                }

            }
            onYChanged:{
                image4.opacity=1
                image6.opacity = 0
                //console.log("y=" + y)
                if(controller.y == 344 && controller.x == 92){
                        backend.car_stop();
                }else{

                    if(controller.y>410){
                        if(controller.x>160){
                            backend.direction_diagonal_right_backward();
                        }else if(controller.x<30){
                            backend.direction_diagonal_left_backward();
                        }else{
                            backend.button_event_stop();
                        }

                 }else if (controller.y<270){
                        if(controller.x>160){
                            backend.direction_diagonal_right();
                        }else if(controller.x<30){
                            backend.direction_diagonal_left();
                        }else{
                            backend.button_event_forward();
                        }

                }else{
                        if(controller.x>160){
                            backend.direction_right();
                        }else if(controller.x<30){
                            backend.direction_left();
                        }
                    }
                }
            }

            MouseArea {
                anchors.fill: parent
                id :area
                drag.target: controller
                //drag.axis: Drag.XAxis
                drag.minimumX: 0
                drag.maximumX: 184

                drag.minimumY: 252
                drag.maximumY: 436
                onReleased: {
                    controller.x= 92
                    controller.y= 344
                    image4.opacity=0
                    image6.opacity = 1
                }
                Drag.active: area.drag.active

                onClicked: {
                    backend.counter = backend.counter + 1
                    //backend.position = controller.x
                }



            }
        }

        MouseArea {
            id: mouseArea
            x: 1031
            y: 9
            width: 196
            height: 372
            rotation: 90
            opacity: 0
            Rectangle {
                id: rectangle
                x: 0
                y: 101
                width: 196
                height: 200
                color: "#171717"
                radius:100


                Image {
                    id: arrow_left
                    x: 0
                    y: 0
                    source: "qrc:/images/cerchio.png"
                    width: 196
                    height: 200
                    clip: false
                    opacity: 1
                    Image{
                        id: forward
                        x: 23
                        y: 20
                        width: 150
                        height: 160
                        rotation: -90
                        source: "qrc:/images/arrow-symbol-arrow-png-image--29.png"
                        //source:
                    }

                }


            }
            onPressed: {
                rectangle.opacity = 0.5
                rectangle.color = "#ffffff"
                element2.text = "GO"
                image4.opacity = 1
                image6.opacity = 0


            }
            onReleased: {
                rectangle.color = "#171717"
                rectangle.opacity = 1
            }
            onClicked: {
                backend.button_event_forward();

            }
        }

        Image {
            id: image4
            x: 642
            y: 304
            width: 182
            height: 162
            opacity : 0
            fillMode: Image.PreserveAspectFit
            source: "qrc:/images/Ellipse.png"
        }
        Image {
            id: image2
            x: 680
            y: 384
            width: 104
            height: 102
            fillMode: Image.PreserveAspectFit
            source: "qrc:/images/Car.png"
        }


        Image {
            id: image6
            x: 631
            y: 332
            width: 203
            height: 188
            fillMode: Image.PreserveAspectFit
            source: "qrc:/images/Model 3.png"
            opacity: 1

        }


        Rectangle {
            id: rectangle2
            x: 548
            y: 231
            width: 353
            height: 343
            color: "#171717"
            border.color: "#171717"
            opacity: 0
            Image {
                id: model_3
                x: -1
                y: 103
                width: 356
                height: 416
                opacity: 1
                fillMode: Image.PreserveAspectFit
                source: "qrc:/images/model 3 copia.png"
            }
        }
        MouseArea{
            id: righ
            x: 859
            y: 272
            width: 131
            height: 93

            onPressAndHold : {
                righ_o.opacity = 1
                rectangle2.opacity=1
            }
            onReleased:{
                righ_o.opacity = 0
                rectangle2.opacity=0
            }

        }

        Image {
            id: righ_o
            x: 778
            y: 230
            width: 150
            height: 150
            rotation: -9
            opacity: 0
            fillMode: Image.PreserveAspectFit
            source: "qrc:/images/ok.png"
        }

        Image {
            id: middle_o
            x: 650
            y: 198
            width: 150
            height: 150
            rotation: -54.5
            opacity: 0
            fillMode: Image.PreserveAspectFit
            source: "qrc:/images/ok.png"
        }



        MouseArea {
            id: mouseArea2
            x: 633
            y: 184
            width: 175
            height: 164
            onPressAndHold : {
                middle_o.opacity = 1
                rectangle2.opacity=1
            }
            onReleased:{
                middle_o.opacity = 0
                rectangle2.opacity=0
            }
        }
        Text {
            id: element2
            x: 581
            y: 91
            width: 303
            height: 122
            color: "#ffffff"
            text: ""
            visible: false
            font.family: "Tahoma"
            lineHeight: 0.8
            renderType: Text.NativeRendering
            textFormat: Text.RichText
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 100
            //wrapMode: Text.Wrap
            elide: Text.ElideLeft

        }



        Image {
            id: left_o
            x: 503
            y: 230
            width: 150
            height: 150
            rotation: -99
            opacity: 0
            fillMode: Image.PreserveAspectFit
            source: "qrc:/images/ok.png"
        }

        MouseArea {
            id: mouseArea3
            x: 405
            y: 219
            width: 222
            height: 166
            onPressAndHold : {
                left_o.opacity = 1
                rectangle2.opacity=1
            }
            onReleased:{
                left_o.opacity = 0
                rectangle2.opacity=0
            }
        }


        MouseArea {
            id: mouseArea4
            x: 564
            y: 498
            width: 100
            height: 100
            onClicked: {
                if (rectangle3.color=="#24c0ff"){
                    rectangle3.color = "#580000"
                }else{
                    rectangle3.color = "#24c0ff"
                }
            }


        }


        MouseArea {
            id: mouseArea5
            x: 792
            y: 493
            width: 100
            height: 100
            onClicked: {
                if (rectangle5.color=="#24c0ff"){
                    rectangle5.color = "#580000"
                }else{
                    rectangle5.color = "#24c0ff"
                }
            }
        }

        Button {
            id: button
            x: 420
            y: 175
            text: qsTr("Button")
            onClicked:{
                backend._connect();
            }
        }
    }





}
