#include<iostream>
using namespace std;

int fib(int n , int dp[]){
    if(n <= 1 ){
        dp[n] = n;
        return dp[n];
    }
    if(dp[n] != -1)
        return dp[n];
    dp[n] = fib(n-1,dp) + fib(n-2,dp);
    return dp[n];
}

int main(int argc, char const *argv[])
{
    int n ; cin >> n; 
    int dp[n+1] = {-1};
    fib(n , dp);
    cout << dp[n];
    return 0;
}
