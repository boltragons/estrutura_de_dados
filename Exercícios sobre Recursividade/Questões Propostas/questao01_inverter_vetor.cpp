#include <iostream>

using namespace std;

void inverter(int n, int *array, int aux, int i){
    if(n > i){
        aux = array[n];
        array[n] = array[i];
        array[i] = aux;
    }
    else if(n <= i){
        return;
    }
    inverter(n - 1, array, 0, i + 1);
}

int main(void){
    int n = 0, i = 0;
    cin >> n;
    int *array = new int[n];
    for(i = 0; i < n; i++){
        cin >> array[i];
    }
    inverter(n - 1, array, 0, 0);
    for(i = 0; i < n; i++){
        cout << array[i] << endl;
    }
}