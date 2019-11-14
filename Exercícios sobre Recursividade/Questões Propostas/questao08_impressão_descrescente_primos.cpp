#include <iostream>

using namespace std;

int imprime(int n){
    int flag = 0;
    if(n >= 0){
        for(int i = 1; i <= n; i++){
            if(n % i == 0)
                flag++;
        }
        if(flag == 2)
            cout << n << endl;
    }
    return imprime(n - 1);
}

int main(void){
    int n = 0;
    cin >> n;
    cout << imprime(n);
}