#include<iostream>
#include<algorithm>
using namespace std;


void countSort(int a[] , int n){
    int max = *max_element(a, a + n);
    int min = *min_element(a,a+n);
    int range = max - min + 1;
    int count[range] = {0};
    int arr[n];

    for(int i = 0 ; i < n ; i++)
        count[a[i] - min]++;

    for(int i = 1 ; i < range ; i++)
        count[i] = count[i] + count[i-1];

    for(int i = n-1 ; i>=0 ; i--){
        arr[count[a[i] - min]-1]=a[i];
        count[a[i]-min]--;
    }

    for (int i = 0; i < n; i++){
        a[i] = arr[i];
        cout << a[i] << " "; 
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int A[n];

    for (int i = 0; i < n; i++)
        cin >> A[i];

    countSort(A,n);
}