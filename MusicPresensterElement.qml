import QtQuick 2.9
import QtQuick.Controls 2.2

Item {

    id: root
    property int  presenterId: 0
    property bool valveON: false
    property bool valveLevelControl: false
    property int valveLevel: 0
    property  int presenerGroup: 0
    property bool ledON: false
    property string ledColor: "red"
    property int  ledMode: 0
    property double scale : 1.0
    property int edgePixelLength: 8
    property bool  odd: false


    onValveONChanged: {
        console.log("Valve ON CHANGEDDDD" + valveON);
    }

    Rectangle
    {
        id: theElement
        width: root.edgePixelLength * scale
        height: root.edgePixelLength * scale
        radius: (root.edgePixelLength * scale) /2
        color: root.valveON == true ? "black" : "white"

        border.width:  2
        border.color: root.ledON ? root.ledColor:"grey"
    }

}

