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
            console.log("timeLineWidth" + root.timeLineWidth)
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

            onPressed:
            {
                if(pressedButtons & Qt.RightButton)
                {
                    theTimeSlotMenu.open()
                }
                if(pressedButtons & Qt.LeftButton)
                {
                    timeSlotMouseArea.mouseOffset = mouseX
                    timeSlotMouseArea.selected = true
                }

            }
            onReleased: {
                timeSlotMouseArea.selected = false
            }

            onMouseXChanged: {
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
            }

            onClicked: {
                // implement shit here
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
        color: "black"
        border.width: 1
        border.color: "white"

    }
}
