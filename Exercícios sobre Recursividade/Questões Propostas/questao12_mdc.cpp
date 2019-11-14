#include <iostream>

using namespace std;

int mdc(int x, int y){
    if(y == 0)
        return x;
    else
        return mdc(y, x%y);
}

int main(void){
    int num1 = 0, num2 = 0;
    cin >> num1;
    cin >> num2;
    cout << mdc(num1, num2);
}