#include <iostream>

using namespace std;

double potencia(double a, int b){
    if(b == 0)
        return 1;
    else
        return a * potencia(a, b - 1);
}

int main(void){
    int a, b;
    cin >> a;
    cin >> b;
    cout << potencia(a, b);
}