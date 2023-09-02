#include <QString>

#pragma once

class CellButton
{
private:
    QString m_titleButton;
    QString m_target;
    QChar m_symbol_in_expression;

public:
    CellButton(QString titleButton, QString target, char16_t symbol_in_expression):
        m_titleButton(std::move(titleButton)),
        m_target(std::move(target)),
        m_symbol_in_expression(symbol_in_expression){};

    QString titleButton() const;
    QString target() const;
    QChar symbol_in_expression() const;
};
