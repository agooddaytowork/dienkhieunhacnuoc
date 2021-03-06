import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import QtMultimedia 5.9
import QtQuick.Dialogs 1.2
import Qt.labs.settings 1.0




ApplicationWindow {

    id: root
    visible: true
    width: 1366
    height: 768
    title: qsTr("Nhạc nước Tiền Giang")
    property int  fromMs: 0
    property int toMs: 60000
    property int  duration: 0
    property int  currentPosition: 0
    property int  buttonSize: 40
    property bool currentSongJustChanged: false

    property string currentSong: ""

    Settings{
        id: appSetting

        property bool  serialOutput: false
    }

    onCurrentSongChanged: {

        root.currentSongJustChanged = true
        //        console.log("file:///"+appFilePath+"/Sessions/" + root.currentSong +".bin")
        //        theInterfaceGod.importTimeSlotList("file:///"+appFilePath+"/Sessions/" + root.currentSong +".bin")
    }

    /***** THIS SHIT IS FOR QUITING THE Application after closing the GOODDDAAM THREAD ****/
    onClosing:
    {
        close.accepted = false;

        theInterfaceGod.closeThreads()
    }

    Connections{
        target: theInterfaceGod

        onGui_CloseApplication:
        {
            Qt.quit()
        }

        onGui_SerialPortConnection:
        {
            if(isConnected)
            {
                serialOutPutCheckBox.enabled = true
                serialOutPutCheckBox.checked = appSetting.serialOutput
            }
            else
            {
                serialOutPutCheckBox.checked = false
                serialOutPutCheckBox.enabled = false
            }
        }

        onGui_FrameListResconstructed:
        {
            if(root.currentSongJustChanged)
            {
                root.currentSongJustChanged = false

                theInterfaceGod.importTimeSlotList("file:///"+appFilePath+"/Sessions/" + root.currentSong +".bin")
            }
        }
    }

    /***** THIS SHIT IS FOR QUITING THE Application after closing the GOODDDAAM THREAD ****/



    onCurrentPositionChanged:
    {

    }

    header: ToolBar{



        Row{
            anchors.top: parent.top
            anchors.left: parent.left
            height: parent.height
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
                    MenuItem{

                        text: "New Session"
                        onClicked: {
                            root.currentSong = ""
                            root.currentPosition = 0
                            root.duration = 0

                            audioPlayer.source = ""

                            theInterfaceGod.clearTimeSlotList()

                        }
                    }
                    MenuItem{

                        text: "Save Session"
                        onClicked: {
                            theInterfaceGod.saveSession(root.currentSong)
                        }
                    }
                    MenuItem{

                        text: "Import Session"
                        onClicked: {

                            importFileDialog.open()

                        }
                    }
                    MenuItem{

                        text: "Export Session"
                        onClicked: {

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
                    audioPlayer.seek(root.currentPosition)
                    audioPlayer.play()

                    timeIndicator.movable = false
                    root.duration = audioPlayer.duration

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



        Row
        {
            anchors.right: parent.right
            anchors.top: parent.top
            height: parent.height
            anchors.rightMargin: 10
            spacing: 2
            Label{
                id: songLabel
                anchors.verticalCenter: parent.verticalCenter
                text: "Song: " + root.currentSong
            }

            ToolSeparator{

            }

            Label{
                id: timeLabel
                text: returnDurationString(root.currentPosition)
                anchors.verticalCenter: parent.verticalCenter

                function returnDurationString(duration)
                {
                    var minutes="00"
                    var seconds="00"
                    var miliSeconds ="000"

                    if(duration <=999)
                    {
                        miliSeconds = ("00" + duration).slice(-3)
                        return "00m:00s:"+miliSeconds +"ms"
                    }
                    else if(duration <=59999)
                    {
                        seconds = ("0" + parseInt(duration/1000)).slice(-2)
                        miliSeconds = ("00" + duration).slice(-3)

                        return "00m:"+seconds+"s:"+miliSeconds+"ms"
                    }
                    else
                    {
                        minutes = ("0" + parseInt(duration/60000)).slice(-2)

                        duration = duration%60000
                        seconds = ("0" + parseInt(duration/1000)).slice(-2)
                        miliSeconds =("00" + duration%1000).slice(-3)

                        return minutes + "m:" + seconds + "s:" + miliSeconds+"ms"

                    }
                }
            }



            ToolSeparator{

            }

            CheckBox{
                id: serialOutPutCheckBox
                enabled: false
                text: "Output"

                onCheckedChanged: {
                    theInterfaceGod.enableSerialOutput(checked)
                    appSetting.serialOutput = checked
                }
            }
            Button{
                id: serialButton
                text: "Serial: "
                width: 60

                onClicked: {
                    theSerialDialog.open()
                }
            }
            Label{
                id: serialPortNameText
                text: theSerialDialog.currentPortName
                anchors.verticalCenter: parent.verticalCenter
            }
        }

    }

    Grid{
        id: mainGrid
        enabled: root.duration == 0 ? false:true
        rows: 1
        columns: 2
        anchors.fill: parent
        rowSpacing: 1
        columnSpacing: 1


        Rectangle{
            id: controlTimeLineBGRec
            color: "white"
            width: root.width-500
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


                    if(audioPlayer.playbackState == Audio.PlayingState)
                    {
                        audioPlayer.seek(mYposition)
                    }
                    else
                    {
                        root.currentPosition = mYposition
                    }

                    var frameNo = mYposition/  50

                    // console.log("frame Point: " + frameNo)
                    theInterfaceGod.playFrame(parseInt(frameNo))
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


                onRequestTimeIndicatorPosition: {


                    if(audioPlayer.playbackState == Audio.PlayingState)
                    {
                        audioPlayer.seek(position)
                    }
                    else
                    {
                        root.currentPosition = position
                    }

                    var frameNo = position/  50

                    // console.log("frame Point: " + frameNo)
                    theInterfaceGod.playFrame(parseInt(frameNo))


                }

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
                    id: groupControlPanelRepeater
                    property int  currentGroupIndex: 0
                    property int  currentTimeSlotIndex: 0

                    model: 9
                    delegate: GroupControlPanel{
                        id: groupControlPanelDelegate
                        width: parent.width
                        groupIndex: index
                        height: (parent.height -40 - 2*9)/9
                        fromMs: root.fromMs
                        toMs: root.toMs
                        duration: root.duration
                        selected: {
                            if(groupControlPanelRepeater.currentGroupIndex === groupControlPanelDelegate.groupIndex)
                            {
                                true
                            }
                            else
                            {
                                false
                            }
                        }
                        onTimeSlotSelect:
                        {
                            groupControlPanelRepeater.currentTimeSlotIndex = timeSlotIndex
                            groupControlPanelRepeater.currentGroupIndex = groupControlPanelDelegate.groupIndex

                            //                            timeLineSlotControlBox.refreshModel()

                        }

                        onChangeFromAndToMoment:
                        {
                            root.fromMs = from
                            root.toMs = to
                        }
                        onTimeLineSelected: {
                            groupControlPanelRepeater.currentTimeSlotIndex = 0
                            groupControlPanelRepeater.currentGroupIndex = groupIndex

                        }

                        onTimeSlotAdded: {

                            groupControlPanelRepeater.currentGroupIndex = groupControlPanelDelegate.groupIndex
                            groupControlPanelRepeater.currentTimeSlotIndex = timeSlotIndex


                            timeLineSlotControlBox.refreshModel()
                        }

                        onTimeSlotRemoved: {

                            timeLineSlotControlBox.refreshModel()
                        }

                        onUpdateAllTimeSlots: {

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
            color: "#474747"
            border.width: 1
            border.color: "black"
            width: 500
            height: root.height


            Rectangle{
                width: parent.width
                anchors.top: parent.top
                anchors.left: parent.left
                height: 500
                color: "#474747"
                border.width: 1
                border.color: "black"
                Repeater{
                    model: 9
                    delegate: MusicPresenterGroup{
                        id: theGroup

                        property int groupIndex: index
                        groupID: index
                        scale: 1.3
                    }
                }

            }
            TimeLineSlotControlBox{

                id: timeLineSlotControlBox
                width: parent.width
                height: root.height-500
                anchors.bottom: parent.bottom
                anchors.left: parent.left
                currentGroupIndex: groupControlPanelRepeater.currentGroupIndex
                currentTimeSlotIndex:  groupControlPanelRepeater.currentTimeSlotIndex


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
        notifyInterval: 45
        property int  previousPosition: 0



        onDurationChanged: {
            console.log("changed DURATION ASLKDJALSDJSKLAJDKLSAJJD: " + duration)


            if(duration != 0)
            {
                 root.duration = duration
                root.toMs = duration
                theInterfaceGod.regenerateFrameList(duration, 50)
            }


        }

        onPositionChanged: {

            // console.log("delta " + (audioPlayer.position - previousPosition))



            root.currentPosition = audioPlayer.position
            timeIndicator.deltaFromPreviousPosition = audioPlayer.position - audioPlayer.previousPosition

            audioPlayer.previousPosition = audioPlayer.position

            var frameNo = audioPlayer.position/  50

            // console.log("frame Point: " + frameNo)
            theInterfaceGod.playFrame(parseInt(frameNo))

        }
    }

    FileDialog{
        id: theFileDialog
        folder: appFilePath
        selectMultiple: false
        selectFolder: false
        nameFilters: ["Music (*.mp3 *.wav)"]

        onAccepted: {

            theFileDialog.folder = fileUrl
            audioPlayer.source = fileUrl

            var theFileName = ""
            theFileName += fileUrl

            root.currentSong =theFileName.split('\\').pop().split('/').pop().slice(0,-4);

        }
    }

    FileDialog{
        id: importFileDialog
        selectMultiple: false
        title: "Import Sessions"
        selectFolder: false
        nameFilters: ["text (*.txt *.bin) "]
        onAccepted: {

            console.log("file URL " +  fileUrl)

            theInterfaceGod.importTimeSlotList(fileUrl)

        }
    }

    SerialDialog{
        id: theSerialDialog
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin:  250
    }



}
