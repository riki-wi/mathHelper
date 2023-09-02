#include "calculaterlogic.h"


// будет ли работать сравнение enum class? отловить исключение
QString CalculaterLogic::infixToPostfix(const QString &expr) const
{
    QString res;
    res.reserve(expr.size());
    std::stack<std::pair<QChar, int>> stack_expr;

    for(auto iter = expr.begin(); iter != expr.end(); ++iter)
    {
         char16_t current_symbol = (*iter).unicode();
         Priority current_preority = get_preority_by_sumbol(current_symbol);

         if(current_preority == Priority::ConstPriority)
         {
             res.append(current_symbol);
         } else if(current_preority == Priority::SqrtPriority)
         {
             stack_expr.push(std::make_pair(current_symbol, current_preority));
         } else if(current_preority == Priority::OpenBracketPriority)
         {
             stack_expr.push(std::make_pair(current_symbol, current_preority));
         } else if(current_preority == Priority::CloseBracketPriority)
         {
             while(stack_expr.size() > 0 && stack_expr.top().second != Priority::OpenBracketPriority)
             {
                 res.append(stack_expr.top().first);
                 stack_expr.pop();
             }
             stack_expr.pop();
         } else if(current_preority == Priority::SumPriority || current_preority == Priority::MulPriority ||
                   current_preority == Priority::DegreePriority)
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

double CalculaterLogic::calcPostfix(const QString &expr) const
{
}

Priority CalculaterLogic::get_preority_by_sumbol(char16_t symbol) const
{
    if(preority_map.find(symbol) != preority_map.end())
    {
        return preority_map.at(symbol);
    }
    return Priority::Unused;
}

QString CalculaterLogic::calc(const QString &expr)
{
    Q_UNUSED(expr)
    return infixToPostfix("3+4*2\\(1-5)^2");
}