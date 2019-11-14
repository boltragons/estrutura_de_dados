#include <iostream>

/**
 * @author: Pedro Botelho
 * @date: 28-08-2019
 * @questao: Segunda Questão
 * 
 * */

using namespace std;

int soma_digitos(int num, int soma){
    if(num > 0){
        soma += num % 10;
        soma_digitos(num/10, soma);
    }
    
}

int main(void){
    int n = 0, soma = 0;
    cin >> n;
    cout << soma_digitos(n, soma);
}