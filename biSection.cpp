#include <iostream>
#include <cmath>

using namespace std;

double function(double x)
{
    return x * x * x + 5 * x - 4; // Change this function as needed
}

void bisection(double a, double b, int maxIterations)
{
    if (function(a) * function(b) >= 0)
    {
        cout << "Bisection method doesn't apply." << endl;
        return;
    }

    cout << "Iteration\t  a\t\t  b\t\t  f(a)\t\t  f(b)" << endl;

    for (int i = 1; i <= maxIterations; ++i)
    {
        double c = (a + b) / 2.0;
        double f_a = function(a);
        double f_b = function(b);
        double f_c = function(c);

        cout << i << "\t\t" << a << "\t\t" << b << "\t\t" << f_a << "\t\t" << f_b << endl;

        if (f_c == 0.0 || (b - a) / 2.0 < 0.0001)
        {
            cout << "Root found: " << c << endl;
            return;
        }
        else if (f_c * f_a < 0)
        {
            b = c;
        }
        else
        {
            a = c;
        }
    }

    cout << "Maximum iterations reached. Approximate root: " << (a + b) / 2.0 << endl;
}

int main()
{
    double a = 0.0;
    double b = 3.0;
    int maxIterations = 50;

    bisection(a, b, maxIterations);

    return 0;
}
