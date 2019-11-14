#include <iostream>

using namespace std;

void conversor(int n){
    //variavel da pilha
    int bi = 0;
    //caso base
    if(n == 0){
        return;
    }
    //conversao
    else if(n > 0)
        bi = n % 2; 
    //chamada da funcao
    conversor(n/2);  
    //impressao da pilha
    cout << bi;
}

int main(void){
    int n = 0;
    cin >> n;
    conversor(n);
}