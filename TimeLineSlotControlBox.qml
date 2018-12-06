import QtQuick 2.9
import QtQuick.Controls 2.2
import TimeLine 1.0
import Qt.labs.folderlistmodel 2.2
import QtQuick.Dialogs 1.2


Item {

    id:root

    property int  currentTimeSlotIndex: 0
    property int  currentGroupIndex: 0
    property int  currentValveModeIndex: 0
    property int  currentValveSpeed: 0
    property int  currentLedSpeed: 0
    property int  currentLedMode: 0
    property TimeSlotModel theTimeSlotModel: TimeSlotModel{list:returnTimeSlotList() }
    property bool groupIndexJustChanged: false
    property string currentLedColorList: "grey;grey"

    signal modelRefreshed()

    enabled: false

    function returnColor(index)
    {

        var colorArray = root.currentLedColorList.split(";")
        if(colorArray.length <= index)
        {
            return "#8e8e8e"
        }
        return colorArray[index]
    }

    onCurrentValveModeIndexChanged: {
        console.log("onCurrentValveModeIndexChanged")
    }



    function updateValveData()
    {
        console.trace()
        console.log("Group: " + root.currentGroupIndex + " - timeslot: " + root.currentTimeSlotIndex
                    + " - valveMode: " + valveModeComboBox.currentIndex)
        //        if(theTimeSlotModel.size !== 0  && root.currentTimeSlotIndex <= theTimeSlotModel.size)
        //        {
//        console.trace()

        theTimeSlotModel.setDataPerIndex(root.currentTimeSlotIndex,"ValveForceRepeat",valveForceRepeatCheckBox.checked)
        theTimeSlotModel.setDataPerIndex(root.currentTimeSlotIndex,"ValveForceRepeatTimes",valveForceRepeatSpinbox.value)
        theTimeSlotModel.setDataPerIndex(root.currentTimeSlotIndex,"ValveMode", valveModeComboBox.currentIndex)
        theTimeSlotModel.setDataPerIndex(root.currentTimeSlotIndex,"FileBinPath", effectFolderModel.get(valveModeComboBox.currentIndex,"filePath"))
        theTimeSlotModel.setDataPerIndex(root.currentTimeSlotIndex,"ValveSpeed",speedValveSpinBox.value)
        theTimeSlotModel.setDataPerIndex(root.currentTimeSlotIndex,"ValveModeName", effectFolderModel.get(valveModeComboBox.currentIndex,"fileName"))

        //        }

        //        refreshModel()


        console.log(effectFolderModel.get(valveModeComboBox.currentIndex,"fileSize"))

        if(valveForceRepeatCheckBox.checked)
        {
            switch(root.currentGroupIndex)
            {
            case 0:
            case 3:
            case 1:
            case 7:
            case 6:
            case 8:
                var currentFromMs = theTimeSlotModel.getDataPerIndex(root.currentTimeSlotIndex,"FromMs")
                var newToMs = effectFolderModel.get(valveModeComboBox.currentIndex,"fileSize") * valveForceRepeatSpinbox.value * 50 *(51- speedValveSpinBox.value) +currentFromMs
                theTimeSlotModel.setDataPerIndex(root.currentTimeSlotIndex,"ToMs", newToMs)
                break
            case 2:
                 currentFromMs = theTimeSlotModel.getDataPerIndex(root.currentTimeSlotIndex,"FromMs")
                 newToMs = effectFolderModel.get(valveModeComboBox.currentIndex,"fileSize")/2 * valveForceRepeatSpinbox.value * 50 *(51- speedValveSpinBox.value) +currentFromMs
                theTimeSlotModel.setDataPerIndex(root.currentTimeSlotIndex,"ToMs", newToMs)
                break


            }

        }

    }

    function updateEffectFolder()
    {
        switch(root.currentGroupIndex)
        {
        case 0:
            effectFolderModel.folder = Qt.resolvedUrl("file:///"+appFilePath+"/Effects/Kieu1")
            break

        case 1:
            effectFolderModel.folder = Qt.resolvedUrl("file:///"+appFilePath+"/Effects/Kieu2")
            break

        case 2:
            effectFolderModel.folder = Qt.resolvedUrl("file:///"+appFilePath+"/Effects/Kieu3")
            break

        case 3:
            effectFolderModel.folder = Qt.resolvedUrl("file:///"+appFilePath+"/Effects/Kieu4")
            break

        case 4:
            effectFolderModel.folder = Qt.resolvedUrl("file:///"+appFilePath+"/Effects/Kieu5")
            break

        case 5:
            effectFolderModel.folder = Qt.resolvedUrl("file:///"+appFilePath+"/Effects/Kieu6")
            break

        case 6:
            effectFolderModel.folder = Qt.resolvedUrl("file:///"+appFilePath+"/Effects/Kieu7")
            break

        case 7:
            effectFolderModel.folder = Qt.resolvedUrl("file:///"+appFilePath+"/Effects/Kieu8")
            break

        case 8:
            effectFolderModel.folder = Qt.resolvedUrl("file:///"+appFilePath+"/Effects/Kieu9")
            break

        }

    }


    function refreshModel()
    {
        theTimeSlotModel.list = returnTimeSlotList()
        if(theTimeSlotModel.list.count() === 0 || currentTimeSlotIndex == -1)
        {
            root.enabled = false
        }
        else
        {
            root.enabled = true
        }
    }

    function updateCurrentConfiguration()
    {
        root.currentValveModeIndex = theTimeSlotModel.getDataPerIndex(root.currentTimeSlotIndex, "ValveMode")
        root.currentValveSpeed = theTimeSlotModel.getDataPerIndex(root.currentTimeSlotIndex,"ValveSpeed")
        root.currentLedSpeed = theTimeSlotModel.getDataPerIndex(root.currentTimeSlotIndex,"LedSpeed")
        root.currentLedMode = theTimeSlotModel.getDataPerIndex(root.currentTimeSlotIndex,"LedModeHihi")
        root.currentLedColorList = theTimeSlotModel.getDataPerIndex(root.currentTimeSlotIndex,"LEDValuesList")

        ledSyncSwitch.checked = theTimeSlotModel.getDataPerIndex(root.currentTimeSlotIndex,"LedSync")
        valveModeComboBox.currentIndex = root.currentValveModeIndex
        ledModeCombobox.currentIndex = setLedMode(theTimeSlotModel.getDataPerIndex(root.currentTimeSlotIndex,"LedModeName"))

        colorBoxesRepeater.itemAt(0).color = returnColor(0)
        colorBoxesRepeater.itemAt(1).color = returnColor(1)
        valveForceRepeatCheckBox.checked = theTimeSlotModel.getDataPerIndex(root.currentTimeSlotIndex,"ValveForceRepeat")
        valveForceRepeatSpinbox.value = theTimeSlotModel.getDataPerIndex(root.currentTimeSlotIndex,"ValveForceRepeatTimes")



    }


    function setLedMode( modeName)
    {
        for(var i = 0; i < ledModeModel.count; i++)
        {
            if(ledModeModel.get(i).name === modeName)
                return i
        }

        return -1
    }

    onCurrentGroupIndexChanged: {

        root.groupIndexJustChanged = true
        console.log("timeSlotMGroupChanged")
        refreshModel()


        valveModeComboBox.model = returnValveModeList()
        root.updateEffectFolder()

        if(root.currentGroupIndex == 0 || root.currentGroupIndex == 3 || root.currentGroupIndex ==5 && valveModeComboBox.currentText === "Solid")
        {
            valveControlPane.state = "Solid"
        }
        else if (valveModeComboBox.currentText === "Fade")
        {
            valveControlPane.state = "Fade"
        }
        else if(valveModeComboBox.currentText === "Blink")
        {
            valveControlPane.state = "Blink"
        }
        else
        {
            valveControlPane.state = "Default"
        }

        console.log("Group: " + root.currentGroupIndex + " - timeslot: " + root.currentTimeSlotIndex
                    + " - valveMode: " +theTimeSlotModel.getDataPerIndex(root.currentTimeSlotIndex, "ValveMode") )

        root.updateCurrentConfiguration()

    }

    onCurrentTimeSlotIndexChanged:
    {
        //        refreshModel()

        //        if(root.groupIndexJustChanged)
        //        {
        //            root.groupIndexJustChanged = false
        //            console.trace()
        //            console.log("onCurrentTimeSlotIndexChanged")
        //            console.log("Group: " + root.currentGroupIndex + " - timeslot: " + root.currentTimeSlotIndex
        //                        + " - valveMode: " +theTimeSlotModel.getDataPerIndex(0, "ValveMode") )

        //            root.currentValveModeIndex = theTimeSlotModel.getDataPerIndex(0, "ValveMode")
        //        }
        //        else
        //        {

        //        if(root.groupIndexJustChanged)
        //        {
        //            root.groupIndexJustChanged = false
        //            return
        //        }
        console.trace()
        console.log("onCurrentTimeSlotIndexChanged")
        console.log("Group: " + root.currentGroupIndex + " - timeslot: " + root.currentTimeSlotIndex
                    + " - valveMode: " +theTimeSlotModel.getDataPerIndex(root.currentTimeSlotIndex, "ValveMode") )

        root.updateCurrentConfiguration()



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

    function returnValveModeList()
    {
        switch(root.currentGroupIndex)
        {
        case 0:
            return inverterModeModel

        case 1:
            return 0

        case 2:
            return 0

        case 3:
            return inverterModeModel

        case 4:
            return 0

        case 5:
            return inverterModeModel

        case 6:
            return 0

        case 7:
            return 0

        case 8:
            return 0

        }
    }

    Column{
        anchors.fill: parent

        //        Rectangle{
        //            height: 30
        //            width: root.width
        //            color: "grey"
        //            Label{
        //                anchors.verticalCenter: parent.verticalCenter
        //                anchors.horizontalCenter: parent.horizontalCenter
        //                text: "Kiểu " + (root.currentGroupIndex+1)
        //                font.bold: true
        //                font.pointSize: 12
        //                color: "white"
        //            }
        //        }

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
            currentIndex: tabBar.currentIndex
            clip: true
            width: root.width
            height: root.height - 40

            Pane {

                width: swipeView.width
                height: swipeView.height


                Column {
                    id: ledControlColumn
                    spacing: 40
                    width: parent.width

                    Row{
                        spacing: 5
                        anchors.horizontalCenter: parent.horizontalCenter
                        Button{
                            text: "Update"
                            onClicked:{
                                //                                refreshModel()
                                console.trace()
                                console.log("Group: " + root.currentGroupIndex + " - timeslot: " + root.currentTimeSlotIndex
                                            + " - valveMode: " + valveModeComboBox.currentIndex)

                                //                                if(theTimeSlotModel.size !== 0 /* && root.currentTimeSlotIndex <= theTimeSlotModel.size*/)
                                //                                {
                                console.trace()


                                theTimeSlotModel.setDataPerIndex(root.currentTimeSlotIndex,"LEDValuesList", colorBoxesRepeater.itemAt(0).color +";"+colorBoxesRepeater.itemAt(1).color)
                                theTimeSlotModel.setDataPerIndex(root.currentTimeSlotIndex,"LedModeName", ledModeCombobox.currentText)
                                theTimeSlotModel.setDataPerIndex(root.currentTimeSlotIndex,"LedSpeed", ledSpeedSpinBox.value)

                                //                                    console.log("Led Mode: " + ledModeCombobox.currentIndex)
                                theTimeSlotModel.setDataPerIndex(root.currentTimeSlotIndex,"LedModeHihi", ledModeCombobox.currentIndex)
                                theTimeSlotModel.setDataPerIndex(root.currentTimeSlotIndex,"LedSync", ledSyncSwitch.checked)

                                //                                }
                            }
                        }

                        Text {

                            text: qsTr("Mode: ")
                            anchors.verticalCenter: parent.verticalCenter

                        }
                        ComboBox{
                            id: ledModeCombobox
                            model: ledModeModel
                            anchors.verticalCenter: parent.verticalCenter
                            currentIndex: root.currentLedMode


                        }

                        Text {

                            text: qsTr("Speed")
                            anchors.verticalCenter: parent.verticalCenter
                        }
                        SpinBox{
                            id: ledSpeedSpinBox
                            from: -50
                            to: 50
                            stepSize: 1
                            value: root.currentLedSpeed
                            editable: true
                        }

                    }

                    Row
                    {
                        spacing: 5
                        Switch{
                            id: ledSyncSwitch
                            text: "Sync"
                        }


                        Text {

                            text: qsTr("Color: ")
                            anchors.verticalCenter: parent.verticalCenter

                        }

                        Repeater{

                            id: colorBoxesRepeater
                            model: 4

                            property int  currentSelectedIndex: -1

                            Rectangle{
                                id: theColorBox
                                property int  theIndex: index
                                width: 30
                                height: 30
                                anchors.verticalCenter: parent.verticalCenter

                                //                                radius: 15
                                color: root.returnColor(theColorBox.theIndex)
                                border.width: 1
                                border.color: "black"

                                MouseArea{
                                    anchors.fill: parent

                                    onClicked: {

                                        colorBoxesRepeater.currentSelectedIndex = theColorBox.theIndex

                                        theColorDialog.open()
                                        console.log(colorBoxesRepeater.currentSelectedIndex)
                                        theColorDialog.color = theColorBox.color
                                    }
                                }
                            }
                        }
                    }
                }
            }

            Flickable{

                contentWidth: swipeView.width
                contentHeight: valveControlPane.implicitHeight + 100
                ScrollBar.vertical: ScrollBar{ policy: ScrollBar.AlwaysOn}

                Pane {

                    id: valveControlPane
                    width: root.width
                    state: "Default"




                    Column {
                        spacing: 40

                        Row
                        {
                            id: valveControlMode
                            spacing: 2

                            Button{
                                text: "Update"

                                onClicked: root.updateValveData()

                            }


                            Text {

                                text: qsTr("|| Mode: ")
                                anchors.verticalCenter: parent.verticalCenter

                            }
                            ComboBox{
                                id: valveModeComboBox
                                model: inverterModeModel
                                anchors.verticalCenter: parent.verticalCenter
                                textRole: "name"
                                currentIndex: root.currentValveModeIndex

                                onCurrentTextChanged: {
                                    if(currentText == "Solid")
                                    {
                                        valveControlPane.state = "Solid"
                                    }
                                    else if (currentText == "Fade")
                                    {
                                        valveControlPane.state = "Fade"
                                    }
                                    else if(currentText == "Blink")
                                    {
                                        valveControlPane.state = "Blink"
                                    }
                                    else
                                    {
                                        valveControlPane.state = "Default"
                                    }
                                }
                            }

                            Text {

                                text: qsTr("|| Speed:")
                                anchors.verticalCenter: parent.verticalCenter
                            }
                            SpinBox{
                                id: speedValveSpinBox
                                from: -50
                                to: 50
                                stepSize: 1
                                value: root.currentValveSpeed
                                editable: true

                            }
                        }

                        Row
                        {
                            spacing: 10
                            CheckBox
                            {
                                id: valveForceRepeatCheckBox
                                text: "Forced Repeat    || "
                            }

                            Text {
                            anchors.verticalCenter: parent.verticalCenter
                                text: qsTr("Repeat:")
                            }

                            SpinBox{
                                id: valveForceRepeatSpinbox
                                from: 1
                                to:10000
                                stepSize: 1
                            }
                            Text {
                            anchors.verticalCenter: parent.verticalCenter
                                text: qsTr("times")
                            }

//                            TextField{
//                                id: valveRepeatTimeTextField
//                                width: 200
//                                validator: IntValidator{bottom: 0; top: 100000}

//                            }
                        }

                    }

                }

            }
        }

    }


    ListModel{
        id: inverterModeModel

        ListElement{
            name: "Solid"
        }
        ListElement{
            name: "Fade"
        }
        ListElement{
            name: "Blink"
        }
    }

    ListModel{
        id: valveBlinkModeModel

        ListElement{
            name: "Immediate"
        }
        ListElement{
            name: "Transition"
        }
    }


    ListModel{
        id: ledModeModel

        ListElement{
            name:"Color Transition"
        }
        ListElement{
            name: "Solid"
        }
        ListElement{
            name: "Blink"
        }
        ListElement{
            name:"Fade In/Out"
        }
        //        ListElement{
        //            name:"Strobe"
        //        }

    }

    FolderListModel{
        id: effectFolderModel
        nameFilters: ["*.bin"]
        showDirs: false
        showDotAndDotDot: false
        rootFolder: Qt.resolvedUrl("file:///"+appFilePath+"/Effects")



        Component.onCompleted:
        {
            console.trace()
            console.log("Folder count: " + effectFolderModel.count)
            //           effectFolderModel. = Qt.resolvedUrl("file:///"+appFilePath+"/Effects")
            effectFolderModel.folder = Qt.resolvedUrl("file:///"+appFilePath+"/Effects/Kieu1")

        }

        onFolderChanged: {
            console.log("Folder count: " + effectFolderModel.count)
            valveModeComboBox.model = effectFolderModel
            valveModeComboBox.textRole = "fileName"

            valveModeComboBox.currentIndex = root.currentValveModeIndex

        }

    }

    ColorDialog
    {
        id: theColorDialog

        title: "Please choose a color"

        onAccepted: {
            colorBoxesRepeater.itemAt(colorBoxesRepeater.currentSelectedIndex).color = theColorDialog.color
            console.trace()
            console.log("the color: " + theColorDialog.color)


        }

        onRejected: {

        }
    }


}
