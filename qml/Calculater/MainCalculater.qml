import QtQuick 2.15
import QtQuick.Controls 2.2

import CalculaterModel 1.0

import StyleSetting 1.0

//перенести _gridViewTopButton в с++ ??
//зачем нужен leftMegrin в _gridViewButtom

Item {
    function assignСolor(str){
        if(str === "operand" || str === "sign"){
            return Style.lightButtonColor
        } else if (str === "bin_operator" || str === "sys"
                   || str === "bracket" || str === "constanta"
                   || str === "unar_operator"){
            return Style.standartButtonColor
        } else {
            return Style.uniqueButtoncolor
        }
    }

    function revColor(str){
        if(str === Style.standartButtonColor){
            return Style.lightButtonColor
        } else if (str === Style.lightButtonColor){
            return Style.standartButtonColor
        } else {
            return Style.uniqueButtoncolor
        }
    }

    id: root

    /* label */
    Rectangle{
        id: _calculaterLabel

        width: root.width
        height: root.height / 4

        color: Style.standartBackGroundColor

        TextField{
            id: _textCalculaterLabel
            width: parent.width
            height: parent.height / 1.5

            horizontalAlignment: TextInput.AlignRight
            verticalAlignment: TextInput.AlignVCenter

            font.pointSize: 2 * Style.largePointSize
            font.bold: true

            color: Style.standartTextColor

            validator: RegularExpressionValidator {regularExpression: /[0-9-+*/()]+/}

            placeholderText: "0"

            onTextEdited: {
                _textCaclculaterResult.text = text
            }
        }

        Text{
            id: _textCaclculaterResult

            width: parent.width
            height: parent.height - _textCalculaterLabel.height

            anchors.top: _textCalculaterLabel.bottom

            horizontalAlignment: Label.AlignRight
            verticalAlignment: Label.AlignVCenter

            visible: text == "0" ? false : true

            font.pointSize: Style.largePointSize
            color: Style.standartTextColor
        }
    }


    /* top panel */
    Rectangle{
        id: _topPanel

        width: root.width
        height: root.height / 15

        anchors.top: _calculaterLabel.bottom
        color: Style.standartBackGroundColor

        GridView{
            id: _gridViewTopButton

            anchors.fill: parent
            cellHeight: height
            cellWidth: width / model.countCell

            model: ListModelTopButton{}

            delegate: Rectangle{
                id: _buttonMC

                height: _gridViewTopButton.cellHeight
                width: _gridViewTopButton.cellWidth
                radius: 5

                color: Style.standartBackGroundColor

                Text{
                    anchors.centerIn: _buttonMC
                    text: model.text
                    color: Style.standartTextColor
                    font.pointSize: Style.standartPointSize
                }

                MouseArea{
                    anchors.fill: _buttonMC
                    hoverEnabled: true

                    onEntered:{
                        _buttonMC.color = Style.lightButtonColor
                    }

                    onExited:{
                        _buttonMC.color = Style.standartBackGroundColor
                    }

                    onClicked:{

                    }
                }
            }
        }
    }

    /* main panel */
    Rectangle{
        width: root.width
        height: root.height - _calculaterLabel.height - _topPanel.height

        anchors.top: _topPanel.bottom
        color: Style.standartBackGroundColor

        GridView{
            id: _gridViewButtom

            anchors.fill: parent
            anchors.leftMargin: 1.5 // considering spacing between children ???
            cellHeight: height / model.rowCountCalc
            cellWidth: width / model.columnCountCalc

            model: CalculaterModel{
                id : _calcModel
            }

            delegate: Rectangle{
                id: _button

                width: _gridViewButtom.cellWidth - 2 // spacing between children
                height: _gridViewButtom.cellHeight - 2

                color: assignСolor(model.target)
                border.width: 0.1
                radius: 5
                Text
                {
                    id: _textButton
                    text: model.title
                    color: Style.standartTextColor
                    font.pointSize: Style.buttonCalcPointSize
                    anchors.centerIn: _button
                }

                MouseArea{
                    anchors.fill: _button
                    hoverEnabled: true

                    onEntered:{
                        _button.color = revColor(_button.color)
                    }

                    onExited:{
                        _button.color = revColor(_button.color)
                    }

                    onClicked:{
                        if(target === "operand" || target === "unar_operator" || target === "bin_operator"
                                || target === "constanta" || target === "bracket"){
                            //_textCalculaterLabel.text = _textCalculaterLabel.text + title_expr
                            //_textCalculaterLabel.textEdited()
                            _textCaclculaterResult.text = _calcModel.calc(_textCalculaterLabel.text)
                        }
                    }
                }
            }
        }
    }

    Component.onCompleted:
    {
        _textCalculaterLabel.forceActiveFocus();
    }
}


