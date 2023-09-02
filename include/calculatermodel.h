#pragma once

#include <QAbstractListModel>
#include <QString>
#include <vector>
#include <stack>
#include <map>

#include "calculatercell.h"

class CalculaterModel: public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(int rowCountCalc READ rowCountCalc CONSTANT)
    Q_PROPERTY(int columnCountCalc READ columnCountCalc CONSTANT)

private:

    std::vector<CellButton> m_data = {CellButton("%", "bin_operator", '\0'), CellButton("CE", "sys", '\0'),
                                      CellButton("C", "sys", '\0'), CellButton("DEL", "sys", '\0'),
                                      CellButton("π", "constanta", 0x03C0), CellButton("e", "constanta", 'e'),
                                      CellButton("(", "bracket", '('), CellButton(")", "bracket", ')'),
                                      CellButton("1/x", "unar_operator", '\0'), CellButton("x^y", "unar_operator", '^'),
                                      CellButton("√", "unar_operator", 0x221A), CellButton("\\", "bin_operator", '\\'),
                                      CellButton("7", "operand", '7'), CellButton("8", "operand", '8'),
                                      CellButton("9", "operand", '9'), CellButton("X", "bin_operator", 'X'),
                                      CellButton("4", "operand", '4'), CellButton("5", "operand", '5'),
                                      CellButton("6", "operand", '6'), CellButton("-", "bin_operator", '-'),
                                      CellButton("1", "operand", '1'), CellButton("2", "operand", '2'),
                                      CellButton("3", "operand", '3'), CellButton("+", "bin_operator", '+'),
                                      CellButton("+/-", "sign", '\0'), CellButton("0", "operand", '0'),
                                      CellButton(",", "operand", ','), CellButton("=", "calculator", '=')};

    enum Roles
    {
        TitleRole = Qt::UserRole + 1,
        Target,
        TitleExprRole
    };

    const int m_rowCountCalc;
    const int m_columnCountCalc;

public:
    CalculaterModel(QObject *parent = nullptr, int rowCount = 7, int columCount = 4);

    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

    int rowCountCalc() const;
    int columnCountCalc() const;
};
