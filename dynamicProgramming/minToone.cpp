#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int minToOne(int n , int arr[]){

    if(n == 1)
        return 0;
    if(arr[n] != 0)
        return arr[n];
    
    int minThree = INT_MAX,minTow = INT_MAX,minOne = INT_MAX;
    if(n%3 == 0) minThree = minToOne(n/3,arr);
    if(n%2 == 0) minTow = minToOne(n/2,arr);
    
    minOne = minToOne(n-1,arr);

    int ans = min(min(minThree,minTow),minOne) + 1;

    return arr[n] = ans; 
}
int main(int argc, char const *argv[])
{
    int n ; cin >> n;
    int arr[n+1] = {0};
    cout << minToOne(n,arr);
    return 0;
}
