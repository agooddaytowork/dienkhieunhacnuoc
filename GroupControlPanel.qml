import QtQuick 2.9
import QtQuick.Controls 2.2
import TimeLine 1.0

Item {

    id: root

    property int  groupIndex: 0
    property int  fromMs: 0
    property int  toMs: 0
    property int  duration: 0
    property int  infoGroupWidth: root.width/10
    signal changeFromAndToMoment(int from, int to)
    signal timeLineSelected(int groupIndex)
    property bool  selected: false

    onSelectedChanged: {
        timeLine.selected = selected
    }

    function collisionCheck(timeSlotId)
    {
        var theList = returnTimeSlotList()


    }


    function returnTimeSlotList()
    {
        switch(root.groupIndex)
        {
        case 0:
            return timeSlotList_0

        case 1:
            return timeSlotList_1

        case 2:
            return timeSlotList_2

        case 3:
            return timeSlotList_3

        case 4:
            return timeSlotList_4

        case 5:
            return timeSlotList_5

        case 6:
            return timeSlotList_6

        case 7:
            return timeSlotList_7

        case 8:
            return timeSlotList_8

        }
    }


    Row
    {
        Rectangle{
            width: root.width / 10
            height: root.height

            radius: 10
            Column{
                anchors.fill: parent
                Label{
                    text: "Kiểu " + (root.groupIndex + 1)
                    height: root.height/3
                    anchors.horizontalCenter: parent.horizontalCenter
                    topPadding: 8
                    font.bold: true
                }

                Switch{
                    id: valveCheckBox
                    text: "Valve"
                    height: root.height/3
                    scale: 0.7

                }
                Switch{
                    id: ledCheckBox
                    text: "LED"
                    height: root.height/3
                    scale: 0.7
                }

            }

        }
        Timeline{
            id: timeLine
            width: root.width/10 * 9
            height: root.height
            fromMs: root.fromMs
            toMs: root.toMs
            duration: root.duration
            selected: root.selected


            onChangeFromAndToMoment: {
                root.changeFromAndToMoment(from,to)
            }

            onTimeLineSelect: {
                root.timeLineSelected(root.groupIndex)
            }

            onNewTimeSlot: {
                var list = returnTimeSlotList()

                list.appendItem(root.groupIndex,from,to)


            }

            Repeater{


                model:TimeSlotModel{

                    list: root.returnTimeSlotList()

                }

                delegate: Rectangle{
                    id: theTimeSlot
                    property int  xOffsetValue: 0

                    z:2

                    function refreshWidth()
                    {
                        var newWidth = Math.abs(ToMs - FromMs) / Math.abs(root.toMs - root.fromMs) * timeLine.width
                        var newPos =  (FromMs - root.fromMs) / Math.abs(root.toMs - root.fromMs) * timeLine.width

                        if(newPos <0 && Math.abs(newPos) <= newWidth)
                        {
                            return newWidth = newWidth + newPos
                        }
                        else if(newPos <0 && Math.abs(newPos) > newWidth)
                        {
                            return 0
                        }
                        else if(newPos+newWidth >= timeLine.width)
                        {
                            return newWidth = newWidth - Math.abs(newPos+newWidth-timeLine.width)
                        }
                        else
                        {
                            return newWidth
                        }
                    }

                    function refreshX()
                    {
                        var newPos =  (FromMs - root.fromMs) / Math.abs(root.toMs - root.fromMs) * timeLine.width

                        if(newPos <0)
                        {
                            return 0
                        }
                        else
                        {
                            return newPos
                        }
                    }

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

                                var timeSlotDuration = Math.abs(FromMs - ToMs)
                                FromMs = (theTimeSlot.x - timeSlotMouseArea.mouseOffset +mouseX) /  timeLine.width * Math.abs(root.toMs - root.fromMs) + root.fromMs
                                ToMs = FromMs + timeSlotDuration
                                var theList = root.returnTimeSlotList()

                                var colliedOffset = theList.timeSlotCollisionCheck(theId)

                                if(colliedOffset !== 0)
                                {
                                    FromMs = colliedOffset
                                    ToMs = FromMs + timeSlotDuration

                                }


                                theTimeSlot.refreshWidth()
                                theTimeSlot.refreshX()

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

                                var list = root.returnTimeSlotList()

                                list.removeItems(theId)
                            }
                        }
                    }

                    height: parent.height
                    width: theTimeSlot.refreshWidth()



                    x:theTimeSlot.refreshX()

                    color: "black"

                }
            }
        }
    }
}
