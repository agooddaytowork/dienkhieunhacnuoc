import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3


ApplicationWindow {

    id: root
    visible: true
    width: 1366
    height: 768
    title: qsTr("Hello World")
    property int  fromMs: 0
    property int toMs: 60000
    property int  duration: 240000


    header: ToolBar{
        Row{
            anchors.fill: parent

            Button
            {
             text: "Button 1"

             onClicked: {
                 timeIndicator.position = 5000
             }
            }

            Button
            {
             text: "Button 1"

             onClicked: {
                 mainTimer.start()
             }
            }

            Button
            {
             text: "Button 1"
             onClicked: {
                 mainTimer.stop()
             }


            }

            Button
            {
             text: "Button 1"
            }
        }
    }

    GridLayout{
        id: mainGrid

        rows: 1
        columns: 2
        anchors.fill: parent

        Rectangle{
            id: controlTimeLineBGRec
            color: "yellow"
            width: root.width-500
            height: root.height


            TimeIndicator{

                id: timeIndicator

                height: parent.height
                width: parent.width / 10 * 9
                anchors.left: parent.left
                anchors.leftMargin: parent.width/10
                z:2
                fromMs: root.fromMs
                toMs: root.toMs
                duration: root.duration
                position: 0

                onTimeIndicatorPositionChanged:
                {
                    console.log("position 2: " + timeIndicator.position)
                    timeIndicator.position = position
                }

            }


            TimeLegend{
                width: parent.width / 10 * 9
                anchors.left: parent.left
                anchors.leftMargin: parent.width/10
                anchors.top: parent.top
                anchors.topMargin: 20
                height: 20
                anchors.right: parent.right
                miniTick: 2
                tick: 15
                fromMs: root.fromMs
                toMs: root.toMs

            }
            Column{
                anchors.top: parent.top
                anchors.topMargin: 40
                width: parent.width
                height: parent.height - 40  - 30
                spacing: 2


                Repeater{
                    model: 9
                    delegate: GroupControlPanel{
                        id: groupControlPanelDelegate
                        width: parent.width
                        groupIndex: index
                        height: (parent.height -40 - 2*9)/9
                        fromMs: root.fromMs
                        toMs: root.toMs

                        onChangeFromAndToMoment:
                        {
                            root.fromMs = from
                            root.toMs = to
                        }

                    }
                }
            }

            TimeLineScroll{
                id: timeLineScrol
                width: parent.width / 10 * 9
                anchors.left: parent.left
                anchors.leftMargin: parent.width/10
                height: 40
                duration: root.duration
                fromMs: root.fromMs
                toMs: root.toMs
                z:3
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 30
                onChangeFromAndToMoment:
                {
                    root.fromMs = from
                    root.toMs = to
                }
            }




        }
        Rectangle{

           id: presenterBGRec
           color: "grey"
           border.width: 1
           border.color: "black"
           width: 500
           height: root.height

           Repeater{
               model: 9
               delegate: MusicPresenterGroup{
                   id: theGroup
                   property int groupIndex: index
                   groupID: index
                   scale: 1
               }
           }
        }
    }

    Timer{
        id: mainTimer
        interval: 50
        repeat: true
        running: false
        triggeredOnStart: true

        onTriggered: {
            timeIndicator.position += 50
        }

    }
}
