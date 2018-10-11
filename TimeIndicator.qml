import QtQuick 2.9

Item {

    id: root
    property int  duration: 5000
    property int  fromMs: 0
    property int  toMs: 5000
    property int  position: 2500
    signal changeFromAndToMoment(int from, int to)
    signal timeIndicatorPositionChanged(int position)
    property bool  movable: false


    Rectangle{
        id: indicator
        width: 2
        color: "red"
        height: root.height
        x: root.position * (root.width/ Math.abs(root.toMs - root.fromMs))



        MouseArea{
            id: mouseArea
            property int  currentPosition: 0
            anchors.fill: parent

            hoverEnabled: true


            onEntered: {
                mouseArea.cursorShape = Qt.IBeamCursor

            }
            onExited: {


            }
            onPressed: {
                root.movable = true

            }
            onReleased: {
                root.movable = false
            }

            onMouseXChanged: {
                if(root.movable)
                {
                    var newX = 0

                     newX = indicator.x + mouseArea.mouseX
                    mouseArea.currentPosition =  parseInt(newX * Math.abs(root.toMs - root.fromMs) / root.width)

                    root.timeIndicatorPositionChanged(mouseArea.currentPosition)

                    //                    root.position = indicator.x * Math.abs(root.toMs - root.fromMs) / root.width

                }
            }

        }
    }

    onPositionChanged: {

        console.log("position 1 :" +  root.position)
        indicator.x = root.position * (root.width/ Math.abs(root.toMs - root.fromMs))
        console.log("position changed, new X: " + indicator.x)


    }
}
