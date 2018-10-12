import QtQuick 2.9
import QtQuick.Controls 2.2


Item {

    id: root

    property int  groupIndex: 0
    property int  fromMs: 0
    property int  toMs: 0
    property int  duration: 0
    property int  infoGroupWidth: root.width/10
    signal changeFromAndToMoment(int from, int to)

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
            width: root.width/10 * 9
            height: root.height
            fromMs: root.fromMs
            toMs: root.toMs
            duration: root.duration


            onChangeFromAndToMoment: {
                root.changeFromAndToMoment(from,to)
            }
        }
    }
}
