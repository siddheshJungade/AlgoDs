// binary Search using recursion approch

#include <iostream>
using namespace std;
int binarySearch(int *arr ,int i, int n,int found){
    while(i <= n){
        int mid = i+ ( n - i)/2;

        if(arr[mid] == found)
            return mid;
        else if(arr[mid] > found)
            i = mid +1;
        else
            n = mid-1;
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