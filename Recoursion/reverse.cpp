#include<iostream>
using namespace std;

void reverse(int n , int *res){
    if(n == 0)
        return ;
    *res = (*res) * 10 + n%10;
    reverse(n/10,res);
}
int main(int argc, char const *argv[])
{
    int n ;  cin >> n;
    int re = 0;
    reverse(n,&re);
    cout << re;
    return 0;
}
