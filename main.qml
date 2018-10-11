import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import QtMultimedia 5.9
import QtQuick.Dialogs 1.2


ApplicationWindow {

    id: root
    visible: true
    width: 1366
    height: 768
    title: qsTr("Nhạc nước Tiền Giang")
    property int  fromMs: 0
    property int toMs: 60000
    property int  duration: 240000
    property int  currentPosition: 0
    property int  buttonSize: 40



    header: ToolBar{



        Row{
            anchors.fill: parent


            ToolButton{
                text: "File"

                onClicked: {
                    fileMenu.open()
                }

                Menu{
                    id: fileMenu
                    y: parent.height

                    MenuItem{

                        text: "Open music"
                        onClicked: {
                            theFileDialog.open()
                        }
                    }
                }

            }

            ToolSeparator
            {

            }


            Button
            {
                icon.name: "Play"
                icon.source: "icons/play.png"
                width: root.buttonSize
                height: root.buttonSize
                icon.color: "transparent"
                icon.height: root.buttonSize
                icon.width: root.buttonSize
                onClicked: {
                    //                    mainTimer.start()
                    timeIndicator.autoPlay = true
                    audioPlayer.play()
                    timeIndicator.movable = false
                    root.duration = audioPlayer.duration
                    root.toMs = audioPlayer.duration

                    console.log("root duration: " + root.duration)
                    console.log("root toMs: " + root.toMs)

                }

            }

            Button
            {
                icon.name: "Pause"
                icon.source: "icons/pause.png"
                width:  root.buttonSize
                height: root.buttonSize
                icon.color: "transparent"
                icon.height: root.buttonSize
                icon.width: root.buttonSize
                onClicked: {
                    audioPlayer.pause()
                    timeIndicator.autoPlay = false
                    //                    mainTimer.stop()

                }

            }

            Button
            {
                icon.name: "Stop"
                icon.source: "icons/stop.png"
                width:  root.buttonSize
                height: root.buttonSize
                icon.color: "transparent"
                icon.height: root.buttonSize
                icon.width: root.buttonSize
                onClicked: {
                    timeIndicator.autoPlay = false
                    //                    mainTimer.stop()
                    root.currentPosition = 0
                    audioPlayer.stop()
                }

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
            width: root.width-400
            height: root.height


            TimeIndicator{

                id: timeIndicator

                height: parent.height / 10 * 9
                width: parent.width / 10 * 9
                anchors.left: parent.left
                anchors.leftMargin: parent.width/10
                anchors.top: parent.top
                anchors.topMargin: 5
                z:3
                fromMs: root.fromMs
                toMs: root.toMs
                duration: root.duration
                position: root.currentPosition

                onTimeIndicatorPositionChanged:
                {
                    root.currentPosition = mYposition
                }
                onChangeFromAndToMoment: {
                    root.fromMs = from
                    root.toMs = to
                }

            }



            TimeLegend{
                id: timeLegend
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

                Connections
                {
                    target: root

                    onFromMsChanged:
                    {
                        timeLegend.fromMs = root.fromMs
                    }

                    onToMsChanged:
                    {
                        timeLegend.toMs = root.toMs
                    }

                }


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
                        duration: root.duration

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
                z:2
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 30
                onChangeFromAndToMoment:
                {
                    root.fromMs = from
                    root.toMs = to
                }
            }

            TimeIndicator{

                id: timeIndicatorForScrollBar

                height: (parent.height -5) / 11
                width: parent.width / 10 * 9
                anchors.left: parent.left
                anchors.leftMargin: parent.width/10
                anchors.bottom: parent.bottom
                z:3
                fromMs:0
                toMs: root.duration
                duration: root.duration
                position: root.currentPosition

            }
        }
        Rectangle{

            id: presenterBGRec
            color: "grey"
            border.width: 1
            border.color: "black"
            width: 400
            height: root.height

            Rectangle{
                width: parent.width
                anchors.top: parent.top
                anchors.left: parent.left
                height: 400
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
    }

    Timer{
        id: mainTimer
        interval: 50
        repeat: true
        running: false
        triggeredOnStart: true

        onTriggered: {
            root.currentPosition += 50
        }

    }

    Audio{
        id: audioPlayer

        autoLoad: true
        notifyInterval: 50
        property int  previousPosition: 0
        onPositionChanged: {

            console.log("delta " + (audioPlayer.position - previousPosition))



            root.currentPosition = audioPlayer.position
            timeIndicator.deltaFromPreviousPosition = audioPlayer.position - audioPlayer.previousPosition

            audioPlayer.previousPosition = audioPlayer.position

        }
    }

    FileDialog{
        id: theFileDialog
        folder: shortcuts.home
        selectMultiple: false
        selectFolder: false
        nameFilters: ["Music (*.mp3 *.wav)"]
        onAccepted: {

            console.log("file URL" +  fileUrl)
            audioPlayer.source = fileUrl



            //            audioPlayer.play()
            //            console.log("audio duration" + audioPlayer.duration)
            //            console.log("audio Position" + audioPlayer.position)



        }
    }

}
