#include<iostream>
#include<cmath>
using namespace std;
double function (double x){
    return x * x * x + 5 * x - 4;
}
void bisection(double a, double b, int maxIterations){
    if(function(a)*function(b) >=0){
        cout << "bisection method is not applicable";
        return; 
    }
    cout << "Iteration \t a\t\t  b\t\t f(a)\t\t f(b)\t\t";
    for (int i = 1; i <= maxIterations; ++i){
        double c = (a + b) / 2.0;
        double fa = function(a);
        double fb = function(b);
        double fc = function(c);
        cout << i << "\t\t" << a << "\t\t" << b << "\t\t" << fa << "\t\t" << fb << endl;
        if(fc = 0.0 || (b-a)/2.0 < 0.0001){
            cout << "Root Found" << c << endl;
            return;
        }
        else if(fc *fa < 0){
            b = c;
        }
        else {
            a = c;
        }
    }
    cout << "Root is " << (a + b) / 2.0 << endl;
}
int main()
{
    double a = 0.0;
    double b = 3.0;
    int maxIterations = 50;

    bisection(a, b, maxIterations);

    return 0;
}
