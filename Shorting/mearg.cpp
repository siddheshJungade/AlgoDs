#include<iostream>
using namespace std;

int merge(int A[] , int l , int m ,int r)
{
    int i,j,k;
    int n1 =  l;
    int n2 = r;

    cout<<"merge short"<<endl;

}

void mergeSort(int A[],int l ,int r)
{
    if(l < r)
    {
        int m = (l + r)/2;

        mergeSort(A,l,m);
        mergeSort(A,m+1,r);

        merge(A,l,m,r);
    }

}
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    int A[n],j,temp,m;

    for(int i = 0 ; i<n ; i++)
    {
        cout<<"----------"<<i<<"------------"<<endl;
        cin>>A[i];
    }

    mergeSort(A , 0 , n-1);
    return 0;
}
