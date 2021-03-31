#include<iostream>
#include<algorithm>
using namespace std;

// this is countSort function
void countSort(int a[],int n , int exp){
    int count[10] = {0};
    for(int i = 0 ; i < n ; i++)
        count[(a[i] / exp) % 10]++;
    for(int i = 1 ; i < 10 ; i++)
        count[i] += count[i-1];
    
    int output[n];
    for(int i = n - 1 ; i >= 0 ; i--)
        output[--count[(a[i]/exp) % 10]]=a[i];
    for(int i = 0 ; i < n ; i++)
        a[i] = output[i];
}

void radixSort(int a[],int n) {
    int max = *max_element(a,a+n);

    for(int exp = 1 ; max/exp > 0 ; exp *= 10)
        countSort(a,n,exp);
}
int main(int argc, char const *argv[])
{
    int n;cin >> n;
    int A[n];

    for (int i = 0; i < n; i++)
        cin >> A[i];

    radixSort(A,n);
    
    for (int i = 0; i < n; i++)
        cout <<"\t"<< A[i] <<"\t";
    return 0;
}
