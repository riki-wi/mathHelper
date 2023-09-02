#include "calculatermodel.h"

QString CalculaterModel::infixToPostfix(const QString &expr) const
{
    QString res;
    res.reserve(expr.size());
    std::stack<std::pair<QChar, int>> stack_expr;

    for(auto iter = expr.begin(); iter != expr.end(); ++iter)
    {
         char16_t current_symbol = (*iter).unicode();
         int current_preority = get_preority_by_sumbol(current_symbol);
         if(current_preority == 0)
         {
             res.append(current_symbol);
         } else if(current_preority == 6)
         {
             stack_expr.push(std::make_pair(current_symbol, current_preority));
         } else if(current_preority == 1)
         {
             stack_expr.push(std::make_pair(current_symbol, current_preority));
         } else if(current_preority == 2)
         {
             while(stack_expr.size() > 0 && stack_expr.top().second != 1)
             {
                 res.append(stack_expr.top().first);
                 stack_expr.pop();
             }
             stack_expr.pop();
         } else if(current_preority == 3 || current_preority == 4 || current_preority == 5)
         {
             while(stack_expr.size() > 0 && stack_expr.top().second >= current_preority)
             {
                 res.append(stack_expr.top().first);
                 stack_expr.pop();
             }
             stack_expr.push(std::make_pair(current_symbol, current_preority));
         }
    }

    while(stack_expr.size() > 0)
    {
        res.append(stack_expr.top().first);
        stack_expr.pop();
    }

    return res;
}

double CalculaterModel::calcPostfix(const QString &expr) const
{
    std::stack<double> s;
    for(auto iter = expr.begin(); iter != expr.end(); ++iter)
    {
        char16_t current_symbol = (*iter).unicode();
        int current_preority = get_preority_by_sumbol(current_symbol);

    }
}

int CalculaterModel::get_preority_by_sumbol(char16_t symbol) const
{
    if(preority_map.find(symbol) != preority_map.end())
    {
        return preority_map.at(symbol);
    }
    return -1;
}

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

QString CalculaterModel::calc(const QString &expr)
{
    Q_UNUSED(expr)
    return infixToPostfix("3+4*2\\(1-5)^2");
}

