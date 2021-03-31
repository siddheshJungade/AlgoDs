#include<iostream>
#include<vector>
using namespace std;

// the tebulation method
void fact(int n){
    vector<int> dp(n+1);
    dp[0] = 1 ;
    for(int i = 1 ; i <= n ; i++){
        dp[i] = dp[i-1] * i;
        cout << dp[i] << " "; 
    }
}

int main(int argc, char const *argv[])
{
    int n; cin >> n;
    fact(n);
    return 0;
}
