#include "calculatercell.h"

QString CellButton::target() const
{
    return m_target;
}

QChar CellButton::symbol_in_expression() const
{
    return m_symbol_in_expression;
}

QString CellButton::titleButton() const
{
    return m_titleButton;
}
