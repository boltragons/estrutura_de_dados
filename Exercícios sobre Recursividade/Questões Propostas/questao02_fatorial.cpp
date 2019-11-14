#include <iostream>

using namespace std;

int fatorial(int num){
    if(num == 0)
        return 1;
    else
        return num * fatorial(num - 1);
}

int main(void){
    int num = 0;
    cin >> num;
    cout << fatorial(num);
}