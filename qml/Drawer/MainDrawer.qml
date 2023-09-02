import QtQuick 2.15
import QtQuick.Controls 2.2

import StyleSetting 1.0
import Header

import DrawerModel 1.0

Drawer
{    
    id: root

    property string pageName: _listViewDrawer.pageName
    property string pagePath: _listViewDrawer.pagePath

    function openDrawer()
    {
        if(root.opened)
        {
            root.close();
        } else
        {
            root.open();
        }
    }

    ListView
    {
        id: _listViewDrawer

        property int indexHelper: 0 // для инициализации индекса (currentIndex, видимо, еще не существует)
        property string pageName: model.getTitleAt(indexHelper)
        property string pagePath: model.getSourceAt(indexHelper)

        anchors.fill: parent

        model: DrawerModel{}

        delegate: ItemDelegate
        {
            width: parent.width
            Label{
                width: parent.width
                height: parent.height

                Text{
                    anchors.centerIn: parent
                    color: Style.standartTextColor
                    text: model.title
                }
            }

            onClicked:{
                _listViewDrawer.currentIndex = index
                _listViewDrawer.indexHelper = index

                root.close()
            }

        }
        ScrollIndicator.vertical: ScrollIndicator { }
    }
}
