import QtQuick 2.9

Item {

    id: root
    property int  groupID: 0
    property ListModel presenterModel: ListModel{}
    property double  group6P1: 1.1463414634146343
    property double  group6P2: 0.05746815829737426
    property double  group6P3: 2.4878048780487805
    property double  group6P4: 0.8160478478227146

    Component.onCompleted: {
        presenterModel.clear()
        createGroup(root.groupID)
    }

    onGroup6P1Changed:
    {
        presenterModel.clear()
        createGroup_6()
    }

    onGroup6P2Changed:
    {
        presenterModel.clear()
        createGroup_6()
    }
    onGroup6P3Changed:
    {
        presenterModel.clear()
        createGroup_6()
    }
    onGroup6P4Changed:
    {
        presenterModel.clear()
        createGroup_6()
    }

    function createGroup(i)
    {
        presenterModel.clear()
        switch(i)
        {
        case 0: createGroup_1()
            break
        case 1: createGroup_2()
            break
        case 2: createGroup_3()
            break
        case 3: createGroup_4()
            break
        case 4: createGroup_5()
            break
        case 5: createGroup_6()
            break
        case 6: createGroup_7()
            break
        case 7: createGroup_8()
            break
        case 8: createGroup_9()
            break

        }
    }

    function createGroup_1()
    {
        //        presenterModel.clear()
        presenterModel.append([
                                  {"presenterId":0,
                                      "xPos" : theFrame.edgePixelLength /2,
                                      "yPos" : theFrame.edgePixelLength/2}
                              ])
    }

    function createGroup_2()
    {
        for (var i = 0; i < 8; i++)
        {
            presenterModel.append({"presenterId":i,
                                      "xPos" : x_polarToCatersian(meterToPixel(2),Math.PI / 4 * i),
                                      "yPos" : y_polarToCatersian(meterToPixel(2),Math.PI / 4  * i)})
        }
    }

    function createGroup_3()
    {
        for (var i = 0; i < 16; i++)
        {
            presenterModel.append({"presenterId":i,
                                      "xPos" : x_polarToCatersian(meterToPixel(4),Math.PI / 8 * i),
                                      "yPos" : y_polarToCatersian(meterToPixel(4),Math.PI / 8  * i)})
        }
    }

    function createGroup_4()
    {
        for (var i = 0; i < 32; i++)
        {
            presenterModel.append({"presenterId":i,
                                      "xPos" : x_polarToCatersian(meterToPixel(10.7/2),Math.PI / 16 * i),
                                      "yPos" : y_polarToCatersian(meterToPixel(10.7/2),Math.PI / 16  * i)})
        }
    }

    function createGroup_5()
    {
        for (var i = 0; i < 12; i++)
        {
            presenterModel.append({"presenterId":i,
                                      "xPos" : x_polarToCatersian(meterToPixel(10) ,Math.PI / 6 * i + (Math.PI /12)),
                                      "yPos" : y_polarToCatersian(meterToPixel(10),Math.PI / 6 * i + (Math.PI /12))})
        }
    }

    function createGroup_6()
    {
        var p1 = root.group6P1
        var p2 = root.group6P2
        var p3 = root.group6P3
        var p4 = root.group6P4
        for (var i = 0; i < 8; i++)
        {
            presenterModel.append({"presenterId":i,
                                      "xPos" : x_polarToCatersian(meterToPixel(35/2),Math.PI / 4 * i),
                                      "yPos" : y_polarToCatersian(meterToPixel(35/2),Math.PI / 4  * i)})
            presenterModel.append({"presenterId":i,
                                      "xPos" : x_polarToCatersian(meterToPixel((35 -(p1*1))/2),Math.PI / 4 * i - p2 ),
                                      "yPos" : y_polarToCatersian(meterToPixel((35 -(p1*1))/2),Math.PI / 4  * i - p2)})
            presenterModel.append({"presenterId":i,
                                      "xPos" : x_polarToCatersian(meterToPixel((35 -(p1*1))/2),Math.PI / 4 * i + p2 ),
                                      "yPos" : y_polarToCatersian(meterToPixel((35 -(p1*1))/2),Math.PI / 4  * i + p2)})
            presenterModel.append({"presenterId":i,
                                      "xPos" : x_polarToCatersian(meterToPixel((35 -(p1*2))/2),Math.PI / 4 * i - p2 *2),
                                      "yPos" : y_polarToCatersian(meterToPixel((35 -(p1*2))/2),Math.PI / 4  * i - p2 *2)})
            presenterModel.append({"presenterId":i,
                                      "xPos" : x_polarToCatersian(meterToPixel((35 -(p1*2))/2),Math.PI / 4 * i + p2 *2),
                                      "yPos" : y_polarToCatersian(meterToPixel((35 -(p1*2))/2),Math.PI / 4  * i + p2*2)})
            presenterModel.append({"presenterId":i,
                                      "xPos" : x_polarToCatersian(meterToPixel((35 -(p1*3))/2),Math.PI / 4 * i - p2 *3),
                                      "yPos" : y_polarToCatersian(meterToPixel((35 -(p1*3))/2),Math.PI / 4  * i - p2 *3)})
            presenterModel.append({"presenterId":i,
                                      "xPos" : x_polarToCatersian(meterToPixel((35 -(p1*3))/2),Math.PI / 4 * i + p2 *3),
                                      "yPos" : y_polarToCatersian(meterToPixel((35 -(p1*3))/2),Math.PI / 4  * i + p2*3)})
            presenterModel.append({"presenterId":i,
                                      "xPos" : x_polarToCatersian(meterToPixel((35 -(p1*4))/2),Math.PI / 4 * i - p2 *4),
                                      "yPos" : y_polarToCatersian(meterToPixel((35 -(p1*4))/2),Math.PI / 4  * i - p2 *4)})
            presenterModel.append({"presenterId":i,
                                      "xPos" : x_polarToCatersian(meterToPixel((35 -(p1*4))/2),Math.PI / 4 * i + p2 *4),
                                      "yPos" : y_polarToCatersian(meterToPixel((35 -(p1*4))/2),Math.PI / 4  * i + p2*4)})
            presenterModel.append({"presenterId":i,
                                      "xPos" : x_polarToCatersian(meterToPixel((35 -(p1*5))/2),Math.PI / 4 * i - p2 *5),
                                      "yPos" : y_polarToCatersian(meterToPixel((35 -(p1*5))/2),Math.PI / 4  * i - p2 *5)})
            presenterModel.append({"presenterId":i,
                                      "xPos" : x_polarToCatersian(meterToPixel((35 -(p1*5))/2),Math.PI / 4 * i + p2 *5),
                                      "yPos" : y_polarToCatersian(meterToPixel((35 -(p1*5))/2),Math.PI / 4  * i + p2*5)})
            presenterModel.append({"presenterId":i,
                                      "xPos" : x_polarToCatersian(meterToPixel((35 -(p1*6))/2),Math.PI / 4 * i - p2 *6),
                                      "yPos" : y_polarToCatersian(meterToPixel((35 -(p1*6))/2),Math.PI / 4  * i - p2 *6)})
            presenterModel.append({"presenterId":i,
                                      "xPos" : x_polarToCatersian(meterToPixel((35 -(p1*6))/2),Math.PI / 4 * i + p2 *6),
                                      "yPos" : y_polarToCatersian(meterToPixel((35 -(p1*6))/2),Math.PI / 4  * i + p2 *6)})

            presenterModel.append({"presenterId":i,
                                      "xPos" : x_polarToCatersian(meterToPixel((35 -(p1*7))/2),Math.PI / 4 * i - p2 *7),
                                      "yPos" : y_polarToCatersian(meterToPixel((35 -(p1*7))/2),Math.PI / 4  * i - p2*7)})
            presenterModel.append({"presenterId":i,
                                      "xPos" : x_polarToCatersian(meterToPixel((35 -(p1*8))/2),Math.PI / 4 * i - p2 *8),
                                      "yPos" : y_polarToCatersian(meterToPixel((35 -(p1*8))/2),Math.PI / 4  * i - p2*8)})
            presenterModel.append({"presenterId":i,
                                      "xPos" : x_polarToCatersian(meterToPixel((35 -(p1*9))/2),Math.PI / 4 * i - p2 *9),
                                      "yPos" : y_polarToCatersian(meterToPixel((35 -(p1*9))/2),Math.PI / 4  * i - p2*9)})
            presenterModel.append({"presenterId":i,
                                      "xPos" : x_polarToCatersian(meterToPixel((35 -(p1*10))/2),Math.PI / 4 * i - p2 *10),
                                      "yPos" : y_polarToCatersian(meterToPixel((35 -(p1*10))/2),Math.PI / 4  * i - p2*10)})


            presenterModel.append({"presenterId":i,
                                      "xPos" : x_polarToCatersian(meterToPixel((35 -(p3*6))/2),Math.PI / 4 * i + p4 *6),
                                      "yPos" : y_polarToCatersian(meterToPixel((35 -(p3*6))/2),Math.PI / 4  * i + p4 *6)})

            presenterModel.append({"presenterId":i,
                                      "xPos" : x_polarToCatersian(meterToPixel((35 -(p3*7))/2),Math.PI / 4 * i + p4 *7),
                                      "yPos" : y_polarToCatersian(meterToPixel((35 -(p3*7))/2),Math.PI / 4  * i + p4*7)})
            presenterModel.append({"presenterId":i,
                                      "xPos" : x_polarToCatersian(meterToPixel((35 -(p3*8))/2),Math.PI / 4 * i + p4 *8),
                                      "yPos" : y_polarToCatersian(meterToPixel((35 -(p3*8))/2),Math.PI / 4  * i + p4*8)})
            presenterModel.append({"presenterId":i,
                                      "xPos" : x_polarToCatersian(meterToPixel((35 -(p3*9))/2),Math.PI / 4 * i + p4 *9),
                                      "yPos" : y_polarToCatersian(meterToPixel((35 -(p3*9))/2),Math.PI / 4  * i + p4*9)})
            presenterModel.append({"presenterId":i,
                                      "xPos" : x_polarToCatersian(meterToPixel((35 -(p3*5))/2),Math.PI / 4 * i + p4 *5),
                                      "yPos" : y_polarToCatersian(meterToPixel((35 -(p3*5))/2),Math.PI / 4  * i + p4*5)})


        }
    }

    function createGroup_7()
    {
        for (var i = 0; i < 16; i++)
        {
            presenterModel.append({"presenterId":i,
                                      "xPos" : x_polarToCatersian(meterToPixel(23/2) ,Math.PI / 8 * i ),
                                      "yPos" : y_polarToCatersian(meterToPixel(23/2) ,Math.PI / 8 * i )})
        }
    }

    function createGroup_8()
    {
        for (var i = 0; i < 8; i++)
        {
            presenterModel.append({"presenterId":i,
                                      "xPos" : x_polarToCatersian(meterToPixel(31.5/2) ,Math.PI / 4 * i),
                                      "yPos" : y_polarToCatersian(meterToPixel(31.5/2),Math.PI / 4  * i)})
        }
    }

    function createGroup_9()
    {
        for (var i = 0; i < 8; i++)
        {
            presenterModel.append({"presenterId":i,
                                      "xPos" : x_polarToCatersian(meterToPixel(2.5/2),Math.PI / 4 * i),
                                      "yPos" : y_polarToCatersian(meterToPixel(2.5/2),Math.PI / 4  * i)})
        }
        for ( i = 0; i < 16; i++)
        {
            presenterModel.append({"presenterId":i,
                                      "xPos" : x_polarToCatersian(meterToPixel(3),Math.PI / 8 * i),
                                      "yPos" : y_polarToCatersian(meterToPixel(3),Math.PI / 8  * i)})
        }
    }

    function x_polarToCatersian(r, angle)
    {

        return r * Math.cos(angle) + theFrame.edgePixelLength /2
    }

    function y_polarToCatersian(r, angle)
    {

        return r * Math.sin(angle) + theFrame.edgePixelLength /2
    }

    function meterToPixel(met)
    {
        return (42/ theFrame.edgePixelLength -10) * met
    }



    MusicPresensterFrame{

        id: theFrame

        Repeater{
            id: groupRepeater
            model: presenterModel

            delegate: MusicPresensterElement
            {
                presenterId: presenterId
                x: xPos
                y: yPos
            }
        }
    }

    ListModel{
        id: presenterGroupData

    }

}



