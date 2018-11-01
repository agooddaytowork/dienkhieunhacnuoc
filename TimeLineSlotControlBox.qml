import QtQuick 2.9
import QtQuick.Controls 2.2

Item {

    id:root
    Column{
        anchors.fill: parent

        Rectangle{
            height: 30
            width: root.width
            color: "grey"
            Label{
                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                text: "Group 1"
                font.bold: true
                font.pointSize: 15
            }
        }

            TabBar{
                id: tabBar
                width: root.width
                height: 30


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

                    Pane {
                        width: swipeView.width
                        height: swipeView.height

                        Column {
                            spacing: 40
                            width: parent.width

                            Switch{
                                text: "Sync"
                            }
                            Row
                            {
                                Text {

                                    text: qsTr("Mode: ")
                                }
                                ComboBox{
                                    model: 5
                                }
                            }
                            Row
                            {
                                Text {

                                    text: qsTr("Speed")
                                }
                                ComboBox{
                                    model: 5
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

                            Label {
                                width: parent.width
                                wrapMode: Label.Wrap
                                horizontalAlignment: Qt.AlignHCenter
                                text: "T22222or text which allows the user"
                                      + "to switch between different subtasks, views, or modes."
                            }

                        }
                    }




            }


    }
}
