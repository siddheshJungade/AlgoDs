// binary Search using recursion approch

#include <iostream>
using namespace std;
int binarySearch(int *arr ,int i, int n,int found){
    if(n >= i){
        int mid = i (n - i)/2 ; // best method use
        // int mid =flour((i+n)/2): //bad method

        if (arr[mid] == found)
            return mid;
        else if(arr[mid] > found )
            return binarySearch(arr,i,mid-1,found);
        else
            return binarySearch(arr,mid+1,n,found);
    }
    cout << "No Element present";
    return -1; 
    
}

int main(int argc, char const *argv[])
{
    int n; cin >> n;
    int *a = new int(n);
    int found;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "Enter the element to find :" ;
    cin >> found;

    cout << "\nElement is found at index :" << binarySearch(a,0,n,found) << endl;
    return 0;
}