import QtQuick 2.9
import QtQuick.Controls 2.2
import TimeLine 1.0

Item {

    id:root

    property int  currentTimeSlotIndex: 0
    property int  currentGroupIndex: 0
    property TimeSlotModel theTimeSlotModel: TimeSlotModel{list:returnTimeSlotList() }

    onCurrentGroupIndexChanged: {
         console.log("timeSlotMGroupChanged")
        theTimeSlotModel.list = returnTimeSlotList()
    }

    function returnTimeSlotList()
    {
        switch(root.currentGroupIndex)
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

    Column{
        anchors.fill: parent

        Rectangle{
            height: 30
            width: root.width
            color: "grey"
            Label{
                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                text: "Kiểu " + (root.currentGroupIndex+1)
                font.bold: true
                font.pointSize: 12
                color: "white"
            }
        }

        TabBar{
            id: tabBar
            width: root.width
            height: 40

            TabButton{
                text: "LED"
            }
            TabButton
            {
                text: "Valve"
            }
        }



        SwipeView{
            id: swipeView
            width: root.width
            height: root.height - 60
            currentIndex: tabBar.currentIndex
            clip: true

            ScrollView{
                width: swipeView.width
                height: swipeView.height
                clip: true

                Pane {

                    width: swipeView.width


                    Column {
                        id: ledControlColumn
                        spacing: 40
                        width: parent.width

                        Switch{
                            text: "Sync"
                        }
                        Row
                        {
                            spacing: 2
                            Text {

                                text: qsTr("Mode: ")
                                anchors.verticalCenter: parent.verticalCenter

                            }
                            ComboBox{
                                model: 5
                                anchors.verticalCenter: parent.verticalCenter
                            }
                            Text {

                                text: qsTr("Speed")
                                anchors.verticalCenter: parent.verticalCenter
                            }
                            ComboBox{
                                model: 5
                                anchors.verticalCenter: parent.verticalCenter
                            }
                        }

                        Grid
                        {
                            rows: 2
                            columns: 3

                            Repeater{
                                model: 6

                                Rectangle{
                                    width: 30
                                    height: 30
                                    color: "grey"
                                    border.width: 1
                                    border.color: "white"
                                }
                            }
                        }


                    }
                }
            }

            Pane {
                width: swipeView.width
                height: swipeView.height

                Column {
                    spacing: 40
                    width: parent.width
                    Row
                    {
                        spacing: 2
                        Text {

                            text: qsTr("Mode: ")
                            anchors.verticalCenter: parent.verticalCenter

                        }
                        ComboBox{
                            model: 5
                            anchors.verticalCenter: parent.verticalCenter
                        }
                        Text {

                            text: qsTr("Speed")
                            anchors.verticalCenter: parent.verticalCenter
                        }
                        ComboBox{
                            model: 5
                            anchors.verticalCenter: parent.verticalCenter
                        }
                    }



                }
            }




        }


    }
}
