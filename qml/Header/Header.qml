import QtQuick 2.15
import QtQuick.Controls 2.2

import StyleSetting 1.0
import ResourceProvider 1.0

//вместо текста image _buttonOpenDrawer

ToolBar {
    property alias labelTextToolBar: _labelTextToolBar
    signal openDrawerSignal()

    Rectangle{

        id: root

        anchors.fill: parent
        color: Style.standartBackGroundColor

        Rectangle{
            id: _buttonOpenDrawer
            width: height
            height: root.height
            color: Style.standartBackGroundColor

            Text
            {
                anchors.centerIn: _buttonOpenDrawer

                font.pointSize: Style.largePointSize * 2
                color: Style.standartTextColor
                text: "≡"
            }

            MouseArea{
                id: _mouseAreaOpendrawer
                anchors.fill: _buttonOpenDrawer
                hoverEnabled: true
                onEntered:{
                    _buttonOpenDrawer.color = Style.lightButtonColor
                }
                onExited:{
                    _buttonOpenDrawer.color = Style.standartBackGroundColor
                }

                onClicked:{
                    openDrawerSignal()
                }
            }
        }

        Label{
            id: _labelToolBar
            width:root.width
            height: root.height

            anchors.left : _buttonOpenDrawer.right
            anchors.leftMargin: 5
            Text{
                id: _labelTextToolBar

                width: parent.width
                height: parent.height

                horizontalAlignment: Text.AlignLeft
                verticalAlignment: Text.AlignBottom

                color: Style.standartTextColor
                font.pointSize: Style.buttonCalcPointSize
                font.bold: true
                text: ""
            }
        }
    }
}
