pragma Singleton
import QtQuick 2.15

QtObject{
    property bool isDarkTheme: true

    property int initalWidth: 450
    property int initalHeight: 650
    property int minimumWidth: 350
    property int minimumHeight: 450

    property color standartBackGroundColor: "#FF202020"

    property color standartButtonColor: "#FF323232"
    property color lightButtonColor: "#FF3B3B3B"
    property color uniqueButtoncolor: "#FF76B9ED"

    property color standartTextColor: "#FFCECECE"
    property int largePointSize: 18
    property int standartPointSize: 9
    property int buttonCalcPointSize: 12
}
