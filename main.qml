import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Window 2.2
import QtQuick.Layouts 1.0

Window {
    visible: true
    width: 640
    height: 480
    function updatePos(xPos, yPos){
        rectangle1.x=xPos
        rectangle1.y=yPos
    }


    Rectangle {
        id: rectangle1
        x: 240
        y: 240
        width: 20
        height: 20
        color: "#fd1414"
        radius: 1
    }

    signal buttonClicked(bool isWork)
    Button {
        id: start
        x: 450
        y: 0
        width: 60
        height: 40
        text: qsTr("Start")
        onClicked:
               buttonClicked(true)
    }
    Button {
        id: stop
        x: 550
        y: 0
        width: 60
        height: 40
        text: qsTr("Stop")
        onClicked:
               buttonClicked(false)
    }

}
