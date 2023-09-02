#pragma once

#include <QObject>
#include <QString>

#include "errors.h"

class CalculaterLogic: public QObject
{
	QObject
private:
	// in ascending order of priority
	enum class Priority{ConstPriority, OpenBracketPriority, CloseBracketPriority, 
				        SumPriority, MulPriority, DegreePriority, SqrtPriority, Unused};

	// 0x03C0 - pi;  0x221A - sqrt
    std::map<char16_t, Priority> preority_map = {{'0', ConstPriority}, {'1', ConstPriority}, 
    											 {'2', ConstPriority}, {'3', ConstPriority}, 
    											 {'4', ConstPriority}, {'5', ConstPriority}, 
    											 {'6', ConstPriority}, {'7', ConstPriority},
    											 {'8', ConstPriority}, {'9', ConstPriority},
                                                 {'e', ConstPriority}, {0x03C0, ConstPriority},
                                                 {'(', OpenBracketPriority}, {')', CloseBracketPriority}, 
                                                 {'+', SumPriority}, {'-', SumPriority}, 
                                                 {'*', MulPriority}, {'\\', MulPriority}, 
                                                 {'^', DegreePriority}, {0x221A, SqrtPriority}};

    QString infixToPostfix(const QString& expr) const;
    double calcPostfix(const QString& expr) const;
    Priority get_preority_by_sumbol(char16_t symbol) const;

public:
	CalculaterLogic(QObject *parent = nullptr);

    Q_INVOKABLE QString calc(const QString& expr);
}