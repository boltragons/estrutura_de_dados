#include <iostream>

using namespace std;

int find_minor(int n, int *array, int elemento){
    if(n >= 0 && array[n] < elemento)
        elemento = array[n];
    if(n < 0)
        return elemento;
    return find_minor(n - 1, array, elemento);
}

int main(void){
    int n = 0, i = 0;
    cin >> n;
    int *array = new int[n];
    for(i = 0; i < n; i++){
        cin >> array[i];
    }
    cout << find_minor(n - 1, array, array[n - 1]);
}