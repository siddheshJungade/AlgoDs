#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n ; cin >> n;
    int rem = n%4;
    if(rem == 0)
        cout << n ;
    else if(rem == 1)
        cout << 1;
    else if(rem == 2)
        cout << n+1;
    else 
        cout << 0;
    return 0;
}
