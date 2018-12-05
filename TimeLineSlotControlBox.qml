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
        if(theTimeSlotModel.size !== 0  && root.currentTimeSlotIndex <= theTimeSlotModel.size)
        {
            console.trace()
            theTimeSlotModel.setDataPerIndex(root.currentTimeSlotIndex,"ValveMode", valveModeComboBox.currentIndex)
            theTimeSlotModel.setDataPerIndex(root.currentTimeSlotIndex,"FileBinPath", effectFolderModel.get(valveModeComboBox.currentIndex,"filePath"))
            theTimeSlotModel.setDataPerIndex(root.currentTimeSlotIndex,"ValveSpeed",speedValveSpinBox.value)
            theTimeSlotModel.setDataPerIndex(root.currentTimeSlotIndex,"ValveModeName", effectFolderModel.get(valveModeComboBox.currentIndex,"fileName"))
        }

        //        refreshModel()
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

        ledSyncSwitch.checked = theTimeSlotModel.getDataPerIndex(root.currentTimeSlotIndex,"LedSync");
        valveModeComboBox.currentIndex = root.currentValveModeIndex
        ledModeCombobox.currentIndex = setLedMode(theTimeSlotModel.getDataPerIndex(root.currentTimeSlotIndex,"LedModeName"))

        colorBoxesRepeater.itemAt(0).color = returnColor(0)
        colorBoxesRepeater.itemAt(1).color = returnColor(1)



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
            currentIndex: tabBar.currentIndex
            clip: true
            width: root.width
            height: root.height - 60

            Pane {

                width: swipeView.width
                height: swipeView.height


                Column {
                    id: ledControlColumn
                    spacing: 40
                    width: parent.width

                    Row{
                        spacing: 2
                        Switch{
                            id: ledSyncSwitch
                            text: "Sync"
                        }
                        Button{
                            text: "Update"
                            onClicked:{
                                console.trace()
                                console.log("Group: " + root.currentGroupIndex + " - timeslot: " + root.currentTimeSlotIndex
                                            + " - valveMode: " + valveModeComboBox.currentIndex)
                                if(theTimeSlotModel.size !== 0  && root.currentTimeSlotIndex <= theTimeSlotModel.size)
                                {
                                    console.trace()


                                    theTimeSlotModel.setDataPerIndex(root.currentTimeSlotIndex,"LEDValuesList", colorBoxesRepeater.itemAt(0).color +";"+colorBoxesRepeater.itemAt(1).color)
                                    theTimeSlotModel.setDataPerIndex(root.currentTimeSlotIndex,"LedModeName", ledModeCombobox.currentText)
                                    theTimeSlotModel.setDataPerIndex(root.currentTimeSlotIndex,"LedSpeed", ledSpeedSpinBox.value)

                                    //                                    console.log("Led Mode: " + ledModeCombobox.currentIndex)
                                    theTimeSlotModel.setDataPerIndex(root.currentTimeSlotIndex,"LedModeHihi", ledModeCombobox.currentIndex)
                                    theTimeSlotModel.setDataPerIndex(root.currentTimeSlotIndex,"LedSync", ledSyncSwitch.checked)

                                }
                            }
                        }
                    }


                    Row
                    {
                        spacing: 2
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

                    Grid
                    {
                        rows: 2
                        columns: 3
                        spacing: 2

                        Repeater{

                            id: colorBoxesRepeater
                            model: 2

                            property int  currentSelectedIndex: -1

                            Rectangle{
                                id: theColorBox
                                property int  theIndex: index
                                width: 30
                                height: 30

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

                    states:[

                        State{
                            name:"Solid"
                            PropertyChanges{
                                target: speedValveControl
                                visible: false
                            }
                            PropertyChanges{
                                target: valveInterterStrength00
                                visible: true
                            }

                            PropertyChanges{
                                target: valveFadeSliderRow00
                                visible: false
                            }
                            PropertyChanges{
                                target: valveBlinkSliderRow00
                                visible: false
                            }
                            PropertyChanges{
                                target: valveBlinkCycleRow00
                                visible: false
                            }
                            PropertyChanges{
                                target: valveBlinkCycleSlider00
                                visible: false
                            }

                            PropertyChanges{
                                target: valveBlinkMode00
                                visible: false
                            }
                        },
                        State{
                            name:"Default"
                            PropertyChanges{
                                target: speedValveControl
                                visible: true
                            }
                            PropertyChanges{
                                target: valveInterterStrength00
                                visible: false
                            }
                            PropertyChanges{
                                target: valveInterterStrength01
                                visible: false
                            }
                            PropertyChanges{
                                target: valveFadeSliderRow00
                                visible: false
                            }
                            PropertyChanges{
                                target: valveBlinkCycleRow00
                                visible: false
                            }
                            PropertyChanges{
                                target: valveBlinkCycleSlider00
                                visible: false
                            }
                            PropertyChanges{
                                target: valveBlinkSliderRow00
                                visible: false
                            }
                            PropertyChanges{
                                target: valveBlinkMode00
                                visible: false
                            }

                        },
                        State{
                            name:"Fade"
                            PropertyChanges{
                                target: speedValveControl
                                visible: false
                            }
                            PropertyChanges{
                                target: valveInterterStrength00
                                visible: false
                            }
                            PropertyChanges{
                                target: valveInterterStrength01
                                visible: false
                            }
                            PropertyChanges{
                                target: valveFadeSliderRow00
                                visible: true
                            }
                            PropertyChanges{
                                target: valveBlinkCycleRow00
                                visible: false
                            }
                            PropertyChanges{
                                target: valveBlinkSliderRow00
                                visible: false
                            }
                            PropertyChanges{
                                target: valveBlinkCycleSlider00
                                visible: false
                            }
                            PropertyChanges{
                                target: valveBlinkMode00
                                visible: false
                            }
                        },
                        State{
                            name:"Blink"
                            PropertyChanges{
                                target: speedValveControl
                                visible: false
                            }
                            PropertyChanges{
                                target: valveInterterStrength00
                                visible: false
                            }
                            PropertyChanges{
                                target: valveInterterStrength01
                                visible: false
                            }
                            PropertyChanges{
                                target: valveFadeSliderRow00
                                visible: false
                            }
                            PropertyChanges{
                                target: valveBlinkCycleRow00
                                visible: true
                            }
                            PropertyChanges{
                                target: valveBlinkCycleSlider00
                                visible: true
                            }
                            PropertyChanges{
                                target: valveBlinkMode00
                                visible: true
                            }
                            PropertyChanges{
                                target: valveBlinkSliderRow00
                                visible: true
                            }
                        }

                    ]


                    Column {
                        spacing: 40

                        Row
                        {
                            id: valveControlMode
                            spacing: 2
                            Text {

                                text: qsTr("Mode: ")
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
                        }

                        Row
                        {
                            id: speedValveControl
                            spacing: 2
                            Text {

                                text: qsTr("Speed")
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

                        Row{
                            id: valveInterterStrength00
                            spacing: 2
                            Text {

                                text: qsTr("CH1 Strength :")
                                anchors.verticalCenter: parent.verticalCenter
                            }
                            Slider{
                                id: inverterValveStrangeSlider
                                from: 0
                                to: 255
                                value: 125
                                stepSize: 1
                            }

                            Text {

                                text: inverterValveStrangeSlider.value
                                anchors.verticalCenter: parent.verticalCenter
                            }
                        }

                        Row{
                            id: valveInterterStrength01
                            visible: {
                                if(root.currentGroupIndex == 5  && valveControlPane.state === "Solid")
                                {
                                    true
                                }
                                else
                                {
                                    false
                                }
                            }
                            spacing: 2
                            Text {

                                text: qsTr("CH2 Strength :")
                                anchors.verticalCenter: parent.verticalCenter
                            }
                            Slider{
                                id: inverterValveStrangeSlider1
                                from: 0
                                to: 255
                                value: 125
                                stepSize: 1
                            }

                            Text {
                                text: inverterValveStrangeSlider1.value
                                anchors.verticalCenter: parent.verticalCenter
                            }
                        }

                        Row{

                            id: valveFadeSliderRow00
                            spacing: 2
                            Text {
                                width: 80
                                text: "CH1 - Start: " + parseInt(valveFadeRangeSlider00.first.value)
                                anchors.verticalCenter: parent.verticalCenter
                            }
                            RangeSlider{
                                id: valveFadeRangeSlider00
                                from: 0
                                to: 255
                                stepSize: 1.0
                                snapMode: RangeSlider.SnapAlways
                                first.value: 5
                                second.value: 100


                            }
                            Text {
                                text: "Stop: " + parseInt(valveFadeRangeSlider00.second.value)
                                anchors.verticalCenter: parent.verticalCenter
                            }
                        }



                        Row{
                            id: valveFadeSliderRow01
                            spacing: 2
                            visible: {
                                if(root.currentGroupIndex == 5  && valveControlPane.state === "Fade")
                                {
                                    true
                                }
                                else
                                {
                                    false
                                }
                            }
                            Text {
                                width: 80
                                text: "CH 2 - Start: " + parseInt(valveFadeRangeSlider01.first.value)
                                anchors.verticalCenter: parent.verticalCenter
                            }
                            RangeSlider{
                                id: valveFadeRangeSlider01
                                from: 0
                                to: 255
                                stepSize: 1.0
                                snapMode: RangeSlider.SnapAlways
                                first.value: 5
                                second.value: 100


                            }
                            Text {
                                text: "Stop: " + parseInt(valveFadeRangeSlider01.second.value)
                                anchors.verticalCenter: parent.verticalCenter
                            }
                        }

                        Row{

                            id: valveBlinkSliderRow00
                            spacing: 2
                            Text {
                                width: 80
                                text: "CH1 Start: " + parseInt(valveBlinkRangeSlider00.first.value)
                                anchors.verticalCenter: parent.verticalCenter
                            }
                            RangeSlider{
                                id: valveBlinkRangeSlider00
                                from: 0
                                to: 255
                                stepSize: 1.0
                                snapMode: RangeSlider.SnapAlways
                                first.value: 5
                                second.value: 100


                            }
                            Text {
                                text: "Stop: " + parseInt(valveBlinkRangeSlider00.second.value)
                                anchors.verticalCenter: parent.verticalCenter
                            }
                        }

                        Row
                        {
                            id: valveBlinkCycleRow00
                            spacing: 2
                            Text {
                                width: 100
                                text: "CH1 Cycle Time: " + valveBlinkCycleSlider00.value + "s"
                                anchors.verticalCenter: parent.verticalCenter
                            }
                            Slider{
                                id: valveBlinkCycleSlider00
                                from: 0
                                to: 60
                                stepSize: 0.5
                                value: 1
                            }
                            ComboBox{
                                id: valveBlinkMode00
                                model: valveBlinkModeModel
                                textRole: "name"

                            }
                        }

                        Row{

                            id: valveBlinkSliderRow01
                            spacing: 2
                            visible: {
                                if(root.currentGroupIndex == 5  && valveControlPane.state === "Blink")
                                {
                                    true
                                }
                                else
                                {
                                    false
                                }
                            }
                            Text {
                                width: 80
                                text: "CH2 Start: " + parseInt(valveBlinkRangeSlider01.first.value)
                                anchors.verticalCenter: parent.verticalCenter
                            }
                            RangeSlider{
                                id: valveBlinkRangeSlider01
                                from: 0
                                to: 255
                                stepSize: 1.0
                                snapMode: RangeSlider.SnapAlways
                                first.value: 5
                                second.value: 100


                            }
                            Text {
                                text: "Stop: " + parseInt(valveBlinkRangeSlider01.second.value)
                                anchors.verticalCenter: parent.verticalCenter
                            }
                        }


                        Row
                        {
                            id: valveBlinkCycleRow01
                            spacing: 2
                            visible: {
                                if(root.currentGroupIndex == 5  && valveControlPane.state === "Blink")
                                {
                                    true
                                }
                                else
                                {
                                    false
                                }
                            }
                            Text {
                                width: 100
                                text: "CH2 Cycle Time: " + valveBlinkCycleSlider01.value + "s"
                                anchors.verticalCenter: parent.verticalCenter
                            }
                            Slider{
                                id: valveBlinkCycleSlider01
                                from: 0
                                to: 60
                                stepSize: 0.5
                                value: 1
                            }
                            ComboBox{
                                id: valveBlinkMode01
                                model: valveBlinkModeModel
                                textRole: "name"

                            }
                        }

                        Button{
                            text: "Update"

                            onClicked: root.updateValveData()

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
        ListElement{
            name:"Strobe"
        }

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
