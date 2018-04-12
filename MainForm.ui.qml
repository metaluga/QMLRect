import QtQuick 2.5

Rectangle {
    property alias mouseArea: mouseArea

    width: 360
    height: 360
    property alias rectangle1: rectangle1
    MouseArea {
        id: mouseArea
        anchors.fill: parent


    }
}
