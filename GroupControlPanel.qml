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
                    //                    list: if(root.groupIndex == 0 )
                    //                          {
                    //                              testList
                    //                          }
                    //                          else
                    //                          {
                    //                              0
                    //                          }

                    list: root.returnTimeSlotList()

                }

                delegate: Rectangle{
                    id: theTimeSlot
                    property int  xOffsetValue: 0
                    z:2
                    MouseArea{
                        anchors.fill: parent
                        acceptedButtons: Qt.LeftButton | Qt.RightButton

                        onPressed:
                        {
                            if(pressedButtons & Qt.RightButton)
                            {
                                theTimeSlotMenu.open()
                            }
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
                    width: {
                        var newWidth = Math.abs(ToMs - FromMs) / Math.abs(root.toMs - root.fromMs) * timeLine.width
                        var newPos =  (FromMs - root.fromMs) / Math.abs(root.toMs - root.fromMs) * timeLine.width

                        if(newPos <0 && Math.abs(newPos) <= newWidth)
                        {
                            newWidth = newWidth + newPos
                        }
                        else if(newPos <0 && Math.abs(newPos) > newWidth)
                        {
                            0
                        }
                        else if(newPos+newWidth >= timeLine.width)
                        {
                            newWidth = newWidth - Math.abs(newPos+newWidth-timeLine.width)
                        }
                        else
                        {
                            newWidth
                        }
                    }

                    x:{
                        var newPos =  (FromMs - root.fromMs) / Math.abs(root.toMs - root.fromMs) * timeLine.width

                        if(newPos <0)
                        {
                            0
                        }
                        else
                        {
                            newPos
                        }
                    }

                    color: "black"

                }
            }
        }
    }
}
