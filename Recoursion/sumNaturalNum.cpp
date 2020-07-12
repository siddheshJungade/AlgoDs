#include <iostream>
using namespace std;

int sum(int n){
    if(n==0)
        return 0;
    return sum(n-1) + n;
}
int sumf(int n){
    return n*(n+1)/2;
}

int main(int argc, char const *argv[])
{
    int n; cin >> n;
    cout << sum(n) << endl;
    cout << sumf(n) << endl;
    return 0;
}
