#include<iostream>
#include<vector>
using namespace std;

int evenSum(vector<int> &arr , int size){
    if(size == 0)
        return 0;
    
    if(arr[size-1] % 2 == 0)
        return arr[size-1] + evenSum(arr,size-1);
    
    return evenSum(arr,size-1);
}

int main(int argc, char const *argv[])
{
    int n ; cin >> n;
    vector<int> arr(n);

    for(int i = 0 ; i < n ; i++)
        cin >> arr[i];
    
    cout << evenSum(arr,n);
    return 0;
}
