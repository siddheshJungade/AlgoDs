#include<iostream>
using namespace std;

void printBinary(int n){
    int rem = n % 2;
    if(n == 0)
        return ;
    printBinary(n/2);
    if(rem < 10)
        cout << rem ;
}

int main(int argc, char const *argv[])
{
    int n; cin >> n;
    printBinary(n);
    return 0;
}
