#include <iostream>

using namespace std;

int imprime(int n){
    if(n >= 0 && n % 2 == 0)
        cout << n << endl;
    return imprime(n - 1);
}

int main(void){
    int n = 0;
    cin >> n;
    imprime(n);
}