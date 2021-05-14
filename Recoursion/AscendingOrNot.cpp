#include<iostream>
#include<vector>
using namespace std;

int ascendingOrNot(int arr[] , int size){
    if(size == 1)
        return 1;
    if(arr[size-1] > arr[size])
        return 0;
    return ascendingOrNot(arr,size-1);
}

int main(int argc, char const *argv[])
{
    int n ; cin >> n;
    int arr[n];
    for(int i = 0 ; i < n ; i++)
        cin >> arr[i];
    
    cout << ascendingOrNot(arr,n-1);

    return 0;
}