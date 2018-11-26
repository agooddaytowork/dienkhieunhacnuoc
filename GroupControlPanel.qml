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
    signal timeSlotSelect(int timeSlotIndex)
    signal timeSlotAdded(int timeSlotIndex)
    signal timeSlotRemoved()
    property bool  selected: false

    //    onSelectedChanged: {
    //        timeLine.selected = selected
    //    }

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

                root.timeSlotAdded(list.lastIndex())

            }

            Repeater{
                id: timeSlotRepeater


                model:TimeSlotModel{

                    list: root.returnTimeSlotList()

                }



                property int  timeSlotSelectedIndex: -1


                delegate: TimeLineSlot{
                    id: theTimeLineSlot
                    z: 2
                    //                        width: theTimeLineSlot.refreshWidth()
                    //                        x: theTimeLineSlot.refreshX()
                    property int  timeSlotIndex: theId
                    valveMode: ValveMode
                    height: timeLine.height
                    timeLineFromMs: root.fromMs
                    timeLineToMs: root.toMs
                    //                    timeSlotFromMs: FromMs
                    //                    timeSlotToMs: ToMs
                    timeLineWidth:  timeLine.width
                    duration: root.duration

                    onDeleteTimeSlot: {

                        root.timeSlotRemoved()
                        var list = root.returnTimeSlotList()
                        list.removeItems(theId)


                    }

                    Component.onCompleted: {
                        timeSlotFromMs = FromMs
                        timeSlotToMs = ToMs
                    }

                    onTimeSlotFromMsChanged:
                    {
                        FromMs = timeSlotFromMs
                    }
                    onTimeSlotToMsChanged:
                    {
                        ToMs = timeSlotToMs
                    }

                    onTimeSlotSelect:
                    {
                        timeSlotRepeater.timeSlotSelectedIndex = theTimeLineSlot.timeSlotIndex
                        root.timeSlotSelect(theTimeLineSlot.timeSlotIndex)
                    }

                    timeSlotSelected:{

                        if(root.selected)
                        {
                            if(theTimeLineSlot.timeSlotIndex == timeSlotRepeater.timeSlotSelectedIndex)
                            {
                                true
                            }
                            else
                            {
                                false
                            }
                        }
                        else
                        {
                            false
                        }
                    }


                    onCheckCollision: {

                        //                        FromMs = theTimeLineSlot.timeSlotFromMs
                        //                        ToMs = theTimeLineSlot.timeLineToMs
                        var list = root.returnTimeSlotList()
                        var colliedOffset = list.timeSlotCollisionCheck(theId)

                        if(colliedOffset !== 0)
                        {
                            theTimeLineSlot.collided = true
                            theTimeLineSlot.rightCollision = list.getCollisionSide()

                            if(theTimeLineSlot.edgeSelected)
                            {
                                if(theTimeLineSlot.rightCollision)
                                {
                                    theTimeLineSlot.timeSlotToMs = FromMs + theTimeLineSlot.slotDuration
                                }
                                else
                                {
                                    theTimeLineSlot.timeSlotFromMs = colliedOffset
                                }

                            }
                            else
                            {
                                theTimeLineSlot.timeSlotFromMs = colliedOffset
                                theTimeLineSlot.timeSlotToMs = FromMs + theTimeLineSlot.slotDuration
                            }

                        }
                        else
                        {
                            theTimeLineSlot.collided = false
                        }
                    }

                }
            }
        }
    }
}
