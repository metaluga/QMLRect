import QtQuick 2.5
import QtQuick.Window 2.2

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
}