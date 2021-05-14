#include<iostream>
#include<vector>
using namespace std;

int binarySearch(int arr[],int start,int end, int search){
    if(end < start) return -1;
    int mid = (end+start)/2;
    if(arr[mid] > search)
        return binarySearch(arr,start,mid-1,search);
    else if(arr[mid] < search)
        return binarySearch(arr,mid+1,end,search);
    else return mid;
}

int main(int argc, char const *argv[])
{
    int n ; cin >> n;
    int arr[n];
    for(int i = 0 ; i < n ; i++)
        cin >> arr[i];
    cout << "search :" ;
    int sc ; cin >> sc;
    cout << binarySearch(arr,0,n,sc);
    return 0;
}
