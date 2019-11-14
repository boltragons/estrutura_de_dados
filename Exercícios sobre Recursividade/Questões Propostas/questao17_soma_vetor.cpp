#include <iostream>

using namespace std;

int soma_vetor(int n, int *array){
    if(n == -1)
        return 0;
    else
        return array[n] + soma_vetor(n - 1, array);
}

int main(void){
    int n = 0;
    cin >> n;
    int *array = new int[n];
    for(int i = 0; i < n; i++)
        cin >> array[i];
    cout << soma_vetor(n - 1, array);
}