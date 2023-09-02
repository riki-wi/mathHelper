#pragma once
#include <exception>
#include <cstring>

class ErrorExpression: exeption
{
private:
	const char* m_str;
public:
	ErrorExpression(const char* str): m_str(str){};

	const char *what() const noexcept override
    {
        return strcat("inappropriate expression: ", m_str);
    }
}

