import QtQuick 2.9
import QtQuick.Controls 2.2

Item {
    id: root

    property int  timeLineToMs: 0
    property int  timeLineFromMs: 0
    property int  timeSlotToMs: 0
    property int  timeSlotFromMs: 0
    property int  timeLineWidth: 0
    property int  duration: 0
    property int  slotDuration: 0
    signal deleteTimeSlot()
    signal checkCollision()
    property bool collided: false
    property bool rightCollision: false
    property bool  edgeSelected: false
    property bool timeSlotSelected: false
    signal timeSlotSelect()

    x: root.refreshX()
    width: root.refreshWidth()



    function refreshPosition()
    {

        root.x = refreshPosition()
        root.width = refreshWidth()
    }

    function refreshWidth()
    {
        var newWidth = Math.abs(root.timeSlotToMs - root.timeSlotFromMs) / Math.abs(root.timeLineToMs - root.timeLineFromMs) * root.timeLineWidth

        var newPos =  (root.timeSlotFromMs  - root.timeLineFromMs) / Math.abs(root.timeLineToMs - root.timeLineFromMs) * root.timeLineWidth

        if(newPos <= 0 && Math.abs(newPos) <= newWidth)
        {
            return newWidth = newWidth - Math.abs(newPos)
        }
        else if(newPos <=0 && Math.abs(newPos) > newWidth)
        {
            return 0
        }
        else if((newPos+newWidth) >= root.timeLineWidth)
        {
            return newWidth = newWidth - Math.abs(newPos+newWidth-root.timeLineWidth)
        }
        else
        {
            return newWidth
        }
    }

    function refreshX()
    {
        var newPos =  (root.timeSlotFromMs  - root.timeLineFromMs) / Math.abs(root.timeLineToMs - root.timeLineFromMs) * root.timeLineWidth

        if(newPos <0)
        {
            return 0
        }
        else
        {
            return newPos
        }
    }
    Rectangle{
        id: theTimeSlot
        anchors.fill: parent
        property int  xOffsetValue: 0
        z:2

        MouseArea{
            id: timeSlotMouseArea
            anchors.fill: parent
            acceptedButtons: Qt.LeftButton | Qt.RightButton
            property int  mouseOffset: 0
            property bool  selected: false
            property bool fromEdge: false // only valid when root.edgeSelected = true
            hoverEnabled: true

            onPressed:
            {
                if(pressedButtons & Qt.RightButton)
                {
                    theTimeSlotMenu.open()
                }
                if(pressedButtons & Qt.LeftButton && timeSlotMouseArea.cursorShape === Qt.ArrowCursor)
                {
                    timeSlotMouseArea.mouseOffset = mouseX
                    timeSlotMouseArea.selected = true
                    root.edgeSelected = false
                }
                else
                {
                    timeSlotMouseArea.mouseOffset = mouseX
                    root.edgeSelected = true
                    timeSlotMouseArea.selected = false
                }

            }
            onReleased: {

                timeSlotMouseArea.selected = false
                root.edgeSelected = false
            }

            onMouseXChanged: {

                // SLIDE FUNCTION
                if(pressedButtons & Qt.LeftButton && timeSlotMouseArea.selected)
                {
                    root.slotDuration = Math.abs(root.timeSlotFromMs - root.timeSlotToMs)
                    root.timeSlotFromMs = (root.x - timeSlotMouseArea.mouseOffset +mouseX) /  root.timeLineWidth * Math.abs(root.timeLineToMs - root.timeLineFromMs) + root.timeLineFromMs


                    if(root.timeSlotFromMs <0)
                    {
                        root.timeSlotFromMs = 0
                    }
                    root.timeSlotToMs = root.timeSlotFromMs + root.slotDuration

                    root.checkCollision()
                }
                // SLOT EDGE DETECTION
                if(Math.abs(mouseX) <= 3 )
                {
                    timeSlotMouseArea.cursorShape = Qt.IBeamCursor
                    timeSlotMouseArea.fromEdge = true
                }
                else if(Math.abs(mouseX) >= theTimeSlot.width-3)
                {
                    timeSlotMouseArea.cursorShape = Qt.IBeamCursor
                    timeSlotMouseArea.fromEdge = false
                }

                else
                {
                    timeSlotMouseArea.cursorShape = Qt.ArrowCursor
                }

                if(root.edgeSelected)
                {


                    if(timeSlotMouseArea.fromEdge)
                    {
                        var previousFromMs = root.timeSlotFromMs
                        var previousTimeSlotDuration = root.slotDuration
                        root.timeSlotFromMs = (root.x  +mouseX) /  root.timeLineWidth * Math.abs(root.timeLineToMs - root.timeLineFromMs) + root.timeLineFromMs
                        if(collided && !root.rightCollision)
                        {
                            if(previousFromMs > root.timeSlotFromMs)
                            {
                                root.timeSlotFromMs = previousFromMs - 1
                                root.slotDuration = previousTimeSlotDuration
                            }

                        }
                        else
                        {
                            root.slotDuration = Math.abs(root.timeSlotToMs - root.timeSlotFromMs)
                        }

                    }
                    else
                    {
                        var previousToMs = root.timeSlotToMs
                         previousTimeSlotDuration = root.slotDuration

                        root.timeSlotToMs  =  (root.x  +mouseX) /  root.timeLineWidth * Math.abs(root.timeLineToMs - root.timeLineFromMs) + root.timeLineFromMs

                        if(collided && root.rightCollision)
                        {
                            if(previousToMs < root.timeSlotToMs){
                                root.timeSlotToMs = previousToMs + 1
                                root.slotDuration = previousTimeSlotDuration
                            }
                        }
                        else
                        {
                            root.slotDuration = Math.abs(root.timeSlotToMs - root.timeSlotFromMs)
                        }


                    }
                      root.checkCollision()
                }

            }

            onClicked: {
                // implement shit here
                root.timeSlotSelect()
            }
        }
        Menu
        {
            id: theTimeSlotMenu
            MenuItem{
                text: qsTr("Delete")
                onClicked: {

                    root.deleteTimeSlot();
                }
            }
        }
        color:  root.timeSlotSelected ? "grey":"black"
        border.width: 1
        border.color: "white"

    }
}
