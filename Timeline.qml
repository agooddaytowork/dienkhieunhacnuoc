import QtQuick 2.9
import QtQuick.Controls 2.2
Item {

    id: root
    property int  timeLineWidth: 640
    property int  timelineHeight: 80
    property int  fromMs: 0
    property int toMs: 60000
    property int  duration: 240000
    signal changeFromAndToMoment(int from, int to)

    Rectangle
    {
        id: timelineBG
        width: root.width
        height: root.height
        color: "grey"



        MouseArea
        {
            id: timeLineMainMouseArea
            anchors.fill: parent
            property int  initialX: 0

            function zoomTimeLine(angleDelta)
            {
                var theMsZoomStep = 0
                var theCurrentDuration = Math.abs(root.toMs - root.fromMs)
                if( theCurrentDuration<= 1000)
                {
                    theMsZoomStep = 50
                }
                else if(theCurrentDuration <= 60000)
                {
                    theMsZoomStep = 1000
                }
                else
                {
                    theMsZoomStep = 5000
                }

                if(angleDelta > 0)
                {


                    if(root.toMs >= root.duration)
                    {
//                        root.fromMs = 0
//                        root.toMs = root.duration

                        root.changeFromAndToMoment(0, root.duration)

                    }

                    else if(root.toMs < root.duration)
                    {
//                        root.toMs = root.toMs + theMsZoomStep
                        root.changeFromAndToMoment(root.fromMs, root.toMs + theMsZoomStep)

                    }
                    else
                    {
                         root.changeFromAndToMoment(root.fromMs, root.duration)
//                        root.toMs = root.duration

                    }

                }
                else
                {

                    if(Math.abs(root.toMs - root.fromMs) > 500)
                    {
//                        root.toMs = root.toMs - theMsZoomStep
                        root.changeFromAndToMoment(root.fromMs, root.toMs - theMsZoomStep)
                    }
                }

            }

            onPressed: {
                selectRec.width = 1
                selectRec.height = root.height
                selectRec.visible = true
                selectRec.x = timeLineMainMouseArea.mouseX
                selectRec.y = timeLineMainMouseArea.mouseY

                timeLineMainMouseArea.initialX = mouseX

            }

            onMouseXChanged: {
                if(mouseX > selectRec.x) // ben phai
                {
                    selectRec.width = mouseX - selectRec.x
                }
                else
                {
                    selectRec.x = mouseX
                    selectRec.width = Math.abs(mouseX - timeLineMainMouseArea.initialX)
                }

            }

            onClicked: {

            }

            onWheel: {
                console.log("Wheel X: " + wheel.angleDelta.x + " - Wheel Y: " + wheel.angleDelta.y)
                timeLineMainMouseArea.zoomTimeLine(wheel.angleDelta.y)

            }

        }

        Rectangle{
            id: selectRec
            width: 0
            height: 0
            anchors.top: parent.top
            visible: false
            color: "black"
            opacity: 0.5
            border.color: "black"
            border.width: 1
        }
    }










}
