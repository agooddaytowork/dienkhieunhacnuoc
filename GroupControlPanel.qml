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
            Label{
                anchors.centerIn: parent
                text: "Kiểu " + (root.groupIndex + 1)
                rotation: 90
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
