#include <iostream>

using namespace std;

int fat_duplo(int num){
    if(num % 2 == 1)
        return num * fat_duplo(num - 2);
    /*
    else if(num % 2 == 0)
        return fat_duplo(num - 1);
    */
    if(num <= 1)
        return 1;
}

int main(void){
    int num = 0;
    cin >> num;
    cout << fat_duplo(num);
}