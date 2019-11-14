#include <iostream>

using namespace std;

void inverte(char *palavra, int i, int n, char swap){
    if(n > i){
        swap = palavra[n];
        palavra[n] = palavra[i];
        palavra[i] = swap;
    }
    else
        return;
    return inverte(palavra, i + 1, n - 1, 0);
}

int main(void){
    int n;
    cin >> n;
    char *palavra = new char[n];
    cin >> palavra;
    inverte(palavra, 0, n - 1, 0);
    cout << palavra;
}