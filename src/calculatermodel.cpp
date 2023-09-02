#include "calculatermodel.h"

CalculaterModel::CalculaterModel(QObject *parent, int rowCount, int columCount):
    QAbstractListModel(parent),
    m_rowCountCalc(rowCount),
    m_columnCountCalc(columCount)
{
}

int CalculaterModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return static_cast<int>(m_data.size());
}

QVariant CalculaterModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid() || index.row() > static_cast<int>(m_data.size()))
    {
        return QVariant();
    }

    const CellButton &cell = m_data.at(index.row());
    switch(role)
    {
        case TitleRole:
        {
            return QVariant::fromValue(cell.titleButton());
        }
        case Target:
        {
            return QVariant::fromValue(cell.target());
        }
        case TitleExprRole:
        {
            return QVariant::fromValue(cell.symbol_in_expression());
        }
        default:
        {
            return QVariant();
        }
    }
}

QHash<int, QByteArray> CalculaterModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[TitleRole] = "title";
    roles[Target] = "target";
    roles[TitleExprRole] = "title_expr";

    return roles;
}

int CalculaterModel::rowCountCalc() const
{
    return m_rowCountCalc;
}

int CalculaterModel::columnCountCalc() const
{
    return m_columnCountCalc;
}

