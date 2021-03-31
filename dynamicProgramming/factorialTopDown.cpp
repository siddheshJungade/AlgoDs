#include<iostream>
#include<vector>
using namespace std;

// the memoization method
int fact(int n,vector<int> &dp){
    if(n<=1) return dp[n] = 1;

    if(dp[n] != -1 ) return dp[n];

    return dp[n] = n * fact(n-1,dp);
    
}

int main(int argc, char const *argv[])
{
    int n; cin >> n;
    vector<int> dp(n+1,-1);
    cout << fact(n,dp) << "\n";
    vector<int>::iterator it;
    for(it = dp.begin() ; it < dp.end() ; it++)
        cout << *it  << " ";
    return 0;
}