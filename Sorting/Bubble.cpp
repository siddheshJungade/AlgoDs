#include<iostream>

using namespace std;

void swap(int *xp,int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 void bubbleSort(int a[], int n)
{
        if(n == 1)
            return;
        
        for(int i = 0 ; i < n - 1 ; i++){
            if(a[i] > a[i+1])
                swap(&a[i],&a[i+1]);
        }
        
        bubbleSort(a,n-1);
        // Your code here  
}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    int A[n],j,temp;

    for(int i = 0 ; i<n ; i++)
        cin>>A[i];

    // bouble sort

    for(int i = 0 ; i <= n-1 ; i++)
    {
        for(j = 0 ; j <= n-1-1 ; j++)
        {
            if(A[j]>A[j+1])
            swap( &A[j], &A[j+1]);

        }
    }

    for(int i = 0 ; i<n ; i++)
    {
        cout<<A[i]<<"\t";
    }

    return 0;
}
