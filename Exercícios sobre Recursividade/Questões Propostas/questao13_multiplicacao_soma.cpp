#include <iostream>

using namespace std;

int multRec(int n1, int n2){
    if(n2 > 1)
        return n1 + multRec(n1, n2 - 1);
}   

int main(void){
    int mult1 = 0, mult2 = 0;
    cin >> mult1;
    cin >> mult2;
    cout << multRec(mult1, mult2);
}   