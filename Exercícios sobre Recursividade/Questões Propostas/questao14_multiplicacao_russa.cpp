#include <iostream>

using namespace std;

int multRussa(int n1, int n2, int value){
    if(n1 % 2 == 1)
        value += n2;
    if(n1 > 1)
        return multRussa(n1/2, n2*2, value);
    else
        return value;
}   

int main(void){
    int mult1 = 0, mult2 = 0;
    cin >> mult1;
    cin >> mult2;
    cout << multRussa(mult1, mult2, 0);
}   