import QtQuick 2.15
import QtQuick.Controls 2.2
import QtQuick.Controls.Material 2.2

import Header 1.0
import StyleSetting 1.0
import Drawer 1.0

ApplicationWindow {
    id: window

    width: Style.initalWidth
    height: Style.initalHeight
    minimumWidth: Style.minimumWidth
    minimumHeight: Style.minimumHeight

    visible: true
    title: qsTr("mathHelper")

    header: MainHeader
    {
        id: _header

        labelTextToolBar.text: _drawer.pageName

        onOpenDrawerSignal:{
            _drawer.openDrawer()
        }
    }

    Loader
    {
        id: _loader
        anchors.fill: parent
        source: _drawer.pagePath
    }

    MainDrawer
    {
        id: _drawer

        width: window.width / 3
        height: window.height - _header.height

        y: _header.height


    }
 }
