#include <iostream>

using namespace std;

char find(int n, int *array, int k, int atual){
    if(n >= atual){
        for(int i = 0; i < n; i++){
            if(array[atual] + array[i] == k && atual != i){
                return 's';
            }
        }
    }
    else
        return 'n';
    return find(n, array, k, atual + 1);
}

int main(void){
    int n = 0, k = 0;
    cout << "Quantidade de elementos: " << endl;
    cin >> n;
    int *array = new int[n];
    for(int i = 0; i < n; i++){
        cout << "Elemento numero " << i << ":";
        cin >> array[i];
    }
    cout << "Qual a soma que voce quer achar? " << endl;
    cin >> k;
    cout << "Ha? " << find(n , array, k, 0);
}