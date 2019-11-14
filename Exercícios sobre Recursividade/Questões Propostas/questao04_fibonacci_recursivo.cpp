#include <iostream>

using namespace std;

int fibonacci(int num){
   if(num==1 || num==2)
       return 1;
   else
       return fibonacci(num-1) + fibonacci(num-2);
}

int main(void){
    int n = 0;
    cin >> n;
    cout << fibonacci(n);
}