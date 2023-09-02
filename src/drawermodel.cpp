#include "drawermodel.h"

DrawerModel::DrawerModel(QObject* parent):
    QAbstractListModel(parent)
{
    // загружать данные из файла???
    m_cells.push_back(Cell("КАЛЬКУЛЯТОР", "qrc:/qml/Calculater/MainCalculater.qml"));
    m_cells.push_back(Cell("ГРАФИКИ", "qrc:/qml/Graph/MainGraph.qml"));
}

int DrawerModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return static_cast<int>(m_cells.size());
}

QVariant DrawerModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid() || index.row() > static_cast<int>(m_cells.size()))
    {
        return QVariant();
    }

    const Cell &cell = m_cells.at(index.row());
    switch(role)
    {
        case TitleRole:
        {
            return QVariant::fromValue(cell.title());
        }
        case SourceRole:
        {
            return QVariant::fromValue(cell.source());
        }
        default:
        {
            return QVariant();
        }
    }
}

QHash<int, QByteArray> DrawerModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[TitleRole] = "title";
    roles[SourceRole] = "source";

    return roles;
}

QString DrawerModel::getTitleAt(int index) const
{
    if(index >= static_cast<int>(m_cells.size()))
    {
        return QString();
    }

    return m_cells[index].title();
}

QString DrawerModel::getSourceAt(int index) const
{
    if(index >= static_cast<int>(m_cells.size()))
    {
        return QString();
    }

    return m_cells[index].source();
}

QString DrawerModel::Cell::source() const
{
    return m_source;
}

QString DrawerModel::Cell::title() const
{
    return m_title;
}
