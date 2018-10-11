import QtQuick 2.9

Item {

    id: root
    property int  duration: 5000
    property int  fromMs: 0
    property int  toMs: 5000
    property int  position: 2500
    signal changeFromAndToMoment(int from, int to)
    signal timeIndicatorPositionChanged(int mYposition)
    property bool  movable: false
    property bool  autoPlay: false


    Rectangle{
        id: indicator
        width: 2
        color: "red"
        height: root.height
        x: 0



        MouseArea{
            id: mouseArea
            anchors.fill: parent

            hoverEnabled: true


            onEntered: {
                mouseArea.cursorShape = Qt.IBeamCursor

            }
            onExited: {


            }
            onPressed: {
                root.movable = true

            }
            onReleased: {
                root.movable = false
            }

            onMouseXChanged: {

                if(root.movable)
                {
                     console.log("DMMMs_____________________")
                        console.log("MOUSE X: " + mouseX)
                       console.log("current Duration on time Indicator: " + (root.toMs - root.fromMs))
//                    console.log("timeIndicat or fromMs: " + root.fromMs)
//                    console.log("timeIndicator toMs: " + root.toMs)
                      console.log("initial indicator X: " + indicator.x)

                    var newX = 0
                    newX = indicator.x + mouseArea.mouseX
                    root.timeIndicatorPositionChanged(parseInt(newX * Math.abs(root.toMs - root.fromMs) / root.width) + root.fromMs)

                    //                    root.position = indicator.x * Math.abs(root.toMs - root.fromMs) / root.width

                }
            }

        }
    }

    onPositionChanged: {


        console.log("position 1 :" +  root.position)
        indicator.x = (root.position - root.fromMs) * (root.width/ Math.abs(root.toMs - root.fromMs))
        console.log("On position change indicator X: " + indicator.x)
        console.log("position changed, new X: " + indicator.x)

            if(root.position < root.fromMs || root.position > root.toMs)
            {
                indicator.visible = false
            }
            else
            {
                indicator.visible = true
            }

        if(root.autoPlay)
        {
            if((root.position - root.fromMs) / Math.abs(root.toMs - root.fromMs) >= 0.8 && root.toMs != root.duration)
            {
                root.changeFromAndToMoment(root.fromMs+50, root.toMs + 50)
            }
        }


    }

    onFromMsChanged: {

        console.log("dm position co doi khong: " + root.position)

        indicator.x = (root.position - root.fromMs) * (root.width/ Math.abs(root.toMs - root.fromMs))
        console.log("INDICATOR X CHANGE: " + indicator.x)
        if(root.position < root.fromMs || root.position > root.toMs)
        {
            indicator.visible = false
        }
        else
        {
            indicator.visible = true
        }

        root.movable = false

    }
//    onToMsChanged: {
//        indicator.x = (root.position - root.fromMs) * (root.width/ Math.abs(root.toMs - root.fromMs))
//        if(root.position < root.fromMs || root.position > root.toMs)
//        {
//            indicator.visible = false
//        }
//        else
//        {
//            indicator.visible = true
//        }
//        root.movable = false
//    }
}
