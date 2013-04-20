#include <cmath>
#include <cstdio>
#include <cctype>
#include <cassert>
#include <cstring>
#include <cstdlib>

using namespace std;

const double PI = 3.14159265358979323846264338327950288L;

double calc_function(char **expr)
{
    double buf = 0.0;
    double calc_sum(char **expr);

    if (**expr)
    {
        if (isdigit(**expr) || **expr == '+' || **expr == '-')
            buf = strtod(*expr, expr);
        else if (!strncmp(*expr, "pi", 2))
            *expr += 2, buf = PI;
        else if (**expr == '(')
            ++(*expr), buf = calc_sum(expr), ++(*expr);
        else if (!strncmp(*expr, "sin", 3))
            *expr += 3, buf = sin(calc_function(expr));
        else if (!strncmp(*expr, "cos", 3))
            *expr += 3, buf = cos(calc_function(expr));
        else if (!strncmp(*expr, "tan", 3))
            *expr += 3, buf = tan(calc_function(expr));
        else
            assert(!"Syntax error.");
        while (**expr == ' ')
            ++(*expr);
    }

    return buf;
}

double calc_product(char **expr)
{
    double buf = 1.0; char sign = '*';

    while (**expr)
    {
        double res = calc_function(expr);
        if (sign == '*')
            buf *= res;
        else if (sign == '/')
            buf /= res;
        else
            assert(!"Please contact support staff.");
        sign = **expr;
        if (**expr != '*' && **expr != '/')
            break;
        while (*(++(*expr)) == ' ');
    }

    return buf;
}

double calc_sum(char **expr)
{
    double buf = 0.0, sign = 1.0;

    while (**expr)
    {
        double res = calc_product(expr);
        buf += sign * res;
        if (**expr == '+')
            sign = 1.0;
        else if (**expr == '-')
            sign = -1.0;
        else
            break;
        while (*(++(*expr)) == ' ');
    }

    return buf;
}

inline double calc(char *expr)
{
    while (*expr == ' ')
        ++expr;
    return calc_sum(&expr);
}

char buffer[1024], result[1024];

int main()
{
    while (gets(buffer))
    {
        if (*buffer == '0' && *(buffer + 1) == '\0')
            break;
        sprintf(result, "%.2lf", calc(buffer));
        if (!strcmp(result, "-0.00"))
            printf("0.00\n");
        else
            printf("%s\n", result);
    }
    return 0;
}
