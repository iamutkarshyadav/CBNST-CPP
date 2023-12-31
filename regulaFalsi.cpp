#include<iostream>

using namespace std;
#define MAX_ITER 100000
double func(double x){
    return x * x * x - x * x + 2; 
}
void regulaFalsi(double a, double b){
    if(func(a) * func(b) >=0){
        cout << "Assumption is wrong ";
        return; 
    }
    double c = a;
    for (int i = 0; i < MAX_ITER; i++){
        c = (a*func(b) - b*func(a))/ (func(b) - func(a));
        if (func(c)== 0)
        break;
        else if(func(c)*func(a) < 0)
        b = c; 
        else
        a = c; 
    }
    cout << " The value of the roots of the equation is : " << c; 
}
int main(){
    double a = -20, b = 300;
    regulaFalsi(a, b);
    return 0;
}